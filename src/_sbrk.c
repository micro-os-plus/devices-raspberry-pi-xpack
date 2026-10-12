/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2022-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

// ----------------------------------------------------------------------------

/*
 * The `_sbrk()` implementation below is copied from the Raspberry Pi
 * Pico SDK (`src/rp2_common/pico_clib_interface/newlib_interface.c`),
 * reused here because this platform does not link the SDK's
 * `pico_clib_interface` (it provides its own µOS++ startup/runtime
 * instead). Apart from cosmetic formatting, the only change is that
 * `errno` is set to `ENOMEM` on failure (the SDK leaves that line
 * commented out), as the POSIX `sbrk()` contract requires and as the
 * µOS++ `startup` implementation does:
 *
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

// ----------------------------------------------------------------------------

#include "micro-os-plus/device.h"

#if __has_include("micro-os-plus/startup-defines.h")
#include "micro-os-plus/startup-defines.h"
#endif // __has_include("micro-os-plus/startup-defines.h")

#include <errno.h>

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_DEVICE_RASPBERRY_PI_SDK_SBRK_ENABLED)

// Both `_sbrk()` implementations are weak, so enabling both would not
// fail the link; one would be silently picked, possibly over the wrong
// heap region (`end`..`__StackLimit` from the SDK linker script here,
// `__heap_begin__`..`__heap_end__` from the µOS++ linker scripts there).
#if defined(MICRO_OS_PLUS_STARTUP_SBRK_ENABLED)
#error \
    "MICRO_OS_PLUS_DEVICE_RASPBERRY_PI_SDK_SBRK_ENABLED and MICRO_OS_PLUS_STARTUP_SBRK_ENABLED are mutually exclusive"
#endif // defined(MICRO_OS_PLUS_STARTUP_SBRK_ENABLED)

// ----------------------------------------------------------------------------

#define false 0

extern char __StackLimit; /* Set by linker.  */
extern char end; /* Set by linker.  */

void*
_sbrk (int incr);

/**
 * @brief Extend the heap (newlib `sbrk()` syscall stub).
 * @param [in] incr Number of bytes to add to the current heap break.
 * @return A pointer to the start of the newly allocated block, or
 *  `(void*) -1` with `errno` set to `ENOMEM` if the request cannot
 *  be satisfied.
 *
 * @details
 * Grows a heap tracked in a function-local `static` pointer, seeded
 * from `end` on the first call and bounded by `__StackLimit` (both
 * defined by the Pico SDK linker script). With
 * `PICO_USE_OPTIMISTIC_SBRK`, a request that does not fit is clipped
 * to the remaining space, and only a request made when the heap is
 * already full fails.
 *
 * Setting `errno` is the only functional difference from the SDK
 * original; without it, code that inspects `errno` after a failed
 * allocation (for example the libstdc++ out-of-memory tests) sees
 * a stale value.
 */
__attribute__ ((weak)) void*
_sbrk (int incr)
{
  static char* heap_end;
  char* prev_heap_end;

  if (heap_end == 0)
    heap_end = &end;

  prev_heap_end = heap_end;
  char* next_heap_end = heap_end + incr;

  if (__builtin_expect (next_heap_end > (&__StackLimit), false))
    {
#if defined(PICO_USE_OPTIMISTIC_SBRK) && PICO_USE_OPTIMISTIC_SBRK
      if (heap_end == &__StackLimit)
        {
          errno = ENOMEM; // Commented out in the SDK original.
          return (char*)-1;
        }
      next_heap_end = &__StackLimit;
#else
      errno = ENOMEM; // Not present in the SDK original.
      return (char*)-1;
#endif
    }

  heap_end = next_heap_end;
  return (void*)prev_heap_end;
}

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_DEVICE_RASPBERRY_PI_SDK_SBRK_ENABLED)

// ----------------------------------------------------------------------------

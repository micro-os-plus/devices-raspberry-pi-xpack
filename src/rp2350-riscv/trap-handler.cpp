/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

// ----------------------------------------------------------------------------

#include "micro-os-plus/device.h"
#include "micro-os-plus/rp2350-riscv/trap-handler.h"

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_DEVICES_RASPBERRY_PI_ENABLED) \
    && defined( \
        MICRO_OS_PLUS_DEVICES_RASPBERRY_PI_VECTORS_RP2350_RISCV_ENABLED)

// ----------------------------------------------------------------------------

namespace device
{
  namespace
  {
    // Direct-mode `mtvec` target: since this build never resumes the
    // interrupted context, it can be an ordinary function (no manual
    // register save/restore is needed, unlike a real trap-entry
    // routine); `aligned(4)` guarantees the low mode bits of `mtvec`
    // stay zero (Direct mode) even though `-march=...c` allows 2-byte
    // function alignment by default.
    [[noreturn]] void __attribute__ ((aligned (4)))
    trap_handler (void)
    {
      // Read the trap cause so it is visible to a debugger inspecting
      // this frame; this build does not decode it any further.
      [[maybe_unused]] riscv::architecture::register_t mcause
          = riscv::csr::mcause ();

      for (;;)
        {
          riscv::architecture::wfi ();
        }
    }
  } // namespace

  void
  install_trap_handler (void)
  {
    riscv::csr::mtvec (
        reinterpret_cast<riscv::architecture::register_t> (&trap_handler));
  }
} // namespace device

// ----------------------------------------------------------------------------

#endif /* defined(MICRO_OS_PLUS_DEVICES_RASPBERRY_PI_ENABLED) && \
          defined(MICRO_OS_PLUS_DEVICES_RASPBERRY_PI_VECTORS_RP2350_RISCV_ENABLED) */

// ----------------------------------------------------------------------------

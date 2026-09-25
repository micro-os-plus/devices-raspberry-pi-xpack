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

#include "micro-os-plus/device.h"

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_DEVICES_RASPBERRY_PI_ENABLED)

#if defined(MICRO_OS_PLUS_DEVICES_RASPBERRY_PI_RP2040__SUPPORT_ENABLED) \
    || defined(MICRO_OS_PLUS_DEVICES_RASPBERRY_PI_RP2350_ARM_SUPPORT_ENABLED)

// ----------------------------------------------------------------------------

// system_RP2040.h (pulled in via micro-os-plus/device.h, RP2040.h) declares
// SystemCoreClock/SystemInit/SystemCoreClockUpdate inside its own
// `#ifdef __cplusplus extern "C"` block, so the definitions below must be
// given matching C language linkage.
extern "C" uint32_t SystemCoreClock;
uint32_t SystemCoreClock;

extern "C" void
SystemInit (void)
{
  SystemCoreClockUpdate ();
}

extern "C" void
SystemCoreClockUpdate (void)
{
  SystemCoreClock = system_clock.clock_get_frequency_hz ();
}

// ----------------------------------------------------------------------------

#endif /* defined(MICRO_OS_PLUS_DEVICES_RASPBERRY_PI_RP2040__SUPPORT_ENABLED) || \
          defined(MICRO_OS_PLUS_DEVICES_RASPBERRY_PI_RP2350_ARM_SUPPORT_ENABLED)) */

#endif // defined(MICRO_OS_PLUS_DEVICES_RASPBERRY_PI_ENABLED)

// ----------------------------------------------------------------------------

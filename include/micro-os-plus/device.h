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

#ifndef MICRO_OS_PLUS_DEVICE_H_
#define MICRO_OS_PLUS_DEVICE_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)
#if !(__cplusplus >= 202002L || (defined(_MSVC_LANG) && _MSVC_LANG >= 202002L))
#error "C++20 or higher is required"
#endif
#endif // defined(__cplusplus)

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/device-defines.h")
#include "micro-os-plus/device-defines.h"
#endif // __has_include("micro-os-plus/device-defines.h")

// ----------------------------------------------------------------------------

#include "micro-os-plus/architecture.h"

#if !defined(__ASSEMBLY__)

#if defined(MICRO_OS_PLUS_DEVICES_RASPBERRY_PI_CORE_RP2040)

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__cplusplus)
#pragma GCC diagnostic ignored "-Wuseless-cast"
#else
#pragma GCC diagnostic ignored "-Wnested-externs"
#pragma GCC diagnostic ignored "-Wredundant-decls"
#endif // defined(__cplusplus)
#endif // defined(__GNUC__)

#include "RP2040.h"

#elif defined(MICRO_OS_PLUS_DEVICES_RASPBERRY_PI_CORE_RP2350_ARM)

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warith-conversion"
#if defined(__cplusplus)
#pragma GCC diagnostic ignored "-Wuseless-cast"
#else
#pragma GCC diagnostic ignored "-Wnested-externs"
#pragma GCC diagnostic ignored "-Wredundant-decls"
#pragma GCC diagnostic ignored "-Wold-style-definition"
#pragma GCC diagnostic ignored "-Wstrict-prototypes"
#endif // defined(__cplusplus)
#endif // defined(__GNUC__)

#include "RP2350.h"

#else

#error "Unsupported Raspberry Pi core"

#endif // defined(MICRO_OS_PLUS_DEVICES_RASPBERRY_PI_CORE_RPxxxx)

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

#include "micro-os-plus/devices-raspberry-pi/system-clock.h"

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

extern device::system_clock system_clock;

#endif // defined(__cplusplus)

#endif // !defined(__ASSEMBLY__)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_DEVICE_H_

// ----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# DO NOT EDIT! Automatically generated from template file: xcdl-package.json
#
# This file is part of the µOS++ project (https://micro-os-plus.github.io/).
# Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can be
# obtained from https://opensource.org/licenses/mit.
#
# -----------------------------------------------------------------------------

# This file is intended to be used by applications via:
#
# `add_subdirectory("xpacks/@micro-os-plus/devices-raspberry-pi")`
#
# This creates libraries that can be linked to a target with:
#
# ~~~
# target_link_libraries(your-target PUBLIC micro-os-plus::devices-raspberry-pi-micro-os-plus-devices-raspberry-pi-sdk-sbrk)
# target_link_libraries(your-target PUBLIC micro-os-plus::devices-raspberry-pi-micro-os-plus-devices-raspberry-pi-system-clock)
# target_link_libraries(your-target PUBLIC micro-os-plus::devices-raspberry-pi-vectors-rp2040)
# target_link_libraries(your-target PUBLIC micro-os-plus::devices-raspberry-pi-vectors-rp2350-arm)
# target_link_libraries(your-target PUBLIC micro-os-plus::devices-raspberry-pi-vectors-rp2350-riscv)
# target_link_libraries(your-target PUBLIC micro-os-plus::devices-raspberry-pi)
# ~~~

# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.20/
cmake_minimum_required (VERSION 3.20)
project (
  micro-os-plus-devices-raspberry-pi
  DESCRIPTION "A source code library with Raspberry Pi device components"
  LANGUAGES C CXX ASM
)

# To access the optional functions, include the
# `cmake/micro-os-plus-build-helper.cmake` file from the
# `@micro-os-plus/build-helper` package.

if (COMMAND xpack_get_package_name_and_version)
  xpack_get_package_name_and_version (
    "${CMAKE_CURRENT_SOURCE_DIR}/package.json"
  )
  message (VERBOSE
           "Processing xPack ${PACKAGE_JSON_NAME}@${PACKAGE_JSON_VERSION}..."
  )
endif ()

# -----------------------------------------------------------------------------

# Interface libraries are the main targets, which consumers (like embedded
# applications) link against. It defines the public API and properties of the
# library; sources are propagated to and compiled by each consumer.

# They are aliased using namespaced syntax (Project::Target). This is the
# canonical pattern for consumption via target_link_libraries(), whether the
# dependency is added via add_subdirectory(), FetchContent, or an installed
# package via find_package(). Using "::" lets CMake detect an invalid or
# misspelled target name at configure time, rather than silently passing it
# through to the linker as a plain string or flag. Note: alias targets are
# read-only; properties must be set on the underlying target, not on the alias
# itself.

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#interface-libraries
# Visibility keywords: PRIVATE applies to the target itself; INTERFACE passes
# properties up to targets that link against it; PUBLIC does both.
add_library (
  micro-os-plus-devices-raspberry-pi-micro-os-plus-devices-raspberry-pi-sdk-sbrk-interface
  INTERFACE
  EXCLUDE_FROM_ALL
)

target_sources (
  micro-os-plus-devices-raspberry-pi-micro-os-plus-devices-raspberry-pi-sdk-sbrk-interface
  INTERFACE "src/_sbrk.c"
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists (
    micro-os-plus-devices-raspberry-pi-micro-os-plus-devices-raspberry-pi-sdk-sbrk-interface
  )
endif ()

# -----------------------------------------------------------------------------
# Alias.

# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library (
  micro-os-plus::devices-raspberry-pi-micro-os-plus-devices-raspberry-pi-sdk-sbrk
  ALIAS
  micro-os-plus-devices-raspberry-pi-micro-os-plus-devices-raspberry-pi-sdk-sbrk-interface
)
message (
  VERBOSE
  "> micro-os-plus::devices-raspberry-pi-micro-os-plus-devices-raspberry-pi-sdk-sbrk -> micro-os-plus-devices-raspberry-pi-micro-os-plus-devices-raspberry-pi-sdk-sbrk-interface"
)

# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#interface-libraries
# Visibility keywords: PRIVATE applies to the target itself; INTERFACE passes
# properties up to targets that link against it; PUBLIC does both.
add_library (
  micro-os-plus-devices-raspberry-pi-micro-os-plus-devices-raspberry-pi-system-clock-interface
  INTERFACE
  EXCLUDE_FROM_ALL
)

target_sources (
  micro-os-plus-devices-raspberry-pi-micro-os-plus-devices-raspberry-pi-system-clock-interface
  INTERFACE "src/system-clock.cpp"
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists (
    micro-os-plus-devices-raspberry-pi-micro-os-plus-devices-raspberry-pi-system-clock-interface
  )
endif ()

# -----------------------------------------------------------------------------
# Alias.

# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library (
  micro-os-plus::devices-raspberry-pi-micro-os-plus-devices-raspberry-pi-system-clock
  ALIAS
  micro-os-plus-devices-raspberry-pi-micro-os-plus-devices-raspberry-pi-system-clock-interface
)
message (
  VERBOSE
  "> micro-os-plus::devices-raspberry-pi-micro-os-plus-devices-raspberry-pi-system-clock -> micro-os-plus-devices-raspberry-pi-micro-os-plus-devices-raspberry-pi-system-clock-interface"
)

# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#interface-libraries
# Visibility keywords: PRIVATE applies to the target itself; INTERFACE passes
# properties up to targets that link against it; PUBLIC does both.
add_library (
  micro-os-plus-devices-raspberry-pi-vectors-rp2040-interface INTERFACE
  EXCLUDE_FROM_ALL
)

target_include_directories (
  micro-os-plus-devices-raspberry-pi-vectors-rp2040-interface
  INTERFACE
    "${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2_common/cmsis/stub/CMSIS/Core/Include"
    "${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2_common/cmsis/stub/CMSIS/Device/RP2040/Include"
    "${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2040/hardware_regs/include"
)

target_sources (
  micro-os-plus-devices-raspberry-pi-vectors-rp2040-interface
  INTERFACE "src/rp2040/vectors-rp2040.c" "src/system-rp2xxx.cpp"
            "src/rp2040/bs2_default_padded_checksummed.S"
)

target_link_libraries (
  micro-os-plus-devices-raspberry-pi-vectors-rp2040-interface
  INTERFACE "micro-os-plus::device"
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists (
    micro-os-plus-devices-raspberry-pi-vectors-rp2040-interface
  )
endif ()

# -----------------------------------------------------------------------------
# Alias.

# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library (
  micro-os-plus::devices-raspberry-pi-vectors-rp2040 ALIAS
  micro-os-plus-devices-raspberry-pi-vectors-rp2040-interface
)
message (
  VERBOSE
  "> micro-os-plus::devices-raspberry-pi-vectors-rp2040 -> micro-os-plus-devices-raspberry-pi-vectors-rp2040-interface"
)

# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#interface-libraries
# Visibility keywords: PRIVATE applies to the target itself; INTERFACE passes
# properties up to targets that link against it; PUBLIC does both.
add_library (
  micro-os-plus-devices-raspberry-pi-vectors-rp2350-arm-interface INTERFACE
  EXCLUDE_FROM_ALL
)

target_include_directories (
  micro-os-plus-devices-raspberry-pi-vectors-rp2350-arm-interface
  INTERFACE
    "${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2_common/cmsis/stub/CMSIS/Core/Include"
    "${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2_common/cmsis/stub/CMSIS/Device/RP2350/Include"
    "${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/common/boot_picobin_headers/include"
    "${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2350/hardware_regs/include"
)

target_sources (
  micro-os-plus-devices-raspberry-pi-vectors-rp2350-arm-interface
  INTERFACE "src/rp2350-arm/vectors-rp2350.c" "src/system-rp2xxx.cpp"
            "src/rp2350-arm/embedded-block-rp2350-arm.c"
)

target_link_libraries (
  micro-os-plus-devices-raspberry-pi-vectors-rp2350-arm-interface
  INTERFACE "micro-os-plus::device"
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists (
    micro-os-plus-devices-raspberry-pi-vectors-rp2350-arm-interface
  )
endif ()

# -----------------------------------------------------------------------------
# Alias.

# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library (
  micro-os-plus::devices-raspberry-pi-vectors-rp2350-arm ALIAS
  micro-os-plus-devices-raspberry-pi-vectors-rp2350-arm-interface
)
message (
  VERBOSE
  "> micro-os-plus::devices-raspberry-pi-vectors-rp2350-arm -> micro-os-plus-devices-raspberry-pi-vectors-rp2350-arm-interface"
)

# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#interface-libraries
# Visibility keywords: PRIVATE applies to the target itself; INTERFACE passes
# properties up to targets that link against it; PUBLIC does both.
add_library (
  micro-os-plus-devices-raspberry-pi-vectors-rp2350-riscv-interface INTERFACE
  EXCLUDE_FROM_ALL
)

target_include_directories (
  micro-os-plus-devices-raspberry-pi-vectors-rp2350-riscv-interface
  INTERFACE
    "${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2350/hardware_regs/include"
    "${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/common/boot_picobin_headers/include"
    "${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2_common/pico_bootrom/include"
    "${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2_common/boot_bootrom_headers/include"
)

target_sources (
  micro-os-plus-devices-raspberry-pi-vectors-rp2350-riscv-interface
  INTERFACE "src/rp2350-riscv/debugger-entry-point.S"
            "src/rp2350-riscv/trap-handler.cpp"
            "src/rp2350-riscv/embedded-block-rp2350-riscv.c"
)

target_compile_definitions (
  micro-os-plus-devices-raspberry-pi-vectors-rp2350-riscv-interface
  INTERFACE "NO_PICO_PLATFORM"
)

target_link_libraries (
  micro-os-plus-devices-raspberry-pi-vectors-rp2350-riscv-interface
  INTERFACE "micro-os-plus::device"
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists (
    micro-os-plus-devices-raspberry-pi-vectors-rp2350-riscv-interface
  )
endif ()

# -----------------------------------------------------------------------------
# Alias.

# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library (
  micro-os-plus::devices-raspberry-pi-vectors-rp2350-riscv ALIAS
  micro-os-plus-devices-raspberry-pi-vectors-rp2350-riscv-interface
)
message (
  VERBOSE
  "> micro-os-plus::devices-raspberry-pi-vectors-rp2350-riscv -> micro-os-plus-devices-raspberry-pi-vectors-rp2350-riscv-interface"
)

# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#interface-libraries
# Visibility keywords: PRIVATE applies to the target itself; INTERFACE passes
# properties up to targets that link against it; PUBLIC does both.
add_library (
  micro-os-plus-devices-raspberry-pi-interface INTERFACE EXCLUDE_FROM_ALL
)

target_include_directories (
  micro-os-plus-devices-raspberry-pi-interface INTERFACE "include"
)

target_sources (
  micro-os-plus-devices-raspberry-pi-interface
  INTERFACE "src/system-rp2xxx.cpp"
)

target_link_libraries (
  micro-os-plus-devices-raspberry-pi-interface
  INTERFACE
    "micro-os-plus::diag-trace"
    "micro-os-plus::architecture"
    "micro-os-plus::devices-raspberry-pi-micro-os-plus-devices-raspberry-pi-sdk-sbrk"
    "micro-os-plus::devices-raspberry-pi-micro-os-plus-devices-raspberry-pi-system-clock"
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists (micro-os-plus-devices-raspberry-pi-interface)
endif ()

# -----------------------------------------------------------------------------
# Alias.

# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library (
  micro-os-plus::devices-raspberry-pi ALIAS
  micro-os-plus-devices-raspberry-pi-interface
)
message (
  VERBOSE
  "> micro-os-plus::devices-raspberry-pi -> micro-os-plus-devices-raspberry-pi-interface"
)

add_library (
  micro-os-plus::device ALIAS micro-os-plus-devices-raspberry-pi-interface
)
message (
  VERBOSE
  "> micro-os-plus::device -> micro-os-plus-devices-raspberry-pi-interface"
)

# -----------------------------------------------------------------------------

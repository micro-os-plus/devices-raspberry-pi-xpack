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
# target_link_libraries(your-target PUBLIC micro-os-plus::devices-raspberry-pi)
# target_link_libraries(your-target PUBLIC micro-os-plus::devices-raspberry-pi-vectors-rp2040)
# target_link_libraries(your-target PUBLIC micro-os-plus::devices-raspberry-pi-vectors-rp2350)
# target_link_libraries(your-target PUBLIC micro-os-plus::devices-raspberry-pi-sdk-sbrk)
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
  micro-os-plus-devices-raspberry-pi-interface INTERFACE EXCLUDE_FROM_ALL
)

target_include_directories (
  micro-os-plus-devices-raspberry-pi-interface INTERFACE "include"
)

target_link_libraries (
  micro-os-plus-devices-raspberry-pi-interface
  INTERFACE "micro-os-plus::diag-trace" "micro-os-plus::architecture"
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

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#interface-libraries
# Visibility keywords: PRIVATE applies to the target itself; INTERFACE passes
# properties up to targets that link against it; PUBLIC does both.
add_library (
  micro-os-plus-devices-raspberry-pi-vectors-rp2040-interface INTERFACE
  EXCLUDE_FROM_ALL
)

target_sources (
  micro-os-plus-devices-raspberry-pi-vectors-rp2040-interface
  INTERFACE "rp2040/src/vectors-rp2040.c"
)

target_link_libraries (
  micro-os-plus-devices-raspberry-pi-vectors-rp2040-interface
  INTERFACE "micro-os-plus::architecture"
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
  micro-os-plus-devices-raspberry-pi-vectors-rp2350-interface INTERFACE
  EXCLUDE_FROM_ALL
)

target_sources (
  micro-os-plus-devices-raspberry-pi-vectors-rp2350-interface
  INTERFACE "rp2350/src/vectors-rp2350.c"
)

target_link_libraries (
  micro-os-plus-devices-raspberry-pi-vectors-rp2350-interface
  INTERFACE "micro-os-plus::architecture"
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists (
    micro-os-plus-devices-raspberry-pi-vectors-rp2350-interface
  )
endif ()

# -----------------------------------------------------------------------------
# Alias.

# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library (
  micro-os-plus::devices-raspberry-pi-vectors-rp2350 ALIAS
  micro-os-plus-devices-raspberry-pi-vectors-rp2350-interface
)
message (
  VERBOSE
  "> micro-os-plus::devices-raspberry-pi-vectors-rp2350 -> micro-os-plus-devices-raspberry-pi-vectors-rp2350-interface"
)

# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#interface-libraries
# Visibility keywords: PRIVATE applies to the target itself; INTERFACE passes
# properties up to targets that link against it; PUBLIC does both.
add_library (
  micro-os-plus-devices-raspberry-pi-sdk-sbrk-interface INTERFACE
  EXCLUDE_FROM_ALL
)

target_sources (
  micro-os-plus-devices-raspberry-pi-sdk-sbrk-interface INTERFACE "src/_sbrk.c"
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists (
    micro-os-plus-devices-raspberry-pi-sdk-sbrk-interface
  )
endif ()

# -----------------------------------------------------------------------------
# Alias.

# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library (
  micro-os-plus::devices-raspberry-pi-sdk-sbrk ALIAS
  micro-os-plus-devices-raspberry-pi-sdk-sbrk-interface
)
message (
  VERBOSE
  "> micro-os-plus::devices-raspberry-pi-sdk-sbrk -> micro-os-plus-devices-raspberry-pi-sdk-sbrk-interface"
)

# -----------------------------------------------------------------------------

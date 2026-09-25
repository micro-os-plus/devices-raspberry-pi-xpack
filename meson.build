# -----------------------------------------------------------------------------
# DO NOT EDIT! Automatically generated from template file:
# xcdl-package.json
#
# This file is part of the µOS++ project (https://micro-os-plus.github.io/).
# Copyright (c) 2022-2026 Liviu Ionescu. All rights reserved.
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
# `subdir('xpacks/@micro-os-plus/devices-raspberry-pi')`
#
# This creates dependencies that can be linked to a target with:
#
# `dependencies: [micro_os_plus_devices_raspberry_pi_micro_os_plus_devices_raspberry_pi_sdk_sbrk_dependency],`
# `dependencies: [micro_os_plus_devices_raspberry_pi_micro_os_plus_devices_raspberry_pi_system_clock_dependency],`
# `dependencies: [micro_os_plus_devices_raspberry_pi_vectors_rp2040_dependency],`
# `dependencies: [micro_os_plus_devices_raspberry_pi_vectors_rp2350_arm_dependency],`
# `dependencies: [micro_os_plus_devices_raspberry_pi_vectors_rp2350_riscv_dependency],`
# `dependencies: [micro_os_plus_devices_raspberry_pi_dependency],`

# Note: the Meson configuration is provided only as a proof of concept;
# for production it might need some refinements.

# -----------------------------------------------------------------------------

# A source code library with Raspberry Pi device components.
message('Processing xPack @micro-os-plus/devices-raspberry-pi...')

# -----------------------------------------------------------------------------

# Meson's DSL does not provide introspection methods on dependency objects
# to retrieve their properties after creation. The `_local_*` variables
# therefore serve a dual purpose: populating the dependency object and
# iterating over its components for the `message()` calls at the end.

_local_compile_args = [] # Common C/C++ args.
_local_compile_c_args = [] # C only args.
_local_compile_cpp_args = [] # C++ only args.
_local_include_directories = []
_local_sources = []
_local_compile_definitions = []
_local_dependencies = []
_local_link_args = []
_local_link_with = []

_local_sources += [
  'src/_sbrk.c',
]

# https://mesonbuild.com/Reference-manual_functions.html#declare_dependency
micro_os_plus_devices_raspberry_pi_micro_os_plus_devices_raspberry_pi_sdk_sbrk_dependency = declare_dependency(
  include_directories: include_directories(_local_include_directories),
  compile_args: _local_compile_args,
  sources: files(_local_sources),
  dependencies: _local_dependencies,
  link_args: _local_link_args,
  link_with: _local_link_with,
)

# Meson dependencies cannot differentiate between C and C++ compile args;
# they are therefore exposed as separate variables alongside the dependency.
micro_os_plus_devices_raspberry_pi_micro_os_plus_devices_raspberry_pi_sdk_sbrk_dependency_compile_c_args = _local_compile_c_args
micro_os_plus_devices_raspberry_pi_micro_os_plus_devices_raspberry_pi_sdk_sbrk_dependency_compile_cpp_args = _local_compile_cpp_args

foreach name : _local_include_directories
  message('+ -I ' + name)
endforeach
foreach name : _local_sources + _local_compile_definitions + _local_compile_args + _local_compile_c_args + _local_compile_cpp_args
  message('+ ' + name)
endforeach
message('> micro_os_plus_devices_raspberry_pi_micro_os_plus_devices_raspberry_pi_sdk_sbrk_dependency')

# -----------------------------------------------------------------------------

_local_compile_args = [] # Common C/C++ args.
_local_compile_c_args = [] # C only args.
_local_compile_cpp_args = [] # C++ only args.
_local_include_directories = []
_local_sources = []
_local_compile_definitions = []
_local_dependencies = []
_local_link_args = []
_local_link_with = []

_local_sources += [
  'src/system-clock.cpp',
]

# https://mesonbuild.com/Reference-manual_functions.html#declare_dependency
micro_os_plus_devices_raspberry_pi_micro_os_plus_devices_raspberry_pi_system_clock_dependency = declare_dependency(
  include_directories: include_directories(_local_include_directories),
  compile_args: _local_compile_args,
  sources: files(_local_sources),
  dependencies: _local_dependencies,
  link_args: _local_link_args,
  link_with: _local_link_with,
)

# Meson dependencies cannot differentiate between C and C++ compile args;
# they are therefore exposed as separate variables alongside the dependency.
micro_os_plus_devices_raspberry_pi_micro_os_plus_devices_raspberry_pi_system_clock_dependency_compile_c_args = _local_compile_c_args
micro_os_plus_devices_raspberry_pi_micro_os_plus_devices_raspberry_pi_system_clock_dependency_compile_cpp_args = _local_compile_cpp_args

foreach name : _local_include_directories
  message('+ -I ' + name)
endforeach
foreach name : _local_sources + _local_compile_definitions + _local_compile_args + _local_compile_c_args + _local_compile_cpp_args
  message('+ ' + name)
endforeach
message('> micro_os_plus_devices_raspberry_pi_micro_os_plus_devices_raspberry_pi_system_clock_dependency')

# -----------------------------------------------------------------------------

_local_compile_args = [] # Common C/C++ args.
_local_compile_c_args = [] # C only args.
_local_compile_cpp_args = [] # C++ only args.
_local_include_directories = []
_local_sources = []
_local_compile_definitions = []
_local_dependencies = []
_local_link_args = []
_local_link_with = []

_local_include_directories += [
  '${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2_common/cmsis/stub/CMSIS/Core/Include',
  '${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2_common/cmsis/stub/CMSIS/Device/RP2040/Include',
  '${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2040/hardware_regs/include',
]

_local_sources += [
  'src/rp2040/vectors-rp2040.c',
  'src/system-rp2xxx.cpp',
  'src/rp2040/bs2_default_padded_checksummed.S',
]

_local_dependencies += [
  micro_os_plus_device_dependency,
]

# https://mesonbuild.com/Reference-manual_functions.html#declare_dependency
micro_os_plus_devices_raspberry_pi_vectors_rp2040_dependency = declare_dependency(
  include_directories: include_directories(_local_include_directories),
  compile_args: _local_compile_args,
  sources: files(_local_sources),
  dependencies: _local_dependencies,
  link_args: _local_link_args,
  link_with: _local_link_with,
)

# Meson dependencies cannot differentiate between C and C++ compile args;
# they are therefore exposed as separate variables alongside the dependency.
micro_os_plus_devices_raspberry_pi_vectors_rp2040_dependency_compile_c_args = _local_compile_c_args
micro_os_plus_devices_raspberry_pi_vectors_rp2040_dependency_compile_cpp_args = _local_compile_cpp_args

foreach name : _local_include_directories
  message('+ -I ' + name)
endforeach
foreach name : _local_sources + _local_compile_definitions + _local_compile_args + _local_compile_c_args + _local_compile_cpp_args
  message('+ ' + name)
endforeach
message('> micro_os_plus_devices_raspberry_pi_vectors_rp2040_dependency')

# -----------------------------------------------------------------------------

_local_compile_args = [] # Common C/C++ args.
_local_compile_c_args = [] # C only args.
_local_compile_cpp_args = [] # C++ only args.
_local_include_directories = []
_local_sources = []
_local_compile_definitions = []
_local_dependencies = []
_local_link_args = []
_local_link_with = []

_local_include_directories += [
  '${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2_common/cmsis/stub/CMSIS/Core/Include',
  '${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2_common/cmsis/stub/CMSIS/Device/RP2350/Include',
  '${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/common/boot_picobin_headers/include',
  '${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2350/hardware_regs/include',
]

_local_sources += [
  'src/rp2350-arm/vectors-rp2350.c',
  'src/system-rp2xxx.cpp',
  'src/rp2350-arm/embedded-block-rp2350-arm.c',
]

_local_dependencies += [
  micro_os_plus_device_dependency,
]

# https://mesonbuild.com/Reference-manual_functions.html#declare_dependency
micro_os_plus_devices_raspberry_pi_vectors_rp2350_arm_dependency = declare_dependency(
  include_directories: include_directories(_local_include_directories),
  compile_args: _local_compile_args,
  sources: files(_local_sources),
  dependencies: _local_dependencies,
  link_args: _local_link_args,
  link_with: _local_link_with,
)

# Meson dependencies cannot differentiate between C and C++ compile args;
# they are therefore exposed as separate variables alongside the dependency.
micro_os_plus_devices_raspberry_pi_vectors_rp2350_arm_dependency_compile_c_args = _local_compile_c_args
micro_os_plus_devices_raspberry_pi_vectors_rp2350_arm_dependency_compile_cpp_args = _local_compile_cpp_args

foreach name : _local_include_directories
  message('+ -I ' + name)
endforeach
foreach name : _local_sources + _local_compile_definitions + _local_compile_args + _local_compile_c_args + _local_compile_cpp_args
  message('+ ' + name)
endforeach
message('> micro_os_plus_devices_raspberry_pi_vectors_rp2350_arm_dependency')

# -----------------------------------------------------------------------------

_local_compile_args = [] # Common C/C++ args.
_local_compile_c_args = [] # C only args.
_local_compile_cpp_args = [] # C++ only args.
_local_include_directories = []
_local_sources = []
_local_compile_definitions = []
_local_dependencies = []
_local_link_args = []
_local_link_with = []

_local_include_directories += [
  '${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2350/hardware_regs/include',
  '${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/common/boot_picobin_headers/include',
  '${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2_common/pico_bootrom/include',
  '${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2_common/boot_bootrom_headers/include',
]

_local_sources += [
  'src/rp2350-riscv/debugger-entry-point.S',
  'src/rp2350-riscv/trap-handler.cpp',
  'src/rp2350-riscv/embedded-block-rp2350-riscv.c',
]
_local_compile_args += [
  '-DNO_PICO_PLATFORM',
]

_local_dependencies += [
  micro_os_plus_device_dependency,
]

# https://mesonbuild.com/Reference-manual_functions.html#declare_dependency
micro_os_plus_devices_raspberry_pi_vectors_rp2350_riscv_dependency = declare_dependency(
  include_directories: include_directories(_local_include_directories),
  compile_args: _local_compile_args,
  sources: files(_local_sources),
  dependencies: _local_dependencies,
  link_args: _local_link_args,
  link_with: _local_link_with,
)

# Meson dependencies cannot differentiate between C and C++ compile args;
# they are therefore exposed as separate variables alongside the dependency.
micro_os_plus_devices_raspberry_pi_vectors_rp2350_riscv_dependency_compile_c_args = _local_compile_c_args
micro_os_plus_devices_raspberry_pi_vectors_rp2350_riscv_dependency_compile_cpp_args = _local_compile_cpp_args

foreach name : _local_include_directories
  message('+ -I ' + name)
endforeach
foreach name : _local_sources + _local_compile_definitions + _local_compile_args + _local_compile_c_args + _local_compile_cpp_args
  message('+ ' + name)
endforeach
message('> micro_os_plus_devices_raspberry_pi_vectors_rp2350_riscv_dependency')

# -----------------------------------------------------------------------------

_local_compile_args = [] # Common C/C++ args.
_local_compile_c_args = [] # C only args.
_local_compile_cpp_args = [] # C++ only args.
_local_include_directories = []
_local_sources = []
_local_compile_definitions = []
_local_dependencies = []
_local_link_args = []
_local_link_with = []

_local_include_directories += [
  'include',
]

_local_sources += [
  'src/system-rp2xxx.cpp',
]

_local_dependencies += [
  micro_os_plus_diag_trace_dependency,
  micro_os_plus_architecture_dependency,
  micro_os_plus_devices_raspberry_pi_micro_os_plus_devices_raspberry_pi_sdk_sbrk_dependency,
  micro_os_plus_devices_raspberry_pi_micro_os_plus_devices_raspberry_pi_system_clock_dependency,
]

# https://mesonbuild.com/Reference-manual_functions.html#declare_dependency
micro_os_plus_devices_raspberry_pi_dependency = declare_dependency(
  include_directories: include_directories(_local_include_directories),
  compile_args: _local_compile_args,
  sources: files(_local_sources),
  dependencies: _local_dependencies,
  link_args: _local_link_args,
  link_with: _local_link_with,
)

# Meson dependencies cannot differentiate between C and C++ compile args;
# they are therefore exposed as separate variables alongside the dependency.
micro_os_plus_devices_raspberry_pi_dependency_compile_c_args = _local_compile_c_args
micro_os_plus_devices_raspberry_pi_dependency_compile_cpp_args = _local_compile_cpp_args

foreach name : _local_include_directories
  message('+ -I ' + name)
endforeach
foreach name : _local_sources + _local_compile_definitions + _local_compile_args + _local_compile_c_args + _local_compile_cpp_args
  message('+ ' + name)
endforeach
message('> micro_os_plus_devices_raspberry_pi_dependency')

# -----------------------------------------------------------------------------
# Alias.

micro_os_plus_device_dependency = declare_dependency(
  include_directories: include_directories(_local_include_directories),
  compile_args: _local_compile_args,
  sources: files(_local_sources),
  dependencies: _local_dependencies,
  link_args: _local_link_args,
  link_with: _local_link_with,
)

# Meson dependencies cannot differentiate between C and C++ compile args;
# they are therefore exposed as separate variables alongside the dependency.
micro_os_plus_device_dependency_compile_c_args = _local_compile_c_args
micro_os_plus_device_dependency_compile_cpp_args = _local_compile_cpp_args

foreach name : _local_include_directories
  message('+ -I ' + name)
endforeach
foreach name : _local_sources + _local_compile_definitions + _local_compile_args + _local_compile_c_args + _local_compile_cpp_args
  message('+ ' + name)
endforeach
message('> micro_os_plus_device_dependency')

# -----------------------------------------------------------------------------

# Project Facts for the Skills — Raspberry Pi devices

This file is owned by the project; it was created once from the
template `npm-packages-helper/templates/first-time/.github/skills/project-liquid.md`, and it is never regenerated.

The skills in `.github/skills/` read the facts of the project from
`.github/skills/project-defaults.md` (generated, with the defaults for
the organisation and the project) and from this file. Add below, under
the same heading, only what differs from the default: the text of a
heading extends the default, or overrides it where the two disagree (a
heading that says "None", or "Not applicable", removes the default). A
heading that is absent keeps the default. The headings are: Tests,
Probes, Generated Files, Files Not to Commit, Review Documents, Breaking Changes, Documentation Updates, and Paths
(see `.github/skills/README.md`).

A skill folder may also have its own `project.md`, for the rules of that
skill only; it takes precedence over this file.

## Probes

The code of this project is specific to the Raspberry Pi devices (RP2040
and RP2350), so a probe cannot run on the host; the native recipe of the
defaults does not apply, and the cross compiler is used as follows:

```sh
# RP2040:
arm-none-eabi-g++ -std=c++20 -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft \
  -Wall -Wextra -Wpedantic -Iinclude -c <file> -o <scratch>/probe/<name>.o
# RP2350, Arm:
arm-none-eabi-g++ -std=c++20 -mcpu=cortex-m33 -mthumb -mfloat-abi=softfp \
  -Wall -Wextra -Wpedantic -Iinclude -c <file> -o <scratch>/probe/<name>.o
# RP2350, RISC-V:
riscv-none-elf-g++ -std=c++20 -march=rv32imac_zicsr -mabi=ilp32 \
  -Wall -Wextra -Wpedantic -Iinclude -c <file> -o <scratch>/probe/<name>.o
```

## Generated Files

- The top-level `CMakeLists.txt` and `meson.build` are generated from
  `xcdl-package.json` (in this project, without the `c` of `.jsonc`)
  with `xpm run xcdl-export`; they are never edited by hand.
- The files with a `DO NOT EDIT!` header are generated from templates
  (named in the header) and are fixed in their templates.

# extras

These small programs were built from the Pico SDK examples. Use them
whenever you need to restore a Pico board to a known working application.

| File | Board |
| ---- | ----- |
| `blink-pico.uf2` | Pico (RP2040) |
| `blink-pico-2-arm.uf2` | Pico 2 (RP2350), Arm cores |
| `blink-pico-2-riscv.uf2` | Pico 2 (RP2350), RISC-V cores |

To flash one of them, put the board in boot mode:

1. disconnect the board from USB
2. press and hold the **BOOTSEL** button
3. reconnect the board to USB, then release the button
4. the board shows up as a USB mass storage device; copy the `.uf2` file to it

The board reboots automatically and runs the new program; the on-board
LED should start blinking.

> [!NOTE]
> On the Pico 2, flashing one of these binaries is also the way to
> switch the board between the Arm and RISC-V architectures.

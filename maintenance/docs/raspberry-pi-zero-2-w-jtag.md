# Raspberry Pi Zero 2 W - JTAG

The JTAG pins are available in Alt4 and Alt5 configurations.

It is recommended to use Alt4.

## The Alt4 GPIO configuration for JTAG

- GPIO22/TRST
- GPIO23/RTCK
- GPIO24/TDO
- GPIO25/TCK
- GPIO26/TDI
- GPIO27/TMS

- GPIO14/TXD0
- GPIO15/RXD0

## The Raspberry Pi header in Alt4 mode

- https://www.raspberrypi.com/documentation/computers/raspberry-pi.html#gpio

| Function | GPIO | Pin | Pin | GPIO | Function |
|---|---|---|---|---|---|
| 3V3 | | [1] | 2 | | 5V |
| SDA1 | GPIO2 | 3 | 4 | | 5V |
| SCL1 | GPIO3 | 5 | 6 | | GND |
| GPCLK0 | GPIO4 | 7 | 8 | GPIO14 | **TXD** |
| GND | | 9 | 10 | | **RXD** |
| | GPIO17 | 11 | 12 | GPIO18 | PWM0/PCM_CLK |
| **TMS** | GPIO27 | 13 | 14 | | GND |
| **TRST** | GPIO22 | 15 | 16 | GPIO23 | **RTCK** |
| 3V3 | | 17 | 18 | GPIO24 | **TDO** |
| SPI0 MOSI | GPIO10 | 19 | 20 | | GND |
| SPI0 MISO | GPIO9 | 21 | 22 | GPIO25 | **TCK** |
| SPI0 SCLK | GPIO11 | 23 | 24 | GPIO8 | SPI0 CE0 |
| GND | | 25 | 26 | GPIO7 | SPI0 CE1 |
| ID_SD | GPIO0 | 27 | 28 | GPIO1 | ID_SC |
| | GPIO5 | 29 | 30 | | GND |
| | GPIO6 | 31 | 32 | GPIO12 | PWM0 |
| PWM1 | GPIO13 | 33 | 34 | | GND |
| PCM_FS/SPI1 MISO | GPIO19 | 35 | 36 | GPIO16 | SPI1 CE2 |
| **TDI** | GPIO26 | 37 | 38 | GPIO20 | PCM_DIN/SPI1 MOSI |
| GND | | 39 | 40 | GPIO21 | PCM_DOUT/SPI1 SCLK |

## JTAG signals

The JTAG signals on the Raspberry Pi Zero 2 W (ALT4 function) are:

| Signal | GPIO | Direction | Purpose |
| --- | --- | --- | --- |
| **TCK** (Test Clock) | GPIO25 | probe → target | Clocks the TAP state machine and shifts data in and out. The probe drives it; its frequency is set with `adapter speed` in OpenOCD. |
| **TMS** (Test Mode Select) | GPIO27 | probe → target | Sampled on the rising edge of TCK. Its value moves the TAP controller through its state machine (Reset, Idle, Shift-DR, Shift-IR, and so on). |
| **TDI** (Test Data In) | GPIO26 | probe → target | Serial data shifted into the selected instruction or data register. |
| **TDO** (Test Data Out) | GPIO24 | target → probe | Serial data shifted out of the selected register. The target changes it on the falling edge of TCK. |
| **TRST** (Test Reset) | GPIO22 | probe → target | Optional, active-low. Resets only the TAP controller, not the processor. Without it, the TAP can be reset by holding TMS high for five TCK cycles. |
| **RTCK** (Return Test Clock) | GPIO23 | target → probe | Optional. TCK echoed back for adaptive clocking, as described below. |

### RTCK

**RTCK (Return Test Clock)** is an optional JTAG signal that the target drives back to the debug probe. It echoes TCK after the target has synchronised it to its own internal clock.

**Why it exists.** Some ARM cores synchronise the incoming TCK to their core clock before using it. Examples are the ARM7TDMI-S, ARM9E-S, ARM11, and some Cortex-A implementations. This is typical of synthesisable cores. On such a core, if the probe drives TCK faster than about 1/6 to 1/8 of the core clock, the TAP controller misses edges and communication fails. The core clock can also change at run time, for example when PLLs are configured or in low-power modes. That makes it unsafe to pick one fixed TCK frequency.

**How it works (adaptive clocking).** With RTCK, the probe does not run TCK at a fixed rate. It waits for each TCK edge to come back on RTCK before it generates the next edge. The JTAG clock therefore follows whatever the target can handle at that moment. This is useful when the core starts on a slow clock and speeds up later, or when it drops into a low-power state.

### Practical aspects

- **Probe support.** Only some probes support RTCK, for example J-Link, ARM-USB-OCD/Olimex, and FT2232-based probes with suitable wiring. In OpenOCD it is enabled with `adapter speed 0` (older versions: `jtag_rclk <fallback_khz>`).
- **Optional.** If the target does not provide RTCK, or you do not connect it, use a fixed, conservative TCK frequency instead. OpenOCD's `adapter speed` sets this.
- **Connector pin.** On the ARM 20-pin JTAG connector, RTCK is pin 11. Cortex-M parts using the 10-pin SWD/JTAG connector do not use it. Cortex-M synchronises TCK differently, so RTCK is irrelevant there.

**Relevance to the Raspberry Pi Zero 2 W.** The BCM2710A1 has four Cortex-A53 cores and exposes `ARM_RTCK` on **GPIO23 (ALT4)**.

Most published OpenOCD setups for BCM2710-class boards leave RTCK unconnected and use a fixed `adapter speed` (typically a few MHz or less). The Cortex-A53 debug logic is accessed through a CoreSight JTAG-DP, which runs in its own TCK clock domain, so the classic reason for adaptive clocking does not apply. It is not documented what the BCM2710A1 drives on `ARM_RTCK`; if adaptive clocking is to be used, verify on hardware that RTCK actually follows TCK before relying on it.

### Other connections

Connections that are not GPIO pins:

- **GND** is required. It gives the probe and the board a common reference.
- **VTref** (target voltage reference) goes to a 3.3 V pin. The probe uses it to sense the I/O voltage and set its level shifters. It does not power the board. Used by J-Link.
- **SRST** (system reset, nSRST) is optional and resets the whole system. The Pi does not route a reset line to the GPIO header. The closest equivalent is the `RUN` pad (on the Zero 2 W, labelled on the board). Most setups leave SRST unconnected and use `reset_config trst_only` or `none` in OpenOCD.

## Connecting a J-Link (20-pin connector)

The J-Link uses the standard ARM 20-pin JTAG connector (2 × 10, 2.54 mm pitch).

- https://www.segger.com/products/debug-probes/j-link/technology/interface-description/

### Corresponding Pins

There are two 10 wire ribon cables, with standard colour coding.

| J&#x2011;Link pin |  Colour  | J&#x2011;Link signal | Pi Zero header pin | Pi Zero signal | Notes |
| --- | --- | --- | --- | --- | --- |
| 1 | brown 1 | VTref | 1 | 3V3 | Reference only; required for the J-Link level shifters. |
| 2 | red 1 | NC | — | — | Not connected. |
| 3 | orange&nbsp;1 | nTRST | 15 | GPIO22 (TRST) | Optional but recommended; GPIO22 has a default pull-down, which may hold the TAP in reset if left unconnected. |
| 4 | yellow&nbsp;I | GND | ? (*) | GND | |
| 5 | green 1 | TDI | 37 | GPIO26 (TDI) | |
| 6 | blue 1 | GND | ? (*) | GND | |
| 7 | violet 1 | TMS | 13 | GPIO27 (TMS) | |
| 8 | grey 1 | GND | ? (*) | GND | |
| 9 | white 1 | TCK | 22 | GPIO25 (TCK) | |
| 10 | black 1 | GND | ? (*) | GND | |
| 11 | brown 2 | RTCK | 16 | GPIO23 (RTCK) | Optional; needed only for adaptive clocking. |
| 12 | red 2 | GND | ? (*) | GND | |
| 13 | orange&nbsp;2 | TDO | 18 | GPIO24 (TDO) | |
| 14 | yellow&nbsp;2 | GND | ? (*) | GND | |
| 15 | green 2 | RESET (nSRST) | — | — | Not connected; the Pi has no reset line on the header. |
| 16 | blue 2 | GND | ? (*) | GND | |
| 17 | violet 2 | DBGRQ | — | — | Not connected. |
| 18 | grey 2 | GND | ? (*) | GND | |
| 19 | white 2 | 5V-Supply | — | — | **Do not connect.** It is a 5 V output from the J-Link. |
| 20 | black 2 | GND | ? (*) | GND |  |

(*) - GND any of 39, 6, 9, 14, 20, 25, 30, 34 - At least one is required; more are better for signal integrity.

The GPIO pins use 3.3 V levels and are not 5 V tolerant. Connect VTref to 3V3, never to 5V.

With individual jumper wires, keep them short (ideally under 15 cm) and connect several ground wires. A ground close to each signal pin is convenient: pin 14 (near TMS and TRST), pin 20 (near TCK and TDO), and pin 39 (near TDI).

### `config.txt`

The JTAG pins are available only after they are switched to ALT4. On the Pi this is usually done with `enable_jtag_gpio=1` in `config.txt`, which the firmware applies at boot.

```txt
enable_jtag_gpio=1
```

According to the Raspberry Pi documentation, `enable_jtag_gpio=1` selects ALT4 for GPIO22 to GPIO27 and also sets up some internal SoC connections required by the Arm JTAG interface.

The generic form, found in older guides, only changes the pin multiplexing:

```txt
gpio=22-27=a4
```

It is redundant when `enable_jtag_gpio=1` is present and is not required.

## Connecting a JTAGprobe

**JTAGprobe** is a Raspberry Pi Pico running a fork of open source `debugprobe`:

- https://github.com/lonehog/JTAGprobe
- https://github.com/raspberrypi/debugprobe

### Corresponding JTAGprobe Pins

| Pico pin | RP2040 GPIO | JTAG Signal | Pi Zero header pin | Pi Zero signal | Notes |
| --- | --- | --- | --- | --- | --- |
| 18 |  | GND | ? (*) | GND | |
| 19 | GP14 | TMS/SWDIO | 13 | GPIO27 (TMS) | |
| 20 | GP15 | nTRST | 15 | GPIO22 (TRST) | Optional but recommended; GPIO22 has a default pull-down, which may hold the TAP in reset if left unconnected. |
| | | | | | |
| 21 | GP16 | nRESET | — | — | Not connected; the Pi has no reset line on the header. |
| 22 | GP17 | NC | — | — | |
| 23 |  | GND | ? (*) | GND | |
| 24 | GP18 | TDI | 37 | GPIO26 (TDI) | |
| 25 | GP19 | TCK/SWCLK | 22 | GPIO25 (TCK) | |
| 26 | GP20 | NC | — | — | |
| 27 | GP21 | TDO | 18 | GPIO24 (TDO) | |
| 28 |  | GND | ? (*) | GND |  |

(*) - GND any of 39, 6, 9, 14, 20, 25, 30, 34 - At least one is required; more are better for signal integrity.

## Connecting a JTAGprobe SMP PIO

**JTAGprobe SMP PIO** is a fork that significantly improves speed and simplifies the cabling:

- https://github.com/dan-maio/JTAGprobe_smp_pio_std
- https://github.com/raspberrypi/debugprobe

The current JTAG probe is based on v4.1.

### Corresponding JTAGprobe SMP PIO Pins

| Pico Pin | Colour | RP2040 GPIO | JTAG Signal | Pi Zero pin | Pi Zero GPIO | JTAG Signal | Hardware Role / Direction | Description |
| :---: | :---: | :---: | :--- | :---: | :---: | :--- | :--- | :--- |
| 1 | brown | GP0 | nTRST | 15 | GP22 | TRST | Output (Probe → Target, SIO GPIO) | JTAG Test Reset (optional) |
| 2 | red | GP1 | nRESET | - | - | - | Open-drain (Target Reset, SIO GPIO) | System Reset |
| 3 | orange | GND | GND | 9 | - | GND | Ground Reference | Common Ground |
| 4 | yellow | GP2 | SWCLK / TCK | 22 | GP25 | TCK | Output (Probe → Target, PIO Side-Set 0) | SWD Clock / JTAG Test Clock |
| 5 | green | GP3 | SWDIO / TMS | 13 | GP27 | TMS | Bi-directional (SWD: SIO GPIO; JTAG: PIO SET 0) | SWD Data I/O / JTAG Test Mode Select |
| 6 | blue | GP4 | UART_TXD | 10 | GP15 | UART RXD | Output (Probe → Target, `uart1`) | to the target's UART RX |
| 7 | violet | GP5 | UART_RXD | 8 | GP14 | UART TXD | Input (Probe ← Target, `uart1`) | from the target's UART TX |
| 8 | grey | GND | GND | 14 | - | GND | Ground Reference | Common Ground |
| 9 | white | GP6 | TDI | 37 | GP26 | TDI | Output (Probe → Target, PIO OUT 0) | JTAG Test Data In |
| 10 | black | GP7 | TDO | 18 | GP24 | TDO | Input (Probe ← Target, PIO IN 0) | JTAG Test Data Out |

-/-/-
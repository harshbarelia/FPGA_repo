# UART Peripheral in SystemVerilog

This project implements a compact UART peripheral in SystemVerilog with a transmitter, receiver, CSR-based register interface, top-level integration, loopback verification, and a small Python MMIO helper for software-side register access. Structuring UART projects as TX, RX, top-level integration, testbench, and software-visible register blocks is a common and practical pattern for FPGA bring-up and verification.[1][2][3]

## Project contents

- `rtl/uart_tx.sv` — UART transmitter with `tx_start`, `tx_data`, `busy`, and `tx_done`.
- `rtl/uart_rx.sv` — UART receiver with `rx_data`, `rx_valid`, and `framing_error`.
- `rtl/uart_csr.sv` — CSR block that exposes UART control and status through memory-mapped registers.
- `rtl/uart_top_csr.sv` — integrated UART peripheral combining CSR, TX, and RX.
- `tb/tb_uart_csr.sv` — loopback-oriented self-checking CSR testbench.
- `sw/uart_csr.py` — Python helper for memory-mapped register access and simple software control flow.

## Features

- Parameterized clock frequency and baud rate.
- Separate TX and RX modules for modular debugging and reuse.
- CSR layer for register-based control.
- Loopback verification from software-visible transmit path to receive path.
- Sticky receiver event flags for `RX_VALID` and `FRAMING_ERROR`, with live `TX_BUSY` status.
- Python helper mirroring the CSR register map for software integration.

## Register map

| Offset | Register | Access | Description |
|--------|----------|--------|-------------|
| `0x00` | `CTRL`   | R/W    | Bit 0 = `TX_START`, Bit 1 = `RX_ENABLE` |
| `0x04` | `STATUS` | R/W1C  | Bit 0 = `TX_BUSY`, Bit 1 = `RX_VALID`, Bit 2 = `FRAMING_ERR` |
| `0x08` | `TX_DATA`| R/W    | Bits `[7:0]` contain the transmit byte |
| `0x0C` | `RX_DATA`| RO     | Bits `[7:0]` contain the last received byte |

This register split follows the usual control/status/data separation used in memory-mapped peripherals.

## Directory layout


FPGA_repo/
├── rtl/
│   ├── uart_tx.sv
│   ├── uart_rx.sv
│   ├── uart_csr.sv
│   └── uart_top_csr.sv
├── tb/
│   └── tb_uart_csr.sv
└── sw/
    └── uart_csr.py


## Simulation flow

Lint the integrated design:


verilator --lint-only --timing -sv \
  --top-module tb_uart_csr \
  rtl/uart_tx.sv \
  rtl/uart_rx.sv \
  rtl/uart_csr.sv \
  rtl/uart_top_csr.sv \
  tb/tb_uart_csr.sv


Build the simulation binary:


/usr/bin/verilator --trace --binary --timing -sv \
  --top-module tb_uart_csr \
  rtl/uart_tx.sv \
  rtl/uart_rx.sv \
  rtl/uart_csr.sv \
  rtl/uart_top_csr.sv \
  tb/tb_uart_csr.sv`

Run the testbench:


./obj_dir/Vtb_uart_csr


Verilator’s `--binary` flow creates an executable under `obj_dir` named after the selected top module, which is why the simulation binary here is `Vtb_uart_csr`.[9][10]

## Expected test result

A passing run should print:


CSR loopback PASSED: got 0xa5


The loopback testbench writes `TX_DATA`, pulses `TX_START` through `CTRL`, waits for `TX_BUSY` to clear, waits for `RX_VALID` to assert, then reads back `RX_DATA` and checks the received byte. This is a standard self-checking register-driven verification style for UART integration.[2][11]

## Python helper usage

The Python helper mirrors the CSR register map and wraps basic register operations behind convenience methods such as `send_byte()`, `enable_rx()`, `read_rx_byte()`, and `clear_status()`. MMIO-style Python wrappers like this are commonly used to access memory-mapped hardware registers from software environments.[4][5]

Example:


from uart_csr import UARTCSR, MockMMIO

mmio = MockMMIO()
uart = UARTCSR(mmio)

uart.enable_rx(True)
uart.send_byte(0xA5)


`MockMMIO` is only a placeholder backend for software structure testing; a real deployment would replace it with a board- or platform-specific MMIO implementation.[12][13]

## Design notes

- `TX_BUSY` is a live status signal and should reflect the transmitter state directly.
- `RX_VALID` and `FRAMING_ERR` are sticky event flags and are cleared with write-one-to-clear behavior.
- The CSR layer is intentionally simple so the same control-plane approach can scale to larger FPGA blocks later.


## Next improvements

Natural next steps are FIFO buffering, stronger verification coverage, hardware bring-up on board, and eventually reusing the same CSR/software structure for more advanced FPGA peripherals.[14]

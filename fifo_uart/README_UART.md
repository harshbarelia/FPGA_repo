# UART in SystemVerilog

A compact UART project in SystemVerilog with separate transmitter, receiver, top-level integration, and loopback-oriented testbenches. The project structure follows the common pattern of splitting UART into TX, RX, and top/testbench blocks for simulation-driven verification.[1][2]

## Modules

- `rtl/uart_tx.sv` — UART transmitter with `tx_start`, `tx_data`, `busy`, and `tx_done`.
- `rtl/uart_rx.sv` — UART receiver with `rx_data`, `rx_valid`, and `framing_error`.
- `rtl/uart_top.sv` — top-level wrapper that instantiates TX and RX together.
- `tb/tb_uart_tx.sv` — standalone TX testbench.
- `tb/tb_uart_rx.sv` — standalone RX testbench.
- `tb/tb_uart_top.sv` — top-level loopback testbench connecting TX output back to RX input for end-to-end verification.

## Features

- Parameterized clock frequency and baud rate.
- Separate TX and RX RTL for modular debugging and reuse.
- Loopback testbench for end-to-end byte transfer validation.
- Framing error output on the receiver side for invalid stop-bit detection.

## Directory layout


FPGA_repo/
├── rtl/
│   ├── uart_tx.sv
│   ├── uart_rx.sv
│   └── uart_top.sv
└── tb/
    ├── tb_uart_tx.sv
    ├── tb_uart_rx.sv
    └── tb_uart_top.sv


## Lint and simulation

Lint the integrated design:


verilator --lint-only --timing -sv \
  --top-module tb_uart_top \
  rtl/uart_tx.sv \
  rtl/uart_rx.sv \
  rtl/uart_top.sv \
  tb/tb_uart_top.sv


Build the simulation binary:


/usr/bin/verilator --trace --binary --timing -sv \
  --top-module tb_uart_top \
  rtl/uart_tx.sv \
  rtl/uart_rx.sv \
  rtl/uart_top.sv \
  tb/tb_uart_top.sv


Run the simulation:


./obj_dir/Vtb_uart_top


Open the waveform:


gtkwave tb_uart_top.vcd


Verilator’s `--binary` flow generates an executable in `obj_dir` named after the selected top module, which is why the testbench binary is `Vtb_uart_top` here.[7][8]

## Expected behavior

In the loopback testbench, `tx_serial` should idle high, drive a low start bit, transmit data LSB first, and finish with a high stop bit. On the receive side, `rx_valid` should pulse when a full byte is received, `rx_data` should match the transmitted byte, and `framing_error` should remain low for valid frames.[9][2]

## Example test intent

The integrated testbench can verify:

- A single-byte loopback such as `8'hA5`.
- A second byte such as `8'h3C`.
- Correct `rx_valid` pulsing.
- No framing error for valid stop bits.[

## Next improvements

Useful next extensions for this UART block are FIFO buffering, stronger constrained or self-checking verification, and board-level bring-up. UART repositories commonly grow by adding FIFO integration and broader test infrastructure after basic TX/RX/top validation is complete.[10][11]

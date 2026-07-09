# FPGA_repo

This repository contains a small FPGA/SystemVerilog learning project focused on FIFO design and verification.

## Modules
- `rtl/reset_sync.sv` : Reset synchronizer with asynchronous assert and synchronous deassert.
- `rtl/sync_fifo.sv` : Synchronous FIFO.
- `rtl/async_fifo.sv` : Asynchronous FIFO using Gray-coded pointers.

## Verification
- `tb/tb_sync_fifo.sv` : Queue-based synchronous FIFO testbench.
- `tb/tb_async_fifo.sv` : Queue-based asynchronous FIFO testbench.
- `assert/assert_sync_fifo.sv` : Assertions for synchronous FIFO.
- `assert/assert_async_fifo.sv` : Assertions for asynchronous FIFO.
- `assert/bind_fifo_assertions.sv` : Bind file for assertion attachment.

## Project goal
Learn RTL design, CDC basics, FIFO flags, assertions, and scoreboard-style verification.

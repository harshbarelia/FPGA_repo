# FPGA Repository

This repository contains two FPGA/SystemVerilog projects:

## 1. [FIFO UART](fifo_uart/)
A project focused on FIFO design (synchronous/asynchronous), Clock Domain Crossing (CDC), Baud rate generation, and UART communication with control-status registers (CSR).
- Code, documentation, and verification testbenches are organized under the `fifo_uart/` directory.

## 2. [HFT Market Data Pipeline](fpga_market_data_pipeline_repo_latest_patched/fpga_market_data_pipeline_repo/)
An ultra-low latency HFT market data processing pipeline that decodes Nasdaq ITCH messages, maintains order book state/BBO calculation, and streams packed events to the host via AXI4-Stream.
- Located inside the `fpga_market_data_pipeline_repo_latest_patched/fpga_market_data_pipeline_repo/` directory.

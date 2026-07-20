# ⚡ High-Performance SystemVerilog & FPGA Designs

A curated collection of production-grade SystemVerilog hardware IP cores, PCIe DMA controllers, FPGA streaming data pipelines, and UART serial communication engines.

---

## 📁 Repository Projects

| Project | Description | Target Interfaces | Key Verification |
|---|---|---|---|
| 🚀 [**PCIe DMA Engine**](./pcie_dma_engine) | Complete Scatter-Gather PCIe DMA Engine for AXI4-Lite hard IP endpoints. Includes descriptor ring fetcher, H2C/C2H engines, mutex arbiter, and MSI-X interrupts. | AXI4-Lite, PCIe BAR0, MSI-X | Verified in Verilator (100% Data Integrity) |
| 🚀 [**PCIe Scatter-Gather DMA Engine**](./pcie-sg-dma-engine) | Scatter-Gather PCIe DMA Engine module layout. | AXI4-Lite, PCIe BAR0, MSI-X | Verified in Verilator |
| 📊 [**FPGA Market Data Pipeline**](./fpga_market_data_pipeline_repo_latest_patched) | Low-latency order book and market data parsing pipeline for high-frequency trading (HFT) applications. | AXI4-Stream, Ethernet MAC | Verified with SystemVerilog TB |
| 🔌 [**FIFO UART Controller**](./fifo_uart) | Asynchronous FIFO-buffered UART transmitter and receiver module with baud rate generator. | UART RX/TX, FIFO | RTL Verified |

---

## 🛠️ Verification & Toolchain Support

- **Simulators**: Verilator 5.x+, Icarus Verilog (`iverilog`), ModelSim / QuestaSim.
- **Synthesis Toolchains**: Xilinx Vivado, Intel Quartus Prime, Lattice Radiant.
- **Languages**: SystemVerilog (IEEE 1800-2017), C++ Verilator testbenches.

---

## 📜 License
Licensed under MIT. Open for hardware community contributions and commercial/research usage.

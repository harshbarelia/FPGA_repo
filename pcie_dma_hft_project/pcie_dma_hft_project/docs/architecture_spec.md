# Production Architecture & Microarchitecture Specification
## PCIe Scatter-Gather DMA Engine & Low-Latency HFT Feed Handler

---

## 1. System Overview
This project implements a hardware-accelerated, sub-microsecond market data ingest engine. Designed for ultra-low latency High-Frequency Trading (HFT) platforms, the pipeline captures raw 10G/25G Ethernet MAC frames, performs hardware IPv4/UDP protocol filtering, tags each frame with a nanosecond-accurate hardware SFD timestamp, and streams parsed market data into host CPU RAM via a high-performance PCIe Scatter-Gather DMA controller over standard AXI4 Master interface.

```
+------------------+     +-------------------+     +------------------+     +-------------------+
|  10G Ethernet    | --> |  Ethernet IPv4/   | --> |  Scatter-Gather  | --> | PCIe Gen3/Gen4    | --> Host RAM
|  MAC RX (156MHz) |     |  UDP Parser       |     |  DMA Engine      |     | AXI4 Master (300M)|
+------------------+     +-------------------+     +------------------+     +-------------------+
                                   |                         |
                                   v                         v
                         Hardware Timestamp         Descriptor Ring Buffer
                         Nanosecond Tagger          Gray-Code CDC FIFO
```

---

## 2. Microarchitecture Details

### 2.1 Ethernet & UDP Parser (`eth_udp_parser.sv`)
- **Protocol Compliance**: Decodes Ethernet II, IPv4 (Header Version 4, IHL 5), and UDP (Protocol `0x11`).
- **Hardware Timestamping**: Captures a 64-bit free-running nanosecond timestamp precisely at the Start-of-Frame Delimiter (SFD) of the first AXI-Stream beat.
- **Port Filtering**: Dynamic destination UDP port filtering configured via BAR0 CSR. Unmatched ports or corrupt EtherType frames are dropped without consuming PCIe DMA bandwidth.

### 2.2 Scatter-Gather DMA Engine (`sg_dma_engine.sv`)
- **AXI4 Master Interface**: Full standard AXI4 compliance (`AWADDR`, `AWLEN`, `AWSIZE`, `AWBURST`, `WDATA`, `WSTRB`, `WLAST`, `BRESP`).
- **4KB Page Boundary Splitting**: Automatically detects and splits AXI write bursts crossing 4KB memory page boundaries to prevent PCIe system bus faults.
- **Burst Optimization**: Calculates optimal AXI `AWLEN` based on descriptor length and 512-bit (64-byte) datapath width.

### 2.3 Descriptor Ring Buffer (`descriptor_ring_buffer.sv`)
- **Producer-Consumer Model**: Host CPU pushes 128-bit descriptors (`{addr[63:0], len[31:0], ctrl[31:0]}`) into ring buffer via BAR0 MMIO.
- **CDC Pointer Protection**: Extra wrap-bit Gray-code pointer arithmetic prevents pointer overrun/underrun during asynchronous clock domain crossings between Ethernet RX clock and PCIe user clock.

---

## 3. Register Map (BAR0 CSR)

| Offset | Register Name      | Access | Description |
|:------:|:------------------:|:------:|:----------------------------------------------------|
| `0x00` | `CSR_CONTROL`      | R/W    | Bit 0: DMA Enable, Bit 1: Soft Reset |
| `0x04` | `CSR_STATUS`       | R/O    | Bit 0: DMA Busy, Bit 1: Interrupt Pending |
| `0x08` | `CSR_COMPLETED`    | R/O    | Total completed DMA transfer counter |
| `0x10` | `CSR_LAST_RX_TS`   | R/O    | 64-bit nanosecond timestamp of last packet arrival |
| `0x18` | `CSR_LAST_DONE_TS` | R/O    | 64-bit nanosecond timestamp of last DMA completion |

---

## 4. Verification Framework

### 4.1 Verilator C++ Simulation Environment
- High-speed simulation in `sim/verilator/`.
- C++ host AXI memory responder & Ethernet frame generator (`sim_main.cpp`).
- Output waveform trace dump (`sim_trace.vcd` / `.fst`).

### 4.2 SystemVerilog UVM 1.2 Environment
- End-to-end scoreboard comparing streaming UDP payload bytes against memory-mapped destination memory.
- Functional coverage (`dma_coverage.sv`) measuring packet byte lengths (64B to 9000B), alignment, and ring occupancy.
- Bound SystemVerilog Assertions (`sva_assertions.sv`) checking no-overrun/underrun properties.

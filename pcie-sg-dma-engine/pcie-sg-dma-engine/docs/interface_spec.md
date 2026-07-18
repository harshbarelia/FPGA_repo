# Interface Specification

## Descriptor Format (32 bytes, host-resident ring)

| Bits | Field | Description |
|---|---|---|
| [63:0] | src_addr | Source buffer physical address (H2C read source) |
| [127:64] | dst_addr | Destination buffer physical address (C2H write dest) |
| [159:128] | length | Transfer length in bytes, max 0x0400_0000 (64MB) |
| [160] | dir | 0 = H2C, 1 = C2H |
| [161] | reserved | |
| [162] | irq_en | Fire MSI-X on completion of this descriptor |
| [255:163] | reserved | Zero-fill |

## BAR0 Register Map (AXI4-Lite, word-addressed)

| Offset | Register | R/W | Description |
|---|---|---|---|
| 0x00 | DESC_RING_BASE_LO | RW | Descriptor ring base address, bits [31:0] |
| 0x04 | DESC_RING_BASE_HI | RW | Descriptor ring base address, bits [63:32] |
| 0x08 | INSERT_PTR | RW | Software writes new insert pointer value here |
| 0x0C | EXTRACT_PTR | RO | Hardware-maintained extract pointer, poll for progress |
| 0x10 | WB_INTR_TIMEOUT | RW | MSI-X coalescing timeout, in core_clk cycles (default 256) |
| 0x1000+ | MSI-X Table | RW | 16 bytes per vector: addr_lo, addr_hi, msg_data, vector_ctrl |

**Note:** this register map has NOT been cross-checked against a real PCIe
config space BAR size requirement (must be power-of-2 sized, minimum 4KB
typically). Verify BAR sizing against your PCIe hard IP's configuration
wizard before taping this out on real hardware.

## MSI-X Vector Table Entry Layout (per PCIe MSI-X capability spec)

| Offset | Field |
|---|---|
| +0x0 | Message Address Low |
| +0x4 | Message Address High |
| +0x8 | Message Data |
| +0xC | Vector Control (bit0 = mask) |

## Clock Domains

| Signal Group | Domain | Crossing Method |
|---|---|---|
| Descriptor engine, AXI-Lite regs | core_clk | N/A |
| PCIe hard IP TX/RX AXI-Stream | pcie_clk | via async_fifo.sv (axi4_stream_bridge.sv) |
| MSI-X fire pulse (if pcie_clk differs) | cross-domain | pulse_sync.sv (not yet wired in top -- TODO) |

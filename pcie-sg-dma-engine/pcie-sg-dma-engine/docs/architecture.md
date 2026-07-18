# Architecture

## Block Diagram

```
                         core_clk domain                     |  pcie_clk domain
                                                             |
 [SW/CPU] --AXI4-Lite--> [axi4_mm_bridge] --regs--> [desc_ring_mgr]  |
                                                        |            |
                                                    [desc_fetch] --FSM--+
                                                   /            \      |
                                          [c2h_engine]      [h2c_engine]
                                          (Multi-beat)      (Elastic FIFO)
                                               \                  /
                                           [axi4_stream_bridge] (async_fifo CDC)
                                                \                /
                                               [TLP req arbiter] (Priority RR)
                                                        |
                                                [tlp_generator] ----> PCIe hard IP TX AXIS
                                                [tlp_parser]    <---- PCIe hard IP RX AXIS
                                                        |
                                             [desc_completion] --> [msix_ctrl] --> [msix_table] --> MSI-X TLP
```

---

## TLP Flow

**Descriptor fetch (Memory Read):** `desc_fetch` issues a read request via `tlp_generator` targeting the host-resident descriptor ring at `reg_desc_ring_base + extract_ptr*32`. The completion TLP is caught by `tlp_parser` and matched back by tag.

**C2H (Memory Write):** `c2h_engine` consumes the user stream, segments it into MPS-sized chunks, and issues Memory Write TLPs via the `tlp_req_arbiter` to the `tlp_generator`. It streams multiple beats directly to the generator per TLP, optimizing PCIe payload utilization.

**H2C (Memory Read + Completion):** `h2c_engine` issues Memory Read requests for the descriptor's `src_addr`. `tlp_parser` catches the incoming completion TLP payloads and pushes them into the H2C engine's internal 32-entry elastic FIFO. The FIFO absorbs burst data and handles backpressure from the user interface (`m_axis_tready` low) without dropping PCIe packets.

**Writeback (Memory Write):** `desc_completion` issues a small Memory Write TLP to a host-visible completion status word once a transfer finishes.

**MSI-X (Memory Write):** `msix_table` issues the MSI-X message as a Memory Write TLP to the address/data pair configured by the OS in the vector table, triggered by `msix_ctrl`'s coalescing logic.

---

## Descriptor Ring Layout

32-byte descriptors, ring depth 128 (configurable via `RING_DEPTH` param), contiguous in host memory starting at `reg_desc_ring_base`. See `interface_spec.md` for the exact bit layout.

---

## Integration Details

- **TLP Arbiter (`tlp_req_arbiter.sv`):** Dynamically allocates the shared `tlp_generator` resource. Priority is statically given to descriptor prefetching (`desc_fetch`) to prevent pipeline starvation, while data streams (`c2h_engine`, `h2c_engine`) and interrupts/status writes share the remaining bandwidth via round-robin arbitration. Grants are locked for the duration of a multi-beat TLP transaction to prevent inter-packet interleaving.
- **Clock Domain Crossing (CDC):** Bridges the `core_clk` (control and registers) and `pcie_clk` (PCIe link interface) domains. High-speed TX/RX streams are routed through standard asynchronous FIFOs (`async_fifo.sv`), while level register states are double-flopped for synchronization.

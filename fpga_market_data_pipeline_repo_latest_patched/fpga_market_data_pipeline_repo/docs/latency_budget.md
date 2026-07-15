# Latency Budget

This document defines the target per-stage latency budget for the v1
pipeline and states clearly which numbers are design targets versus
measured results. No synthesis or hardware timing run has been performed
yet (tracked in `docs/roadmap.md`); all figures below are architectural
targets based on pipeline depth, not silicon-verified numbers.

## Pipeline stages and cycle budget (target)

| Stage | Module | Pipeline depth | Notes |
|---|---|---|---|
| Message classify/extract/assemble | `market_message_decoder.sv` | 3 cycles | Fixed 3-stage pipeline: CLASSIFY -> EXTRACT -> ASSEMBLE |
| Symbol lookup | `symbol_table.sv` | 1 cycle | Registered read, aligned to decoder's stage2->stage3 boundary |
| Order book update | `order_book_core.sv` | 1 cycle | Single-cycle read-modify-write per event in v1 (no multi-cycle RMW pipelining yet) |
| Event packing | `event_packer.sv` | 1 cycle | Single-beat pack, registered output |
| DMA bridge (nominal, FIFO not full) | `dma_bridge.sv` | 1 cycle | FIFO push-to-pop latency when host is ready; up to `FIFO_DEPTH` cycles of added latency if host stalls |

**Total nominal decoder-to-DMA-output latency (target): 6 clock cycles**,
assuming no backpressure at any stage and no FIFO occupancy in
`dma_bridge`. At a representative 250 MHz core clock, this corresponds to
approximately 24 ns core-pipeline latency, exclusive of any front-end
Ethernet/UDP parsing latency (not yet implemented) and exclusive of
PCIe/host-side DMA transfer latency (board-specific, not modeled here).

## What is NOT included in this budget

- Physical-layer / MAC latency for receiving the Ethernet frame.
- `eth_ipv4_udp_parser` / `udp_payload_framer` latency (not yet implemented;
  see `docs/roadmap.md`).
- Host-side DMA engine latency (XDMA descriptor processing, PCIe
  transaction layer, driver interrupt/poll latency) — this is entirely
  board- and driver-dependent and out of scope for the FPGA-side budget.
- Backpressure scenarios: if `m_event_ready`, `s_book_event_ready`, or
  `dma_tready` deassert, latency increases by the stall duration. The
  pipeline is designed to never drop data under backpressure (verified in
  `tb_decoder.sv` T6 and `tb_dma_bridge.sv` T2), but this means the budget
  above is a best-case, not a worst-case or average-case figure.

## Verification of the budget claim

The cycle counts above are derived directly from the register stage counts
in each module (one `always_ff` boundary = one cycle of added latency), not
from a simulation waveform measurement. The next step to convert this from
an architectural claim to a verified number is to add cycle-counting
logic to `tb_int_pipeline.sv` that timestamps message injection at
`s_msg_valid` and event emission at `dma_tvalid`, and report the measured
delta. This is called out explicitly here rather than presented as
already-measured, per the project's stated goal of avoiding overstated
claims in verification collateral.

## Throughput considerations (not yet characterized)

This document currently addresses only per-message latency, not sustained
throughput (messages/second under back-to-back injection with no gaps).
Throughput characterization requires burst-injection stress testing (see
`docs/roadmap.md` item 4: randomized/stress verification) and is deferred
until that test infrastructure exists.

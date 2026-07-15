# Roadmap

This document tracks the current state of the v1 pipeline, known gaps, and
the ordered plan for extending the project beyond v1.

## Current status (v1)

| Block | File | Status |
|---|---|---|
| Shared types/constants | `rtl/pkg/hft_pkg.sv` | Done |
| Big-endian extraction helpers | `rtl/common/be_extract.sv` | Done |
| ITCH 5.0 decoder (R/A/F/E/X/D/U/P) | `rtl/decoder/market_message_decoder.sv` | Done, unit-tested |
| Symbol table | `rtl/book/symbol_table.sv` | Done, unit-tested via decoder integration |
| Order book core | `rtl/book/order_book_core.sv` | Done, unit-tested + integration-tested |
| Event packer | `rtl/event_packer.sv` | Done, unit-tested |
| DMA bridge (transport-agnostic) | `rtl/dma/dma_bridge.sv` | Done, unit-tested |
| Full-path integration test | `tb/int/tb_int_pipeline.sv` | Done |
| Golden model (Python) | `scripts/decode_ref/order_book_model.py` | Done, covers order book lifecycle |

## Resolved gaps

- **Stock Directory ('R') to symbol_table wiring**: originally the decoder
  emitted `EV_NOP` for `R` messages without driving any write path, forcing
  the integration testbench to manually bootstrap the symbol table. This is
  now closed: the decoder exposes `sym_wr_en` / `sym_wr_stock_locate` /
  `sym_wr_stock8`, driven directly from stage 2 when a valid, length-correct
  `R` message is decoded. `tb_int_pipeline.sv` now drives a real
  `MSG_R_DIRECTORY` vector through the decoder instead of writing the table
  directly.

## Known gaps / not yet implemented

- **Front-end framing** (`eth_ipv4_udp_parser`, `udp_payload_framer`) is
  still at the architecture/spec stage only. The current integration test
  starts at the decoder input (`s_msg_data`/`s_msg_len`), not from raw
  Ethernet/UDP bytes. This is the next block to formalize and implement.
- **Hash collision handling** in `order_book_core.sv`: `order_hash` and
  `level_hash` are simple XOR/truncation functions with no collision
  resolution (no chaining, no open addressing). For the small vector counts
  used in test sequences this does not manifest, but it is a real
  correctness risk at scale and must be addressed before claiming
  production-grade capacity.
- **Best-bid/best-ask recomputation on level exhaustion**: when the current
  best level's aggregate quantity drops to zero via `EV_EXEC`/`EV_CANCEL`/
  `EV_DELETE`, the core does not yet re-scan for the next-best price; it
  only zeroes the quantity at the current best price. A full recompute pass
  (or a secondary best-price cache) is needed for strict BBO correctness
  under liquidity removal at the top of book.
- **PCIe/XDMA-specific integration**: `dma_bridge.sv` is deliberately
  transport-agnostic. Wiring to a specific board (e.g. Xilinx XDMA IP or a
  Lattice PCIe core) is a separate, hardware-specific follow-on task.
- **Randomized / stress verification**: current verification is fully
  directed (hand-picked event sequences). A randomized event generator
  cross-checked against `order_book_model.py` over thousands of cycles is
  needed to catch corner cases directed tests miss.
- **Synthesis / timing closure**: no synthesis run has been performed yet;
  all correctness claims are behavioral-simulation-only at this stage.

## Planned order of work

1. Fix best-price recomputation on level exhaustion in `order_book_core.sv`.
2. Add explicit collision handling (or document capacity bounds precisely)
   for `order_hash`/`level_hash`.
3. Implement `eth_ipv4_udp_parser.sv` and `udp_payload_framer.sv`, and
   extend the integration test to start from raw Ethernet frames.
4. Build a randomized event generator + scoreboard against the Python
   golden model for stress verification.
5. Run a first synthesis pass (Yosys/Vivado/Lattice toolchain, per target
   board) and record utilization/timing in `docs/latency_budget.md`.
6. Board-specific DMA integration (XDMA or equivalent).

# Generated Repo Guide

This folder contains the reconstructed FPGA market-data pipeline demo.
Use this file as the one-page orientation before uploading to GitHub.

## File map

### Shared RTL
- `rtl/pkg/hft_pkg.sv` — shared enums, packed structs, constants.
- `rtl/common/be_extract.sv` — big-endian field extraction helpers.
- `rtl/decoder/market_message_decoder.sv` — ITCH message classifier/extractor.
- `rtl/book/symbol_table.sv` — stock locate to symbol_id mapping.
- `rtl/book/order_book_core.sv` — stateful order book engine.
- `rtl/event_packer.sv` — packs book events into AXI-Stream beats.
- `rtl/dma/dma_bridge.sv` — FIFO bridge to host-facing DMA stream.
- `rtl/parser/eth_ipv4_udp_parser.sv` — raw Ethernet/IPv4/UDP parser.
- `rtl/parser/udp_payload_framer.sv` — message framing adapter.

### Testbenches
- `tb/unit/tb_decoder.sv`
- `tb/unit/tb_order_book.sv`
- `tb/unit/tb_event_packer.sv`
- `tb/unit/tb_dma_bridge.sv`
- `tb/unit/tb_eth_ipv4_udp_parser.sv`
- `tb/unit/tb_udp_payload_framer.sv`
- `tb/int/tb_int_pipeline.sv`

### Vectors and reference model
- `tb/vectors/itch_vectors.svh`
- `tb/vectors/itch_vectors_seq.svh`
- `scripts/decode_ref/order_book_model.py`

### Docs
- `docs/protocol_subset.md`
- `docs/order_book_core_spec.md`
- `docs/front_end_parser_plan.md`
- `docs/roadmap.md`
- `docs/latency_budget.md`

## How to present it on GitHub

1. Keep the directory structure exactly as above.
2. Add this `index.md` at the repo root so visitors can find the key files fast.
3. Commit the docs first, then RTL, then testbenches, then vectors.
4. In your README, lead with the architecture diagram and the latency budget.

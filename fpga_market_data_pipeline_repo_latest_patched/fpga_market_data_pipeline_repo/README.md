# FPGA Market Data Pipeline

Reconstructed FPGA market-data pipeline demo:
- Raw Ethernet/IPv4/UDP front-end parser
- ITCH 5.0 message decoder
- Symbol table
- Stateful order book core (with best-price recompute on liquidity removal)
- Event packer and DMA bridge
- Directed unit and full-path integration testbenches
- Python golden model for order-book validation

Start with `index.md` for the file map, then read:
- `docs/protocol_subset.md`
- `docs/roadmap.md`
- `docs/latency_budget.md`
- `docs/front_end_parser_plan.md`

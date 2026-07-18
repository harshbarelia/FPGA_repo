# Test Plan

## Status Legend
- [x] Implemented and passing in simulation
- [~] Implemented, not yet run/verified
- [ ] Not implemented

## Directed Tests

- [~] `tb_ring_wraparound.sv` -- ring fill to full, drain, wraparound past ADDR_WIDTH boundary
- [~] `tb_malformed_descriptor.sv` -- zero length, oversized length, misaligned address rejection
- [ ] `tb_back_to_back.sv` -- BLOCKED on `xfer_engine_stub.sv` (not yet written)
- [ ] C2H single-descriptor end-to-end (desc_fetch -> c2h_engine -> tlp_generator, checked against reference TLP header)
- [ ] H2C single-descriptor end-to-end (desc_fetch -> h2c_engine -> tlp_generator/tlp_parser roundtrip)
- [ ] Credit-stall backpressure test (force posted_data_credit_avail low mid-transfer, verify no data drop)
- [ ] MSI-X coalescing timeout boundary test (verify fire exactly at WB_INTR_TIMEOUT expiry)
- [ ] MSI-X force-fire on near-full test
- [ ] Malformed TLP injection into tlp_parser (length field mismatch)

## UVM Environment

- [~] `desc_env.sv` scaffold with driver/monitor/scoreboard -- NOT functional yet, scoreboard has no predictor (see TODO in `desc_scoreboard.sv`)
- [ ] `desc_predictor.sv` -- not written
- [ ] `desc_if.sv` virtual interface -- not written
- [ ] `ring_full_sequence` run against full env
- [ ] Constrained-random regression, 10,000+ descriptors, all coverage bins closed

## Coverage Closure Targets (before claiming "verified")

- [ ] Ring occupancy: low/mid/near_full/full all hit
- [ ] Ring wraparound point hit
- [ ] decode_error crossed with ring occupancy states
- [ ] All 9 FSM states hit
- [ ] MSI-X fire via both timeout and near-full paths
- [ ] Gray-code single-bit-toggle assertion: zero failures across full regression

## Honest Current State

As of this repo scaffold, ZERO tests have actually been run in a simulator.
Every checkbox above is unchecked or partially-checked based on code being
*written*, not *executed and passing*. Do not present this repo as
"verified" in interviews or on your README until you've run these in
ModelSim/Riviera-PRO and can point to real log output.

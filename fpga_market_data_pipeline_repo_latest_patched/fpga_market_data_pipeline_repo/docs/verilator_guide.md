# Verilator Setup and Usage Guide

## 1. Install Verilator (WSL/Ubuntu)

```bash
sudo apt update
sudo apt install verilator
verilator --version
```

If your distro's Verilator is older than v5.0, some SystemVerilog constructs
in this repo (packed structs, `unique case`, `automatic function`, dynamic
arrays in testbenches) may need a newer version. To build the latest from
source:

```bash
sudo apt install git make autoconf g++ flex bison libfl2 libfl-dev
git clone https://github.com/verilator/verilator
cd verilator
git checkout stable
autoconf
./configure
make -j$(nproc)
sudo make install
```

## 2. Run from the repo root

A `Makefile` is included at the repo root. From inside
`fpga_market_data_pipeline_repo/`:

```bash
make sim TB=tb_decoder
make sim TB=tb_order_book
make sim TB=tb_event_packer
make sim TB=tb_dma_bridge
make sim TB=tb_eth_ipv4_udp_parser
make sim TB=tb_udp_payload_framer
make sim_int
```

Each unit test prints `[PASS]` / `[FAIL]` lines followed by a
`SUMMARY pass=<n> fail=<n>` line. `sim_int` runs the full-path integration
test and prints the same style summary.

## 3. Known Verilator caveats for this repo

- Verilator's default mode is synthesizable-subset only; testbenches use
  `initial`, `$display`, `$error`, delays, and dynamic arrays which require
  `--binary` (executable simulation) and `--timing` (delay support) — both
  flags are already in the Makefile.
- `assert property (...)` concurrent assertions in the RTL
  (`market_message_decoder.sv`, `symbol_table.sv`, `event_packer.sv`,
  `dma_bridge.sv`) require Verilator's assertion support; if your Verilator
  build reports errors on `assert property`, add `--assert` to
  `VERILATOR_FLAGS` in the Makefile.
- If you see "Unsupported: virtual interface" or similar errors — none of
  these RTL files use virtual interfaces, so this would indicate a stale or
  very old Verilator version; upgrade per step 1.

## 4. If Verilator reports errors

Send me the exact first error block (file name + line number + message) and
I will fix the corresponding `.sv` file directly.

## 5. After tests pass

Only after `make sim_int` reports `TB_INT_PIPELINE: ALL TESTS PASSED` (or all
unit tests show `fail=0`), proceed to commit and push to GitHub:

```bash
git add .
git commit -m "Verified with Verilator: all unit + integration tests passing"
git push
```

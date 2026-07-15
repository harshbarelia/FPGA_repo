# -----------------------------------------------------------------------------
# Makefile for Verilator-based simulation of the FPGA market-data pipeline
# -----------------------------------------------------------------------------
VERILATOR := /bin/verilator
TOP       ?= $(TB)
RTL_SRCS :=   rtl/pkg/hft_pkg.sv   rtl/common/be_extract.sv   rtl/decoder/market_message_decoder.sv   rtl/book/symbol_table.sv   rtl/book/order_book_core.sv   rtl/event_packer.sv   rtl/dma/dma_bridge.sv   rtl/parser/eth_ipv4_udp_parser.sv   rtl/parser/udp_payload_framer.sv
VERILATOR_FLAGS := --binary --sv --timing -Wno-fatal -Itb/vectors
.PHONY: sim sim_int clean
sim:
ifndef TB
	$(error Usage: make sim TB=<testbench>)
endif
	$(VERILATOR) $(VERILATOR_FLAGS) $(RTL_SRCS) tb/unit/$(TB).sv --top-module $(TB) -o $(TB).out
	./obj_dir/$(TB).out
sim_int:
	$(VERILATOR) $(VERILATOR_FLAGS) $(RTL_SRCS) tb/int/tb_int_pipeline.sv --top-module tb_int_pipeline -o tb_int_pipeline.out
	./obj_dir/tb_int_pipeline.out
clean:
	rm -rf obj_dir *.out

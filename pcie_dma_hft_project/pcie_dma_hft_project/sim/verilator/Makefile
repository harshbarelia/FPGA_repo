# Makefile for Verilator Simulation of PCIe DMA HFT Project

VERILATOR = verilator
VERILATOR_FLAGS = -Wall -Wno-fatal --trace --cc --exe --build

RTL_DIR = ../../rtl
SRC_FILES = $(RTL_DIR)/latency_timestamp_unit.sv \
            $(RTL_DIR)/eth_udp_parser.sv \
            $(RTL_DIR)/descriptor_ring_buffer.sv \
            $(RTL_DIR)/sg_dma_engine.sv \
            $(RTL_DIR)/tb_verilator_top.sv

TB_CPP = sim_main.cpp

.PHONY: all compile test wave clean

all: compile

compile:
	$(VERILATOR) $(VERILATOR_FLAGS) -I$(RTL_DIR) $(SRC_FILES) $(TB_CPP) --top-module tb_verilator_top

test: compile
	./obj_dir/Vtb_verilator_top

wave:
	gtkwave sim_trace.vcd &

clean:
	rm -rf obj_dir sim_trace.vcd

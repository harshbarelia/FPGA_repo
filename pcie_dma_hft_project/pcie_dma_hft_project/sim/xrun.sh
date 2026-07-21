#!/usr/bin/env bash
set -euo pipefail
xrun -64bit -uvm -access +rwc   rtl/descriptor_ring_buffer.sv   rtl/sg_dma_engine.sv   tb/uvm/dma_if.sv   tb/tb_top.sv   tb/sva_assertions.sv

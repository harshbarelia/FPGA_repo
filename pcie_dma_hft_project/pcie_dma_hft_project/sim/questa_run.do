vlib work
vlog -sv +acc rtl/descriptor_ring_buffer.sv rtl/sg_dma_engine.sv tb/uvm/dma_if.sv tb/tb_top.sv tb/sva_assertions.sv
vsim -c tb_top -do "run -all; coverage save dma_cov.ucdb; quit"

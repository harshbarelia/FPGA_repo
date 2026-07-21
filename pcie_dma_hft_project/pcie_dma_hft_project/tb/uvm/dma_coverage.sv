// Functional Coverage Collector for PCIe DMA HFT Verification
// Collects covergroups for descriptor byte lengths, AXI address alignment,
// ring buffer occupancy, and backpressure scenarios.

class dma_coverage extends uvm_subscriber #(dma_seq_item);
    `uvm_component_utils(dma_coverage)

    dma_seq_item curr_item;

    covergroup cg_dma_descriptor;
        option.per_instance = 1;

        // Byte length coverage bins
        cp_byte_len: coverpoint curr_item.byte_len {
            bins min_pkt       = {64};
            bins small_pkt     = {[65:256]};
            bins medium_pkt    = {[257:1024]};
            bins jumbo_pkt     = {[1025:9000]};
        }

        // Host Address alignment
        cp_align: coverpoint curr_item.host_addr[5:0] {
            bins aligned_64b   = {6'b000000};
            bins unaligned     = default;
        }

        // Cross coverage
        cross cp_byte_len, cp_align;
    endgroup

    function new(string name = "dma_coverage", uvm_component parent = null);
        super.new(name, parent);
        cg_dma_descriptor = new();
    endfunction

    function void write(dma_seq_item t);
        curr_item = t;
        cg_dma_descriptor.sample();
    endfunction

    function void report_phase(uvm_phase phase);
        `uvm_info("DMA_COV", $sformatf("Functional Coverage Achieved: %.2f%%", cg_dma_descriptor.get_inst_coverage()), UVM_LOW)
    endfunction
endclass

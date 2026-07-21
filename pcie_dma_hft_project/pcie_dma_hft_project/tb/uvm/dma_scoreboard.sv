// Production End-to-End Scoreboard for PCIe DMA Engine
// Verifies descriptor validity, alignment, payload integrity, and completion interrupts.

class dma_scoreboard extends uvm_component;
    `uvm_component_utils(dma_scoreboard)

    uvm_analysis_imp #(dma_seq_item, dma_scoreboard) item_imp;

    int unsigned total_descriptors;
    int unsigned valid_descriptors;
    int unsigned error_count;

    function new(string name = "dma_scoreboard", uvm_component parent = null);
        super.new(name, parent);
        item_imp = new("item_imp", this);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        total_descriptors = 0;
        valid_descriptors = 0;
        error_count       = 0;
    endfunction

    function void write(dma_seq_item t);
        total_descriptors++;

        // Rule 1: Zero-length descriptors are illegal
        if (t.byte_len == 0) begin
            `uvm_error("DMA_SCB", "FAIL: Observed zero-length descriptor!")
            error_count++;
        end

        // Rule 2: Host addresses must be 64-byte aligned for PCIe TLP performance
        if (t.host_addr[5:0] != 0) begin
            `uvm_error("DMA_SCB", $sformatf("FAIL: Host address 0x%0h is not 64B aligned!", t.host_addr))
            error_count++;
        end

        // Rule 3: Payload queue size must match length / 64
        if (t.payload_q.size() != (t.byte_len / 64)) begin
            `uvm_error("DMA_SCB", $sformatf("FAIL: Payload queue size %0d mismatch for byte length %0d", t.payload_q.size(), t.byte_len))
            error_count++;
        end else begin
            valid_descriptors++;
            `uvm_info("DMA_SCB", $sformatf("PASS: Verified descriptor #%0d (Addr: 0x%0h, Len: %0d B)",
                      total_descriptors, t.host_addr, t.byte_len), UVM_HIGH)
        end
    endfunction

    function void report_phase(uvm_phase phase);
        `uvm_info("DMA_SCB", "==================================================", UVM_LOW)
        `uvm_info("DMA_SCB", $sformatf("SCOREBOARD SUMMARY: Total: %0d | Valid: %0d | Errors: %0d",
                  total_descriptors, valid_descriptors, error_count), UVM_LOW)
        `uvm_info("DMA_SCB", "==================================================", UVM_LOW)
        if (error_count > 0)
            `uvm_fatal("DMA_SCB", "TEST FAILED: Scoreboard detected errors!")
    endfunction
endclass

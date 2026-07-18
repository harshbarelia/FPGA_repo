//==============================================================================
// desc_monitor.sv
// Passively observes writeback completions and broadcasts them to the
// scoreboard via analysis port.
//==============================================================================
class desc_completion_txn extends uvm_sequence_item;
    bit [31:0] status_word;
    bit        error_flag;
    `uvm_object_utils_begin(desc_completion_txn)
        `uvm_field_int(status_word, UVM_ALL_ON)
        `uvm_field_int(error_flag,  UVM_ALL_ON)
    `uvm_object_utils_end
    function new(string name = "desc_completion_txn");
        super.new(name);
    endfunction
endclass

class desc_monitor extends uvm_monitor;
    `uvm_component_utils(desc_monitor)

    virtual desc_if vif;
    uvm_analysis_port #(desc_completion_txn) ap;

    function new(string name, uvm_component parent);
        super.new(name, parent);
        ap = new("ap", this);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        if (!uvm_config_db#(virtual desc_if)::get(this, "", "vif", vif))
            `uvm_fatal("MON", "Virtual interface not set")
    endfunction

    task run_phase(uvm_phase phase);
        // Wait for reset
        @(posedge vif.rst_n);

        forever begin
            @(posedge vif.clk);
            if (vif.writeback_done) begin
                desc_completion_txn txn = desc_completion_txn::type_id::create("txn");
                txn.status_word = vif.wb_wr_data;
                txn.error_flag  = vif.wb_wr_data[1];
                ap.write(txn);
                `uvm_info("MON", $sformatf("Observed completion: status=%08h error=%0b",
                          txn.status_word, txn.error_flag), UVM_MEDIUM)
            end
        end
    endtask
endclass

//==============================================================================
// desc_test_top.sv
// UVM test top: instantiates DUT, creates interface, configures UVM.
// This file is the compilation top for UVM-based simulation.
//
// NOTE: This requires a commercial simulator (QuestaSim / VCS / Riviera-PRO).
// Verilator does NOT support UVM.
//==============================================================================

`include "uvm_macros.svh"
import uvm_pkg::*;

// Include UVM component files in dependency order
`include "desc_seq_item.sv"
`include "desc_monitor.sv"      // includes desc_completion_txn
`include "desc_predictor.sv"
`include "desc_driver.sv"
`include "desc_scoreboard.sv"
`include "desc_sequence.sv"
`include "desc_env.sv"

//==============================================================================
// Base test class
//==============================================================================
class desc_base_test extends uvm_test;
    `uvm_component_utils(desc_base_test)

    desc_env env;
    virtual desc_if vif;

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        env = desc_env::type_id::create("env", this);

        if (!uvm_config_db#(virtual desc_if)::get(this, "", "vif", vif))
            `uvm_fatal("TEST", "Virtual interface not found in config_db")
    endfunction

    task run_phase(uvm_phase phase);
        desc_base_sequence seq;
        phase.raise_objection(this);

        seq = desc_base_sequence::type_id::create("seq");
        seq.num_descriptors = 50;
        seq.start(env.sequencer);

        // Wait for all completions to drain
        #1000;
        phase.drop_objection(this);
    endtask
endclass

//==============================================================================
// Ring-full stress test
//==============================================================================
class desc_ring_full_test extends desc_base_test;
    `uvm_component_utils(desc_ring_full_test)

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    task run_phase(uvm_phase phase);
        ring_full_sequence seq;
        phase.raise_objection(this);

        seq = ring_full_sequence::type_id::create("seq");
        seq.start(env.sequencer);

        #5000;
        phase.drop_objection(this);
    endtask
endclass

//==============================================================================
// Testbench top module
//==============================================================================
module desc_test_top;

    localparam int RING_DEPTH = 128;
    localparam int PTR_WIDTH  = $clog2(RING_DEPTH) + 1;

    logic clk = 0;
    logic rst_n = 0;

    always #5 clk = ~clk;

    // Interface instance
    desc_if #(.RING_DEPTH(RING_DEPTH)) dut_if (.clk(clk), .rst_n(rst_n));

    // DUT: descriptor ring manager + fetch FSM + completion
    desc_ring_mgr #(.RING_DEPTH(RING_DEPTH)) u_ring_mgr (
        .clk(clk), .rst_n(rst_n),
        .sw_insert_ptr_wr(dut_if.sw_insert_ptr_wr),
        .sw_insert_ptr_wr_en(dut_if.sw_insert_ptr_wr_en),
        .hw_extract_ptr_rd(),
        .insert_ptr(dut_if.insert_ptr),
        .extract_ptr(dut_if.extract_ptr),
        .extract_ptr_update(/* from desc_fetch */),
        .extract_valid_req(/* from desc_fetch */),
        .ring_empty(dut_if.ring_empty),
        .ring_full(dut_if.ring_full),
        .extract_valid(dut_if.extract_valid),
        .insert_ptr_update_dbg(),
        .extract_ptr_update_dbg()
    );

    // Reset generation
    initial begin
        rst_n = 0;
        #100;
        rst_n = 1;
    end

    // UVM configuration
    initial begin
        uvm_config_db#(virtual desc_if)::set(null, "*", "vif", dut_if);
        run_test();
    end

endmodule

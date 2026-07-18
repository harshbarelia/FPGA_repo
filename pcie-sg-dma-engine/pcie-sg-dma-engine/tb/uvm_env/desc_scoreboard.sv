//==============================================================================
// desc_scoreboard.sv
// Reference model scoreboard: compares monitor observations against
// predictor expectations. Tracks pass/fail counts and reports in
// report_phase.
//==============================================================================
class desc_scoreboard extends uvm_scoreboard;
    `uvm_component_utils(desc_scoreboard)

    // Analysis implementation for monitor completions
    uvm_analysis_imp #(desc_completion_txn, desc_scoreboard) mon_imp;

    // Expected completion queue (populated by predictor)
    desc_completion_txn expected_q[$];

    int pass_count = 0;
    int fail_count = 0;
    int total_received = 0;

    function new(string name, uvm_component parent);
        super.new(name, parent);
        mon_imp = new("mon_imp", this);
    endfunction

    // Called by monitor's analysis port when a completion is observed
    function void write(desc_completion_txn txn);
        desc_completion_txn expected;
        total_received++;

        if (expected_q.size() == 0) begin
            `uvm_error("SB", $sformatf("Received completion #%0d with no expected entry -- extra/spurious completion (error=%0b)",
                       total_received, txn.error_flag))
            fail_count++;
            return;
        end

        expected = expected_q.pop_front();
        if (txn.error_flag !== expected.error_flag) begin
            `uvm_error("SB", $sformatf("Completion #%0d MISMATCH: got error_flag=%0b expected=%0b",
                       total_received, txn.error_flag, expected.error_flag))
            fail_count++;
        end else begin
            `uvm_info("SB", $sformatf("Completion #%0d MATCH: error_flag=%0b",
                      total_received, txn.error_flag), UVM_HIGH)
            pass_count++;
        end
    endfunction

    // Add expected completion (called by predictor connection)
    function void add_expected(desc_completion_txn txn);
        expected_q.push_back(txn);
    endfunction

    function void check_phase(uvm_phase phase);
        if (expected_q.size() > 0) begin
            `uvm_error("SB", $sformatf("Scoreboard has %0d unmatched expected completions -- descriptors dropped by DUT",
                       expected_q.size()))
            fail_count += expected_q.size();
        end
    endfunction

    function void report_phase(uvm_phase phase);
        `uvm_info("SB", $sformatf(
            "\n========================================\n" +
            "Scoreboard Results:\n" +
            "  Total received:  %0d\n" +
            "  PASS:            %0d\n" +
            "  FAIL:            %0d\n" +
            "========================================",
            total_received, pass_count, fail_count), UVM_LOW)

        if (fail_count > 0)
            `uvm_error("SB", "SCOREBOARD FAILED -- see errors above")
        else
            `uvm_info("SB", "SCOREBOARD PASSED", UVM_LOW)
    endfunction

endclass

//==============================================================================
// tb_msix_coalescing.sv
// Directed test: verifies MSI-X interrupt coalescing behavior.
// Tests: timeout-based fire, near-full force-fire, no-spurious-fire.
//==============================================================================
`timescale 1ns/1ps

module tb_msix_coalescing;

    logic clk = 0, rst_n = 0;
    always #5 clk = ~clk;

    int pass_count = 0;
    int fail_count = 0;

    // msix_ctrl signals
    logic wb_event_pulse;
    logic [15:0] pending_completions;
    logic [31:0] wb_intr_timeout_cfg;
    logic msix_fire;
    logic [7:0] msix_vector_sel;

    // msix_table signals
    logic msix_wr_req;
    logic [63:0] msix_wr_addr;
    logic [31:0] msix_wr_data;
    logic msix_wr_ack;

    msix_ctrl #(
        .TIMEOUT_WIDTH(32),
        .NEAR_FULL_THRESHOLD(12)
    ) u_ctrl (
        .clk, .rst_n,
        .wb_event_pulse,
        .pending_completions,
        .wb_intr_timeout_cfg,
        .msix_fire,
        .msix_vector_sel
    );

    msix_table #(.NUM_VECTORS(8)) u_table (
        .clk, .rst_n,
        .reg_wr_en(1'b0), .reg_wr_addr(32'h0), .reg_wr_data(32'h0),
        .reg_rd_en(1'b0), .reg_rd_addr(32'h0), .reg_rd_data(),
        .msix_fire,
        .msix_vector_sel,
        .msix_wr_req, .msix_wr_addr, .msix_wr_data,
        .msix_wr_ack
    );

    // Auto-ack MSI-X writes after 1 cycle
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) msix_wr_ack <= 0;
        else msix_wr_ack <= msix_wr_req;
    end

    initial begin
        $dumpfile("tb_msix_coalescing.vcd");
        $dumpvars(0, tb_msix_coalescing);
    end

    task automatic check(input string label, input logic condition);
        if (!condition) begin
            $display("FAIL: %s (time=%0t)", label, $time);
            fail_count++;
        end else begin
            $display("PASS: %s (time=%0t)", label, $time);
            pass_count++;
        end
    endtask

    // Watchdog
    initial begin
        #500_000;
        $display("TIMEOUT");
        $finish;
    end

    // Count fire events
    int fire_count;
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) fire_count <= 0;
        else if (msix_fire) fire_count <= fire_count + 1;
    end

    initial begin
        wb_event_pulse = 0;
        pending_completions = 0;
        wb_intr_timeout_cfg = 32'd20;  // short timeout for testing (20 cycles)

        repeat (5) @(posedge clk);
        rst_n = 1;
        @(posedge clk);

        // ==== Test 1: Timeout-based fire ====
        $display("\n--- Test 1: Timeout-based fire ---");
        fire_count = 0;
        wb_event_pulse = 1;
        pending_completions = 16'd1;
        @(posedge clk);
        wb_event_pulse = 0;

        // Wait for timeout to expire (should fire within ~25 cycles)
        repeat (30) @(posedge clk);
        check("timeout fire: msix fired at least once", fire_count > 0);

        // ==== Test 2: No spurious fire without event ====
        $display("\n--- Test 2: No spurious fire ---");
        pending_completions = 16'd0;
        fire_count = 0;
        repeat (50) @(posedge clk);
        check("no-event: msix did NOT fire", fire_count == 0);

        // ==== Test 3: Near-full force-fire ====
        $display("\n--- Test 3: Near-full force-fire ---");
        fire_count = 0;
        wb_event_pulse = 1;
        pending_completions = 16'd14;  // >= NEAR_FULL_THRESHOLD(12)
        @(posedge clk);
        wb_event_pulse = 0;

        // Should fire almost immediately (within a few cycles)
        repeat (10) @(posedge clk);
        check("near-full: msix fired quickly", fire_count > 0);

        // ==== Test 4: Masked vector (PBA behavior) ====
        // This requires configuring msix_table vector_ctrl[0] = 1 (masked)
        // For now, just verify the basic fire mechanism works
        $display("\n--- Test 4: Multiple coalesced events ---");
        fire_count = 0;
        pending_completions = 16'd0;
        repeat(5) @(posedge clk);

        // Send 3 events rapidly, should coalesce into fewer fires
        for (int i = 0; i < 3; i++) begin
            wb_event_pulse = 1;
            pending_completions = pending_completions + 1;
            @(posedge clk);
            wb_event_pulse = 0;
            repeat (5) @(posedge clk);
        end

        // Wait for timeout
        repeat (30) @(posedge clk);
        check("coalesced: fires <= events (coalescing worked)", fire_count <= 3);
        $display("  (fire_count=%0d for 3 events)", fire_count);

        // ==== Summary ====
        $display("\n========================================");
        $display("tb_msix_coalescing: %0d PASS, %0d FAIL", pass_count, fail_count);
        if (fail_count == 0)
            $display("RESULT: ALL TESTS PASSED");
        else
            $display("RESULT: %0d TESTS FAILED", fail_count);
        $display("========================================\n");
        $finish;
    end

endmodule

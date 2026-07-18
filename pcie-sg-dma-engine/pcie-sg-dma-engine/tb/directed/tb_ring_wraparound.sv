//==============================================================================
// tb_ring_wraparound.sv
// Directed test: fill the ring exactly to RING_DEPTH-1, drain it while
// filling more, and force the insert pointer past the ADDR_WIDTH boundary
// to verify wraparound math (insert_ptr - extract_ptr) never miscomputes.
//==============================================================================
`timescale 1ns/1ps

module tb_ring_wraparound;

    localparam RING_DEPTH = 128;
    localparam PTR_WIDTH  = $clog2(RING_DEPTH) + 1;

    logic clk = 0, rst_n = 0;
    logic [PTR_WIDTH-1:0] sw_insert_ptr_wr;
    logic sw_insert_ptr_wr_en;
    logic [PTR_WIDTH-1:0] hw_extract_ptr_rd;
    logic [PTR_WIDTH-1:0] insert_ptr, extract_ptr;
    logic extract_ptr_update, extract_valid_req, extract_valid;
    logic ring_empty, ring_full;

    int pass_count = 0;
    int fail_count = 0;

    always #5 clk = ~clk;

    desc_ring_mgr #(.RING_DEPTH(RING_DEPTH)) dut (
        .clk, .rst_n,
        .sw_insert_ptr_wr, .sw_insert_ptr_wr_en, .hw_extract_ptr_rd,
        .insert_ptr, .extract_ptr,
        .extract_ptr_update, .extract_valid_req,
        .ring_empty, .ring_full, .extract_valid,
        .insert_ptr_update_dbg(), .extract_ptr_update_dbg()
    );

    // Waveform dumping for Verilator
    initial begin
        $dumpfile("tb_ring_wraparound.vcd");
        $dumpvars(0, tb_ring_wraparound);
    end

    task automatic push_n_descriptors(int n);
        for (int i = 0; i < n; i++) begin
            @(posedge clk);
            sw_insert_ptr_wr    = insert_ptr + 1;
            sw_insert_ptr_wr_en = 1;
            @(posedge clk);
            sw_insert_ptr_wr_en = 0;
        end
    endtask

    task automatic drain_n_descriptors(int n);
        for (int i = 0; i < n; i++) begin
            @(posedge clk);
            extract_ptr_update = 1;
            @(posedge clk);
            extract_ptr_update = 0;
        end
    endtask

    task automatic check(input string label, input logic condition);
        if (!condition) begin
            $display("FAIL: %s (time=%0t)", label, $time);
            fail_count++;
        end else begin
            $display("PASS: %s (time=%0t)", label, $time);
            pass_count++;
        end
    endtask

    // Watchdog timer
    initial begin
        #100_000;
        $display("TIMEOUT: test did not complete within 100us");
        $finish;
    end

    initial begin
        rst_n = 0;
        sw_insert_ptr_wr_en = 0;
        extract_ptr_update  = 0;
        extract_valid_req   = 1;
        repeat (5) @(posedge clk);
        rst_n = 1;
        @(posedge clk);

        // ==== Test 1: Initially empty ====
        check("ring starts empty", ring_empty);
        check("ring starts not full", !ring_full);
        check("extract_valid is low when empty", !extract_valid || ring_empty == 0);

        // ==== Test 2: Fill to DEPTH-1 ====
        push_n_descriptors(RING_DEPTH - 1);
        @(posedge clk);
        check("ring not full at DEPTH-1", !ring_full);
        check("ring not empty at DEPTH-1", !ring_empty);

        // ==== Test 3: Fill to DEPTH (full) ====
        push_n_descriptors(1);
        @(posedge clk);
        check("ring full at DEPTH", ring_full);
        check("ring not empty when full", !ring_empty);

        // ==== Test 4: Drain half, push half more (wraparound) ====
        drain_n_descriptors(RING_DEPTH / 2);
        @(posedge clk);
        check("ring not full after draining half", !ring_full);

        push_n_descriptors(RING_DEPTH / 2);
        @(posedge clk);
        check("ring full again after wraparound push", ring_full);
        check("ring not empty after wraparound", !ring_empty);

        // ==== Test 5: Drain all (back to empty) ====
        drain_n_descriptors(RING_DEPTH);
        @(posedge clk);
        check("ring empty after full drain", ring_empty);
        check("ring not full after full drain", !ring_full);

        // ==== Test 6: Push/drain interleaved past multiple wraps ====
        for (int round = 0; round < 3; round++) begin
            push_n_descriptors(RING_DEPTH);
            check($sformatf("round %0d: ring full", round), ring_full);
            drain_n_descriptors(RING_DEPTH);
            @(posedge clk);
            check($sformatf("round %0d: ring empty", round), ring_empty);
        end

        // ==== Summary ====
        $display("\n========================================");
        $display("tb_ring_wraparound: %0d PASS, %0d FAIL", pass_count, fail_count);
        if (fail_count == 0)
            $display("RESULT: ALL TESTS PASSED");
        else
            $display("RESULT: %0d TESTS FAILED", fail_count);
        $display("========================================\n");
        $finish;
    end

endmodule

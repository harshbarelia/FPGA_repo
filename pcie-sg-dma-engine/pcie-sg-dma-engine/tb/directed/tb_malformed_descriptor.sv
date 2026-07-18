//==============================================================================
// tb_malformed_descriptor.sv
// Directed test: injects malformed descriptors (zero length, oversized,
// misaligned src/dst) and verifies decode_error is flagged and dispatch
// is blocked. Also verifies a valid descriptor passes correctly.
//==============================================================================
`timescale 1ns/1ps

module tb_malformed_descriptor;

    localparam int RING_DEPTH = 128;
    localparam int PTR_WIDTH  = $clog2(RING_DEPTH) + 1;

    logic clk = 0;
    logic rst_n = 0;

    logic extract_valid;
    logic [PTR_WIDTH-1:0] extract_ptr;
    logic extract_ptr_update;
    logic extract_valid_req;

    logic desc_rd_req;
    logic [63:0] desc_rd_addr;
    logic desc_rd_valid;
    logic [255:0] desc_rd_data;

    logic [63:0] desc_src_addr;
    logic [63:0] desc_dst_addr;
    logic [31:0] desc_len;
    logic desc_dir;
    logic desc_irq_en;
    logic decode_error;

    logic dispatch_valid;
    logic dispatch_ack;
    logic xfer_done;
    logic xfer_error;

    logic writeback_req;
    logic writeback_done;
    logic [3:0] state_dbg;

    int pass_count = 0;
    int fail_count = 0;

    always #5 clk = ~clk;

    desc_fetch #(
        .RING_DEPTH(RING_DEPTH)
    ) dut (
        .clk(clk),
        .rst_n(rst_n),
        .desc_base_addr(64'h0),
        .extract_valid(extract_valid),
        .extract_ptr(extract_ptr),
        .extract_ptr_update(extract_ptr_update),
        .extract_valid_req(extract_valid_req),
        .desc_rd_req(desc_rd_req),
        .desc_rd_addr(desc_rd_addr),
        .desc_rd_valid(desc_rd_valid),
        .desc_rd_data(desc_rd_data),
        .desc_src_addr(desc_src_addr),
        .desc_dst_addr(desc_dst_addr),
        .desc_len(desc_len),
        .desc_dir(desc_dir),
        .desc_irq_en(desc_irq_en),
        .decode_error(decode_error),
        .dispatch_valid(dispatch_valid),
        .dispatch_ack(dispatch_ack),
        .xfer_done(xfer_done),
        .xfer_error(xfer_error),
        .writeback_req(writeback_req),
        .writeback_done(writeback_done),
        .state_dbg(state_dbg)
    );

    initial begin
        $dumpfile("tb_malformed_descriptor.vcd");
        $dumpvars(0, tb_malformed_descriptor);
    end

    task automatic check(input string label, input logic condition);
        if (!condition) begin
            $display("FAIL: %s (time=%0t, state=%0d)", label, $time, state_dbg);
            fail_count++;
        end else begin
            $display("PASS: %s (time=%0t)", label, $time);
            pass_count++;
        end
    endtask

    // Wait for FSM to reach a target state
    task automatic wait_for_state(input logic [3:0] target, input int timeout_cycles = 100);
        int cnt = 0;
        while (state_dbg != target && cnt < timeout_cycles) begin
            @(posedge clk);
            cnt++;
        end
        if (cnt >= timeout_cycles)
            $display("WARNING: timeout waiting for state %0d (stuck at %0d)", target, state_dbg);
    endtask

    // Inject a descriptor: wait for desc_rd_req, then provide data
    task automatic inject_descriptor(
        input logic [63:0] src,
        input logic [63:0] dst,
        input logic [31:0] len,
        input logic dir,
        input logic irq_en
    );
        // Wait for FSM to issue a read request (FETCH state)
        wait_for_state(4'd1, 50);  // FETCH
        @(posedge clk);            // desc_rd_req is high this cycle, FSM moves to WAIT_FETCH_DATA

        // Now in WAIT_FETCH_DATA, provide the descriptor data
        wait_for_state(4'd2, 10);  // WAIT_FETCH_DATA
        desc_rd_data = '0;
        desc_rd_data[63:0]    = src;
        desc_rd_data[127:64]  = dst;
        desc_rd_data[159:128] = len;
        desc_rd_data[160]     = dir;
        desc_rd_data[162]     = irq_en;
        desc_rd_valid = 1'b1;
        @(posedge clk);
        desc_rd_valid = 1'b0;
    endtask

    // Complete a writeback handshake
    task automatic complete_writeback();
        wait_for_state(4'd6, 50);  // WRITEBACK
        @(posedge clk);
        wait_for_state(4'd7, 10);  // WAIT_WB
        writeback_done = 1'b1;
        @(posedge clk);
        writeback_done = 1'b0;
        // Wait for ADVANCE_EXTRACT -> IDLE
        wait_for_state(4'd0, 20);  // IDLE
        @(posedge clk);
    endtask

    // Watchdog
    initial begin
        #200_000;
        $display("TIMEOUT: test did not complete within 200us");
        $finish;
    end

    initial begin
        // Initialize
        extract_valid = 1'b0;
        extract_ptr = '0;
        desc_rd_valid = 1'b0;
        desc_rd_data = '0;
        dispatch_ack = 1'b0;
        xfer_done = 1'b0;
        xfer_error = 1'b0;
        writeback_done = 1'b0;

        repeat (5) @(posedge clk);
        rst_n = 1'b1;
        @(posedge clk);

        // ==== Test 1: Zero-length descriptor ====
        $display("\n--- Test 1: Zero-length descriptor ---");
        extract_valid = 1'b1;
        inject_descriptor(64'h1000_0000, 64'h2000_0000, 32'd0, 1'b1, 1'b1);

        // Wait for DECODE -> DISPATCH
        wait_for_state(4'd4, 20);  // DISPATCH
        @(posedge clk);
        check("zero-length: decode_error flagged", decode_error);
        check("zero-length: dispatch_valid NOT asserted", !dispatch_valid);

        // Complete the writeback cycle
        complete_writeback();

        // ==== Test 2: Oversized descriptor (>64MB) ====
        $display("\n--- Test 2: Oversized descriptor ---");
        inject_descriptor(64'h1000_0000, 64'h2000_0000, 32'h0500_0000, 1'b1, 1'b1);
        wait_for_state(4'd4, 20);
        @(posedge clk);
        check("oversized: decode_error flagged", decode_error);
        check("oversized: dispatch_valid NOT asserted", !dispatch_valid);
        complete_writeback();

        // ==== Test 3: Misaligned src address ====
        $display("\n--- Test 3: Misaligned src address ---");
        inject_descriptor(64'h1000_0001, 64'h2000_0000, 32'd4096, 1'b0, 1'b1);
        wait_for_state(4'd4, 20);
        @(posedge clk);
        check("misaligned-src: decode_error flagged", decode_error);
        check("misaligned-src: dispatch_valid NOT asserted", !dispatch_valid);
        complete_writeback();

        // ==== Test 4: Misaligned dst address ====
        $display("\n--- Test 4: Misaligned dst address ---");
        inject_descriptor(64'h1000_0000, 64'h2000_0001, 32'd4096, 1'b1, 1'b1);
        wait_for_state(4'd4, 20);
        @(posedge clk);
        check("misaligned-dst: decode_error flagged", decode_error);
        check("misaligned-dst: dispatch_valid NOT asserted", !dispatch_valid);
        complete_writeback();

        // ==== Test 5: Valid descriptor (should NOT flag error) ====
        $display("\n--- Test 5: Valid descriptor ---");
        inject_descriptor(64'h1000_0000, 64'h2000_0000, 32'd4096, 1'b1, 1'b1);
        wait_for_state(4'd4, 20);
        @(posedge clk);
        check("valid: decode_error NOT flagged", !decode_error);
        check("valid: dispatch_valid asserted", dispatch_valid);

        // Ack the dispatch and complete transfer
        dispatch_ack = 1'b1;
        @(posedge clk);
        dispatch_ack = 1'b0;
        wait_for_state(4'd5, 10);  // WAIT_XFER
        xfer_done = 1'b1;
        @(posedge clk);
        xfer_done = 1'b0;
        complete_writeback();

        // ==== Test 6: Exactly MAX_XFER_LEN (boundary) ====
        $display("\n--- Test 6: Exactly MAX_XFER_LEN ---");
        inject_descriptor(64'h1000_0000, 64'h2000_0000, 32'h0400_0000, 1'b0, 1'b0);
        wait_for_state(4'd4, 20);
        @(posedge clk);
        check("max-len: decode_error NOT flagged", !decode_error);
        check("max-len: dispatch_valid asserted", dispatch_valid);
        dispatch_ack = 1'b1;
        @(posedge clk);
        dispatch_ack = 1'b0;
        wait_for_state(4'd5, 10);
        xfer_done = 1'b1;
        @(posedge clk);
        xfer_done = 1'b0;
        complete_writeback();

        // ==== Summary ====
        extract_valid = 1'b0;
        $display("\n========================================");
        $display("tb_malformed_descriptor: %0d PASS, %0d FAIL", pass_count, fail_count);
        if (fail_count == 0)
            $display("RESULT: ALL TESTS PASSED");
        else
            $display("RESULT: %0d TESTS FAILED", fail_count);
        $display("========================================\n");
        $finish;
    end

endmodule
//==============================================================================
// tb_back_to_back.sv
// Directed test: push N descriptors with zero idle gap between them and verify
// the FETCH->DECODE->DISPATCH pipeline handles consecutive descriptors
// without dropping or duplicating any, and that extract_ptr advances exactly
// once per completed descriptor.
//==============================================================================
`timescale 1ns/1ps

module tb_back_to_back;

    localparam int RING_DEPTH     = 128;
    localparam int PTR_WIDTH      = $clog2(RING_DEPTH) + 1;
    localparam int NUM_DESCRIPTORS = 10;
    localparam int STUB_LATENCY   = 3;

    logic clk = 0, rst_n = 0;
    always #5 clk = ~clk;

    // Ring manager signals
    logic [PTR_WIDTH-1:0] sw_insert_ptr_wr;
    logic sw_insert_ptr_wr_en;
    logic [PTR_WIDTH-1:0] insert_ptr, extract_ptr;
    logic extract_ptr_update, extract_valid_req, extract_valid;
    logic ring_empty, ring_full;

    // Desc fetch signals
    logic desc_rd_req;
    logic [63:0] desc_rd_addr;
    logic desc_rd_valid;
    logic [255:0] desc_rd_data;
    logic [63:0] desc_src_addr, desc_dst_addr;
    logic [31:0] desc_len;
    logic desc_dir, desc_irq_en, decode_error;
    logic dispatch_valid, dispatch_ack;
    logic xfer_done, xfer_error;
    logic writeback_req, writeback_done;
    logic [3:0] state_dbg;

    int pass_count = 0;
    int fail_count = 0;

    // DUT instantiations
    desc_ring_mgr #(.RING_DEPTH(RING_DEPTH)) u_ring (
        .clk, .rst_n,
        .sw_insert_ptr_wr, .sw_insert_ptr_wr_en,
        .hw_extract_ptr_rd(),
        .insert_ptr, .extract_ptr,
        .extract_ptr_update, .extract_valid_req,
        .ring_empty, .ring_full, .extract_valid,
        .insert_ptr_update_dbg(), .extract_ptr_update_dbg()
    );

    desc_fetch #(.RING_DEPTH(RING_DEPTH)) u_fetch (
        .clk, .rst_n,
        .desc_base_addr(64'h0000_1000),
        .extract_valid, .extract_ptr,
        .extract_ptr_update, .extract_valid_req,
        .desc_rd_req, .desc_rd_addr,
        .desc_rd_valid, .desc_rd_data,
        .desc_src_addr, .desc_dst_addr,
        .desc_len, .desc_dir, .desc_irq_en,
        .decode_error,
        .dispatch_valid, .dispatch_ack,
        .xfer_done, .xfer_error,
        .writeback_req, .writeback_done,
        .state_dbg
    );

    // Transfer engine stub
    xfer_engine_stub #(.LATENCY_CYCLES(STUB_LATENCY)) u_stub (
        .clk, .rst_n,
        .dispatch_valid, .dispatch_ack,
        .xfer_done, .xfer_error
    );

    // Descriptor completion (writeback)
    // Ack the writeback TLP write request after 1 cycle
    logic wb_wr_req_out;
    logic wb_wr_ack_r;
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) wb_wr_ack_r <= 0;
        else wb_wr_ack_r <= wb_wr_req_out;
    end

    desc_completion u_completion (
        .clk, .rst_n,
        .writeback_req,
        .decode_error,
        .xfer_error,
        .writeback_done,
        .wb_target_addr(64'hDEAD_0000),
        .wb_wr_req(wb_wr_req_out), .wb_wr_addr(), .wb_wr_data(),
        .wb_wr_ack(wb_wr_ack_r),
        .pending_completions(), .msix_fire(1'b0),
        .wb_event_pulse(), .wb_intr_timeout_cfg()
    );

    // Simulated host memory: respond to descriptor read requests
    // Auto-responds with a valid descriptor after 2 cycles
    logic [1:0] rd_delay;
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            desc_rd_valid <= 0;
            desc_rd_data  <= '0;
            rd_delay      <= 0;
        end else begin
            desc_rd_valid <= 0;
            if (desc_rd_req) begin
                rd_delay <= 2'd2;
            end else if (rd_delay > 0) begin
                rd_delay <= rd_delay - 1;
                if (rd_delay == 1) begin
                    desc_rd_valid <= 1;
                    desc_rd_data  <= '0;
                    desc_rd_data[63:0]    <= 64'hAAAA_0000;  // src
                    desc_rd_data[127:64]  <= 64'hBBBB_0000;  // dst
                    desc_rd_data[159:128] <= 32'd256;         // length (valid)
                    desc_rd_data[160]     <= 1'b1;            // dir=C2H
                    desc_rd_data[162]     <= 1'b0;            // irq_en=0
                end
            end
        end
    end

    initial begin
        $dumpfile("tb_back_to_back.vcd");
        $dumpvars(0, tb_back_to_back);
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
        $display("TIMEOUT: test did not complete within 500us");
        $finish;
    end

    initial begin
        sw_insert_ptr_wr_en = 0;
        repeat (5) @(posedge clk);
        rst_n = 1;
        @(posedge clk);

        // Push NUM_DESCRIPTORS back-to-back
        $display("Pushing %0d descriptors back-to-back...", NUM_DESCRIPTORS);
        for (int i = 0; i < NUM_DESCRIPTORS; i++) begin
            @(posedge clk);
            sw_insert_ptr_wr    = insert_ptr + 1;
            sw_insert_ptr_wr_en = 1;
            @(posedge clk);
            sw_insert_ptr_wr_en = 0;
        end

        // Wait for all descriptors to be processed (dynamic wait)
        // Each descriptor takes: FETCH(1) + WAIT_FETCH(2-3) + DECODE(1) + DISPATCH(1-2)
        // + STUB_LATENCY(3) + WRITEBACK(1) + WAIT_WB(1-2) + ADVANCE_EXTRACT(1) + IDLE(1) ≈ 15+ cycles
        begin
            int timeout = NUM_DESCRIPTORS * 50 + 200;
            int cnt = 0;
            while (!ring_empty && cnt < timeout) begin
                @(posedge clk);
                cnt++;
            end
            if (cnt >= timeout)
                $display("WARNING: timeout waiting for ring to drain (cnt=%0d)", cnt);
        end

        // Check that extract_ptr advanced exactly NUM_DESCRIPTORS times
        check($sformatf("extract_ptr advanced to %0d (actual=%0d)", NUM_DESCRIPTORS, extract_ptr),
              extract_ptr[PTR_WIDTH-2:0] == NUM_DESCRIPTORS[PTR_WIDTH-2:0]);
        check("ring empty after processing all", ring_empty);
        check("no decode errors", !decode_error);

        $display("\n========================================");
        $display("tb_back_to_back: %0d PASS, %0d FAIL", pass_count, fail_count);
        if (fail_count == 0)
            $display("RESULT: ALL TESTS PASSED");
        else
            $display("RESULT: %0d TESTS FAILED", fail_count);
        $display("========================================\n");
        $finish;
    end

endmodule

//==============================================================================
// tb_c2h_single.sv
// Directed test: single C2H descriptor end-to-end.
// desc_fetch -> c2h_engine -> tlp_generator
// Verifies TLP generation for a Memory Write, xfer_done fires correctly.
//
// Upgraded to support Multi-Beat Payload Streaming.
//==============================================================================
`timescale 1ns/1ps

module tb_c2h_single;

    localparam int AXIS_WIDTH = 256;
    localparam int MPS_BYTES  = 64;   // 2 beats per TLP payload

    logic clk = 0, rst_n = 0;
    always #5 clk = ~clk;

    int pass_count = 0;
    int fail_count = 0;

    // C2H engine signals
    logic dispatch_valid, dispatch_ack, xfer_done, xfer_error;
    logic [63:0] dst_addr;
    logic [31:0] xfer_len;

    // AXI-Stream source (user data to send to host)
    logic [AXIS_WIDTH-1:0] s_axis_tdata;
    logic s_axis_tvalid, s_axis_tlast, s_axis_tready;

    // TLP request interface
    logic tlp_req_valid, tlp_req_ack;
    logic [2:0] tlp_req_type;
    logic [63:0] tlp_req_addr;
    logic [31:0] tlp_req_len;
    logic [9:0] tlp_req_tag;

    // Streaming payload interface
    logic [AXIS_WIDTH-1:0] tlp_payload_tdata;
    logic                  tlp_payload_tvalid;
    logic                  tlp_payload_tready;
    logic                  tlp_payload_tlast;

    // TLP generator AXIS outputs
    logic [AXIS_WIDTH-1:0] m_axis_tdata;
    logic m_axis_tvalid, m_axis_tlast, m_axis_tready;

    c2h_engine #(
        .AXIS_WIDTH(AXIS_WIDTH),
        .MPS_BYTES(MPS_BYTES)
    ) u_c2h (
        .clk, .rst_n,
        .dispatch_valid, .dst_addr, .xfer_len,
        .dispatch_ack, .xfer_done, .xfer_error,
        .s_axis_tdata, .s_axis_tvalid, .s_axis_tlast, .s_axis_tready,
        .tlp_req_valid, .tlp_req_type, .tlp_req_addr, .tlp_req_len,
        .tlp_req_tag, .tlp_req_grant(tlp_req_valid), .tlp_req_ack(tlp_req_ack),
        .tlp_payload_tdata, .tlp_payload_tvalid, .tlp_payload_tready, .tlp_payload_tlast
    );

    tlp_generator #(.AXIS_WIDTH(AXIS_WIDTH)) u_tlp_gen (
        .clk, .rst_n,
        .req_valid(tlp_req_valid),
        .req_type(tlp_req_type),
        .req_addr(tlp_req_addr),
        .req_length_bytes(tlp_req_len),
        .req_tag(tlp_req_tag),
        .req_ack(tlp_req_ack),
        .payload_tdata(tlp_payload_tdata),
        .payload_tvalid(tlp_payload_tvalid),
        .payload_tready(tlp_payload_tready),
        .payload_tlast(tlp_payload_tlast),
        .posted_hdr_credit_avail(1'b1),
        .posted_data_credit_avail(1'b1),
        .nonposted_hdr_credit_avail(1'b1),
        .m_axis_tdata, .m_axis_tvalid, .m_axis_tlast,
        .m_axis_tready
    );

    // Always accept TLP output
    assign m_axis_tready = 1'b1;

    initial begin
        $dumpfile("tb_c2h_single.vcd");
        $dumpvars(0, tb_c2h_single);
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
        #100_000;
        $display("TIMEOUT");
        $finish;
    end

    // Count TLP beats emitted
    int tlp_beat_count;
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) tlp_beat_count <= 0;
        else if (m_axis_tvalid && m_axis_tready) tlp_beat_count <= tlp_beat_count + 1;
    end

    initial begin
        dispatch_valid = 0;
        dst_addr = 64'h0;
        xfer_len = 0;
        s_axis_tdata = '0;
        s_axis_tvalid = 0;
        s_axis_tlast = 0;

        repeat (5) @(posedge clk);
        rst_n = 1;
        @(posedge clk);

        // ==== Test 1: Single-beat C2H transfer (32 bytes, fits in 1 beat of AXIS_WIDTH=256) ====
        $display("\n--- Test 1: Single C2H descriptor, 32 bytes ---");
        dst_addr = 64'h0000_DEAD_BEEF_0000;
        xfer_len = 32'd32;
        dispatch_valid = 1;
        @(posedge clk);
        while (!dispatch_ack) @(posedge clk);
        dispatch_valid = 0;

        // Provide AXI-Stream data
        s_axis_tdata = 256'hCAFE_BABE_1234_5678_AAAA_BBBB_CCCC_DDDD_1111_2222_3333_4444_5555_6666_7777_8888;
        s_axis_tvalid = 1;
        s_axis_tlast = 1;
        while (!s_axis_tready) @(posedge clk);
        @(posedge clk);
        s_axis_tvalid = 0;
        s_axis_tlast = 0;

        // Wait for xfer_done
        while (!xfer_done) @(posedge clk);

        check("single-beat C2H: xfer_done asserted", xfer_done);
        check("single-beat C2H: no error", !xfer_error);
        check("single-beat C2H: TLP beats emitted (header+payload = 2)", tlp_beat_count == 2);

        // ==== Test 2: Two-beat C2H transfer (64 bytes, fits in MPS_BYTES=64) ====
        $display("\n--- Test 2: Two-beat C2H descriptor, 64 bytes ---");
        tlp_beat_count = 0;
        repeat(2) @(posedge clk);

        dst_addr = 64'h0000_0000_AAAA_0000;
        xfer_len = 32'd64;
        dispatch_valid = 1;
        @(posedge clk);
        while (!dispatch_ack) @(posedge clk);
        dispatch_valid = 0;

        // Provide first beat
        s_axis_tdata = 256'h1111_1111_1111_1111_1111_1111_1111_1111_1111_1111_1111_1111_1111_1111_1111_1111;
        s_axis_tvalid = 1;
        s_axis_tlast = 0;
        while (!s_axis_tready) @(posedge clk);
        @(posedge clk);

        // Provide second beat
        s_axis_tdata = 256'h2222_2222_2222_2222_2222_2222_2222_2222_2222_2222_2222_2222_2222_2222_2222_2222;
        s_axis_tvalid = 1;
        s_axis_tlast = 1;
        while (!s_axis_tready) @(posedge clk);
        @(posedge clk);
        s_axis_tvalid = 0;
        s_axis_tlast = 0;

        // Wait for completion
        while (!xfer_done) @(posedge clk);

        check("two-beat C2H: xfer_done asserted", xfer_done);
        check("two-beat C2H: no error", !xfer_error);
        check("two-beat C2H: TLP beats emitted (header+2 payload = 3)", tlp_beat_count == 3);

        // ==== Summary ====
        $display("\n========================================");
        $display("tb_c2h_single: %0d PASS, %0d FAIL", pass_count, fail_count);
        if (fail_count == 0)
            $display("RESULT: ALL TESTS PASSED");
        else
            $display("RESULT: %0d TESTS FAILED", fail_count);
        $display("========================================\n");
        $finish;
    end

endmodule

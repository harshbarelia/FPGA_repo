//==============================================================================
// tb_h2c_single.sv
// Directed test: single H2C descriptor end-to-end.
// desc_fetch -> h2c_engine -> tlp_generator / host completion responder -> h2c_engine
// Verifies TLP generation for a Memory Read, receiving Completion TLPs,
// streaming data out on the AXIS master interface, and xfer_done assertion.
//==============================================================================
`timescale 1ns/1ps

module tb_h2c_single;

    localparam int AXIS_WIDTH = 256;
    localparam int MAX_READ_REQ_BYTES = 64; // small chunk size for testing

    logic clk = 0, rst_n = 0;
    always #5 clk = ~clk;

    int pass_count = 0;
    int fail_count = 0;

    // H2C engine signals
    logic dispatch_valid, dispatch_ack, xfer_done, xfer_error;
    logic [63:0] src_addr;
    logic [31:0] xfer_len;

    // TLP request interface (MRd)
    logic tlp_req_valid, tlp_req_ack;
    logic [2:0] tlp_req_type;
    logic [63:0] tlp_req_addr;
    logic [31:0] tlp_req_len;
    logic [9:0] tlp_req_tag;
    logic [AXIS_WIDTH-1:0] tlp_req_payload;

    // Completion data to h2c_engine
    logic cpld_valid;
    logic [9:0] cpld_tag;
    logic [AXIS_WIDTH-1:0] cpld_data;
    logic cpld_last;
    logic cpld_malformed;

    // AXI-Stream master output (FPGA consumer)
    logic [AXIS_WIDTH-1:0] m_axis_tdata;
    logic m_axis_tvalid, m_axis_tlast, m_axis_tready;

    h2c_engine #(
        .AXIS_WIDTH(AXIS_WIDTH),
        .MAX_READ_REQ_BYTES(MAX_READ_REQ_BYTES)
    ) u_h2c (
        .clk, .rst_n,
        .dispatch_valid, .src_addr, .xfer_len,
        .dispatch_ack, .xfer_done, .xfer_error,
        .tlp_req_valid, .tlp_req_type, .tlp_req_addr, .tlp_req_len,
        .tlp_req_tag, .tlp_req_payload, .tlp_req_ack,
        .cpld_valid, .cpld_tag, .cpld_data, .cpld_last, .cpld_malformed,
        .m_axis_tdata, .m_axis_tvalid, .m_axis_tlast, .m_axis_tready
    );

    // Auto-ack H2C's MRd TLP requests
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) tlp_req_ack <= 0;
        else tlp_req_ack <= tlp_req_valid;
    end

    // Host memory responder model
    // When H2C asserts tlp_req_valid (type 0 = MRd), host memory responds N cycles later
    // with Completion with Data (CplD).
    logic [2:0] cpl_delay;
    logic [9:0] cpl_tag_r;
    logic [31:0] cpl_len_r;
    logic [63:0] cpl_addr_r;
    logic respond_active;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            cpl_delay      <= 0;
            cpl_tag_r      <= 0;
            cpl_len_r      <= 0;
            cpl_addr_r     <= 0;
            respond_active <= 0;
            cpld_valid     <= 0;
            cpld_data      <= '0;
            cpld_last      <= 0;
            cpld_malformed <= 0;
        end else begin
            cpld_valid <= 0;
            cpld_last  <= 0;

            if (tlp_req_valid && tlp_req_ack && tlp_req_type == 3'd0) begin
                cpl_tag_r      <= tlp_req_tag;
                cpl_len_r      <= tlp_req_len;
                cpl_addr_r     <= tlp_req_addr;
                cpl_delay      <= 3'd3; // 3 cycles delay
                respond_active <= 1;
            end else if (respond_active) begin
                if (cpl_delay > 0) begin
                    cpl_delay <= cpl_delay - 1;
                end else begin
                    cpld_valid     <= 1;
                    cpld_tag       <= cpl_tag_r;
                    // Provide some test pattern as memory data
                    cpld_data      <= {4{cpl_addr_r[31:0], 32'h55AA_55AA}};
                    cpld_last      <= 1; // single-beat completion for this request size
                    cpld_malformed <= 0;
                    respond_active <= 0;
                end
            end
        end
    end

    initial begin
        $dumpfile("tb_h2c_single.vcd");
        $dumpvars(0, tb_h2c_single);
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

    // Count user stream beats
    int stream_beat_count;
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) stream_beat_count <= 0;
        else if (m_axis_tvalid && m_axis_tready) stream_beat_count <= stream_beat_count + 1;
    end

    initial begin
        dispatch_valid = 0;
        src_addr = 64'h0;
        xfer_len = 0;
        m_axis_tready = 1;

        repeat (5) @(posedge clk);
        rst_n = 1;
        @(posedge clk);

        // ==== Test 1: Single read request (64 bytes, fits in MAX_READ_REQ_BYTES) ====
        $display("\n--- Test 1: Single H2C read request, 64 bytes ---");
        src_addr = 64'h0000_1000_2000_3000;
        xfer_len = 32'd64;
        dispatch_valid = 1;
        @(posedge clk);
        while (!dispatch_ack) @(posedge clk);
        dispatch_valid = 0;

        // Wait for completion stream and xfer_done
        while (!xfer_done) @(posedge clk);
        @(posedge clk);

        check("single H2C: xfer_done asserted", 1'b1);
        check("single H2C: no error", !xfer_error);
        check("single H2C: data stream beats count == 1", stream_beat_count == 1);

        // ==== Test 2: Multi-request read (128 bytes, requires 2 requests of 64 bytes) ====
        $display("\n--- Test 2: Multi-request H2C read, 128 bytes ---");
        stream_beat_count = 0;
        repeat(2) @(posedge clk);

        src_addr = 64'h0000_5000_6000_7000;
        xfer_len = 32'd128;
        dispatch_valid = 1;
        @(posedge clk);
        while (!dispatch_ack) @(posedge clk);
        dispatch_valid = 0;

        // Wait for completion stream and xfer_done
        while (!xfer_done) @(posedge clk);
        @(posedge clk);

        check("multi H2C: xfer_done asserted", 1'b1);
        check("multi H2C: no error", !xfer_error);
        check("multi H2C: data stream beats count == 2", stream_beat_count == 2);

        // ==== Summary ====
        $display("\n========================================");
        $display("tb_h2c_single: %0d PASS, %0d FAIL", pass_count, fail_count);
        if (fail_count == 0)
            $display("RESULT: ALL TESTS PASSED");
        else
            $display("RESULT: %0d TESTS FAILED", fail_count);
        $display("========================================\n");
        $finish;
    end

endmodule

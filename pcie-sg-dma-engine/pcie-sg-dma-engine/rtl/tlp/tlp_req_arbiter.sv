//==============================================================================
// tlp_req_arbiter.sv
// Round-robin arbiter with fixed priority override for the shared TLP
// generator. Multiplexes 4 request sources onto a single tlp_generator.
//
// Upgraded to support Multi-Beat Payload Streaming and distinct Grant/Ack signals.
//==============================================================================
module tlp_req_arbiter #(
    parameter int AXIS_WIDTH  = 256,
    parameter int NUM_PORTS   = 4
)(
    input  logic          clk,
    input  logic          rst_n,

    // Port 0: desc_fetch (highest priority)
    input  logic          p0_req_valid,
    input  logic [2:0]    p0_req_type,
    input  logic [63:0]   p0_req_addr,
    input  logic [31:0]   p0_req_len,
    input  logic [AXIS_WIDTH-1:0] p0_req_payload,
    input  logic [9:0]    p0_req_tag,
    output logic          p0_req_ack,
    output logic          p0_grant,
    input  logic [AXIS_WIDTH-1:0] p0_payload_tdata,
    input  logic          p0_payload_tvalid,
    output logic          p0_payload_tready,
    input  logic          p0_payload_tlast,

    // Port 1: h2c_engine
    input  logic          p1_req_valid,
    input  logic [2:0]    p1_req_type,
    input  logic [63:0]   p1_req_addr,
    input  logic [31:0]   p1_req_len,
    input  logic [AXIS_WIDTH-1:0] p1_req_payload,
    input  logic [9:0]    p1_req_tag,
    output logic          p1_req_ack,
    output logic          p1_grant,
    input  logic [AXIS_WIDTH-1:0] p1_payload_tdata,
    input  logic          p1_payload_tvalid,
    output logic          p1_payload_tready,
    input  logic          p1_payload_tlast,

    // Port 2: c2h_engine (Multi-beat writer)
    input  logic          p2_req_valid,
    input  logic [2:0]    p2_req_type,
    input  logic [63:0]   p2_req_addr,
    input  logic [31:0]   p2_req_len,
    input  logic [AXIS_WIDTH-1:0] p2_req_payload,
    input  logic [9:0]    p2_req_tag,
    output logic          p2_req_ack,
    output logic          p2_grant,
    input  logic [AXIS_WIDTH-1:0] p2_payload_tdata,
    input  logic          p2_payload_tvalid,
    output logic          p2_payload_tready,
    input  logic          p2_payload_tlast,

    // Port 3: writeback + MSI-X
    input  logic          p3_req_valid,
    input  logic [2:0]    p3_req_type,
    input  logic [63:0]   p3_req_addr,
    input  logic [31:0]   p3_req_len,
    input  logic [AXIS_WIDTH-1:0] p3_req_payload,
    input  logic [9:0]    p3_req_tag,
    output logic          p3_req_ack,
    output logic          p3_grant,
    input  logic [AXIS_WIDTH-1:0] p3_payload_tdata,
    input  logic          p3_payload_tvalid,
    output logic          p3_payload_tready,
    input  logic          p3_payload_tlast,

    // Output to tlp_generator
    output logic          arb_req_valid,
    output logic [2:0]    arb_req_type,
    output logic [63:0]   arb_req_addr,
    output logic [31:0]   arb_req_len,
    output logic [9:0]    arb_req_tag,
    input  logic          arb_req_ack,

    // Streaming payload output to tlp_generator
    output logic [AXIS_WIDTH-1:0] arb_payload_tdata,
    output logic          arb_payload_tvalid,
    input  logic          arb_payload_tready,
    output logic          arb_payload_tlast
);

    typedef enum logic [1:0] {ARB_IDLE, ARB_GRANT} arb_state_t;
    arb_state_t state;

    logic [1:0] grant_port;
    logic [1:0] rr_last;

    logic [1:0] next_grant;
    logic       any_request;

    always_comb begin
        next_grant  = 2'd0;
        any_request = 1'b0;

        if (p0_req_valid) begin
            next_grant  = 2'd0;
            any_request = 1'b1;
        end else begin
            case (rr_last)
                2'd1: begin
                    if      (p2_req_valid) begin next_grant = 2'd2; any_request = 1'b1; end
                    else if (p3_req_valid) begin next_grant = 2'd3; any_request = 1'b1; end
                    else if (p1_req_valid) begin next_grant = 2'd1; any_request = 1'b1; end
                end
                2'd2: begin
                    if      (p3_req_valid) begin next_grant = 2'd3; any_request = 1'b1; end
                    else if (p1_req_valid) begin next_grant = 2'd1; any_request = 1'b1; end
                    else if (p2_req_valid) begin next_grant = 2'd2; any_request = 1'b1; end
                end
                default: begin
                    if      (p1_req_valid) begin next_grant = 2'd1; any_request = 1'b1; end
                    else if (p2_req_valid) begin next_grant = 2'd2; any_request = 1'b1; end
                    else if (p3_req_valid) begin next_grant = 2'd3; any_request = 1'b1; end
                end
            endcase
        end
    end

    // State machine
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state      <= ARB_IDLE;
            grant_port <= 2'd0;
            rr_last    <= 2'd0;
        end else case (state)
            ARB_IDLE: begin
                if (any_request) begin
                    grant_port <= next_grant;
                    state      <= ARB_GRANT;
                end
            end
            ARB_GRANT: begin
                if (arb_req_ack) begin
                    if (grant_port != 2'd0)
                        rr_last <= grant_port;
                    state <= ARB_IDLE;
                end
            end
            default: state <= ARB_IDLE;
        endcase
    end

    // Output mux for request control
    always_comb begin
        arb_req_valid   = 1'b0;
        arb_req_type    = 3'd0;
        arb_req_addr    = 64'd0;
        arb_req_len     = 32'd0;
        arb_req_tag     = 10'd0;

        if (state == ARB_GRANT) begin
            case (grant_port)
                2'd0: begin
                    arb_req_valid   = p0_req_valid;
                    arb_req_type    = p0_req_type;
                    arb_req_addr    = p0_req_addr;
                    arb_req_len     = p0_req_len;
                    arb_req_tag     = p0_req_tag;
                end
                2'd1: begin
                    arb_req_valid   = p1_req_valid;
                    arb_req_type    = p1_req_type;
                    arb_req_addr    = p1_req_addr;
                    arb_req_len     = p1_req_len;
                    arb_req_tag     = p1_req_tag;
                end
                2'd2: begin
                    arb_req_valid   = p2_req_valid;
                    arb_req_type    = p2_req_type;
                    arb_req_addr    = p2_req_addr;
                    arb_req_len     = p2_req_len;
                    arb_req_tag     = p2_req_tag;
                end
                2'd3: begin
                    arb_req_valid   = p3_req_valid;
                    arb_req_type    = p3_req_type;
                    arb_req_addr    = p3_req_addr;
                    arb_req_len     = p3_req_len;
                    arb_req_tag     = p3_req_tag;
                end
            endcase
        end
    end

    // Output mux for streaming payload
    always_comb begin
        arb_payload_tdata  = '0;
        arb_payload_tvalid = 1'b0;
        arb_payload_tlast  = 1'b0;

        p0_payload_tready  = 1'b0;
        p1_payload_tready  = 1'b0;
        p2_payload_tready  = 1'b0;
        p3_payload_tready  = 1'b0;

        if (state == ARB_GRANT) begin
            case (grant_port)
                2'd0: begin
                    arb_payload_tdata  = p0_payload_tdata;
                    arb_payload_tvalid = p0_payload_tvalid;
                    arb_payload_tlast  = p0_payload_tlast;
                    p0_payload_tready  = arb_payload_tready;
                end
                2'd1: begin
                    arb_payload_tdata  = p1_payload_tdata;
                    arb_payload_tvalid = p1_payload_tvalid;
                    arb_payload_tlast  = p1_payload_tlast;
                    p1_payload_tready  = arb_payload_tready;
                end
                2'd2: begin
                    arb_payload_tdata  = p2_payload_tdata;
                    arb_payload_tvalid = p2_payload_tvalid;
                    arb_payload_tlast  = p2_payload_tlast;
                    p2_payload_tready  = arb_payload_tready;
                end
                2'd3: begin
                    arb_payload_tdata  = p3_payload_tdata;
                    arb_payload_tvalid = p3_payload_tvalid;
                    arb_payload_tlast  = p3_payload_tlast;
                    p3_payload_tready  = arb_payload_tready;
                end
            endcase
        end
    end

    // Grant signals: active when the port holds the grant
    assign p0_grant = (state == ARB_GRANT) && (grant_port == 2'd0);
    assign p1_grant = (state == ARB_GRANT) && (grant_port == 2'd1);
    assign p2_grant = (state == ARB_GRANT) && (grant_port == 2'd2);
    assign p3_grant = (state == ARB_GRANT) && (grant_port == 2'd3);

    // Per-port ack: transaction complete ack
    assign p0_req_ack = arb_req_ack && (state == ARB_GRANT) && (grant_port == 2'd0);
    assign p1_req_ack = arb_req_ack && (state == ARB_GRANT) && (grant_port == 2'd1);
    assign p2_req_ack = arb_req_ack && (state == ARB_GRANT) && (grant_port == 2'd2);
    assign p3_req_ack = arb_req_ack && (state == ARB_GRANT) && (grant_port == 2'd3);

endmodule

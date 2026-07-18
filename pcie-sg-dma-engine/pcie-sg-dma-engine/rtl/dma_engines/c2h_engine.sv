//==============================================================================
// c2h_engine.sv
// Card-to-Host DMA engine. Consumes an AXI4-Stream source, segments it
// into MPS-sized chunks, and drives tlp_generator.sv.
//
// Upgraded to support Multi-Beat Payload Streaming.
//==============================================================================
module c2h_engine #(
    parameter int AXIS_WIDTH = 256,
    parameter int MPS_BYTES  = 256      // Max Payload Size
)(
    input  logic          clk,
    input  logic          rst_n,

    // Dispatch from desc_fetch.sv
    input  logic          dispatch_valid,
    input  logic [63:0]   dst_addr,
    input  logic [31:0]   xfer_len,
    output logic          dispatch_ack,
    output logic          xfer_done,
    output logic          xfer_error,

    // AXI4-Stream source (data to be written to host)
    input  logic [AXIS_WIDTH-1:0] s_axis_tdata,
    input  logic          s_axis_tvalid,
    input  logic          s_axis_tlast,
    output logic          s_axis_tready,

    // Request interface into tlp_req_arbiter -> tlp_generator
    output logic          tlp_req_valid,
    output logic [2:0]    tlp_req_type,
    output logic [63:0]   tlp_req_addr,
    output logic [31:0]   tlp_req_len,
    output logic [9:0]    tlp_req_tag,
    input  logic          tlp_req_grant,
    input  logic          tlp_req_ack,

    // Streaming Payload Interface to TLP generator / Arbiter
    output logic [AXIS_WIDTH-1:0] tlp_payload_tdata,
    output logic                  tlp_payload_tvalid,
    input  logic                  tlp_payload_tready,
    output logic                  tlp_payload_tlast
);

    localparam int BYTES_PER_BEAT = AXIS_WIDTH / 8;

    typedef enum logic [2:0] {
        IDLE, ACCEPT, ISSUE_TLP, STREAM_PAYLOAD, NEXT_CHUNK, DONE
    } c2h_state_t;

    c2h_state_t state;

    logic [31:0] bytes_remaining;
    logic [31:0] chunk_bytes_remaining;
    logic [63:0] cur_dst_addr;
    logic [31:0] chunk_len;

    // How many bytes does this TLP carry?
    assign chunk_len = (bytes_remaining > MPS_BYTES) ?
                       MPS_BYTES[31:0] : bytes_remaining;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= IDLE;
        end else case (state)
            IDLE:        if (dispatch_valid) state <= ACCEPT;
            ACCEPT:      state <= ISSUE_TLP;
            ISSUE_TLP:   if (tlp_req_grant) state <= STREAM_PAYLOAD;
            STREAM_PAYLOAD: begin
                if (s_axis_tvalid && tlp_payload_tready) begin
                    if ((chunk_bytes_remaining <= BYTES_PER_BEAT) || s_axis_tlast) begin
                        if (bytes_remaining <= BYTES_PER_BEAT || s_axis_tlast)
                            state <= DONE;
                        else
                            state <= NEXT_CHUNK;
                    end
                end
            end
            NEXT_CHUNK:  state <= ISSUE_TLP;
            DONE:        state <= IDLE;
            default:     state <= IDLE;
        endcase
    end

    // Datapath registers
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            bytes_remaining       <= '0;
            chunk_bytes_remaining <= '0;
            cur_dst_addr          <= '0;
        end else if (state == ACCEPT) begin
            bytes_remaining <= xfer_len;
            cur_dst_addr    <= dst_addr;
        end else if (state == ISSUE_TLP) begin
            chunk_bytes_remaining <= chunk_len;
        end else if (state == STREAM_PAYLOAD && s_axis_tvalid && tlp_payload_tready) begin
            bytes_remaining <= (bytes_remaining > BYTES_PER_BEAT) ?
                                bytes_remaining - BYTES_PER_BEAT : 32'd0;
            chunk_bytes_remaining <= (chunk_bytes_remaining > BYTES_PER_BEAT) ?
                                      chunk_bytes_remaining - BYTES_PER_BEAT : 32'd0;
            cur_dst_addr    <= cur_dst_addr + BYTES_PER_BEAT;
        end
    end

    // Handshake signals
    assign dispatch_ack   = (state == ACCEPT);
    assign s_axis_tready  = (state == STREAM_PAYLOAD) && tlp_payload_tready;

    // TLP request: Memory Write (type=1 for C2H data payload)
    assign tlp_req_valid   = (state == ISSUE_TLP);
    assign tlp_req_type    = 3'd1;  // MWr
    assign tlp_req_addr    = cur_dst_addr;
    assign tlp_req_len     = chunk_len;
    assign tlp_req_tag     = 10'd0;

    // Streaming payload assignment (direct path)
    assign tlp_payload_tdata  = s_axis_tdata;
    assign tlp_payload_tvalid = s_axis_tvalid && (state == STREAM_PAYLOAD);
    assign tlp_payload_tlast  = (state == STREAM_PAYLOAD) && ((chunk_bytes_remaining <= BYTES_PER_BEAT) || s_axis_tlast);

    assign xfer_done  = (state == DONE);
    assign xfer_error = 1'b0;

endmodule

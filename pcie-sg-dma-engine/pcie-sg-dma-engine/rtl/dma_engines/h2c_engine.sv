//==============================================================================
// h2c_engine.sv
// Host-to-Card DMA engine. Issues Memory Read TLPs (via tlp_generator.sv) to
// fetch data from the host source buffer (descriptor's src_addr), receives
// Completion TLPs (via tlp_parser.sv), and streams the data out on an
// AXI4-Stream sink toward FPGA-side consumer logic (e.g. into BRAM).
//
// Upgraded to support Multi-Beat completions and user-side backpressure via
// an internal synchronous elastic FIFO buffer.
//==============================================================================
module h2c_engine #(
    parameter int AXIS_WIDTH = 256,
    parameter int MAX_READ_REQ_BYTES = 512   // Max Read Request Size (MRRS)
)(
    input  logic          clk,
    input  logic          rst_n,

    input  logic          dispatch_valid,
    input  logic [63:0]   src_addr,
    input  logic [31:0]   xfer_len,
    output logic          dispatch_ack,
    output logic          xfer_done,
    output logic          xfer_error,

    // Request interface into tlp_req_arbiter -> tlp_generator (Memory Read requests)
    output logic          tlp_req_valid,
    output logic [2:0]    tlp_req_type,
    output logic [63:0]   tlp_req_addr,
    output logic [31:0]   tlp_req_len,
    output logic [9:0]    tlp_req_tag,
    output logic [AXIS_WIDTH-1:0] tlp_req_payload,
    input  logic          tlp_req_ack,

    // Completion data from tlp_parser.sv
    input  logic          cpld_valid,
    input  logic [9:0]    cpld_tag,
    input  logic [AXIS_WIDTH-1:0] cpld_data,
    input  logic          cpld_last,
    input  logic          cpld_malformed,

    // AXI4-Stream sink (data delivered to FPGA-side consumer)
    output logic [AXIS_WIDTH-1:0] m_axis_tdata,
    output logic          m_axis_tvalid,
    output logic          m_axis_tlast,
    input  logic          m_axis_tready
);

    typedef enum logic [2:0] {
        IDLE, ACCEPT, ISSUE_RD_REQ, WAIT_CPLD, NEXT_REQ, DONE_PENDING, DONE, ERROR
    } h2c_state_t;

    h2c_state_t state;

    logic [31:0] bytes_remaining;
    logic [63:0] cur_src_addr;
    logic [9:0]  cur_tag;
    logic [31:0] req_chunk_len;

    // How many bytes to request this round
    assign req_chunk_len = (bytes_remaining > MAX_READ_REQ_BYTES) ?
                            MAX_READ_REQ_BYTES[31:0] : bytes_remaining;

    // --------------------------------------------------------------------------
    // Synchronous FIFO Buffer (Elastic buffer for backpressure support)
    // --------------------------------------------------------------------------
    localparam int FIFO_DEPTH = 32;
    logic [AXIS_WIDTH:0] fifo_mem [FIFO_DEPTH-1:0]; // width = AXIS_WIDTH + 1 (for tlast)
    logic [4:0] fifo_wr_ptr;
    logic [4:0] fifo_rd_ptr;
    logic [5:0] fifo_count;

    logic fifo_full;
    logic fifo_empty;
    assign fifo_full  = (fifo_count == FIFO_DEPTH[5:0]);
    assign fifo_empty = (fifo_count == 6'd0);

    logic cpld_match;
    assign cpld_match = cpld_valid && (cpld_tag == cur_tag);

    // FIFO Write Path
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            fifo_wr_ptr <= '0;
        end else if (cpld_match && !fifo_full) begin
            fifo_mem[fifo_wr_ptr] <= {cpld_last && (bytes_remaining <= MAX_READ_REQ_BYTES), cpld_data};
            if (fifo_wr_ptr == (FIFO_DEPTH[4:0] - 1'b1))
                fifo_wr_ptr <= '0;
            else
                fifo_wr_ptr <= fifo_wr_ptr + 1'b1;
        end
    end

    // FIFO Read Path
    logic fifo_read_en;
    assign fifo_read_en = m_axis_tvalid && m_axis_tready;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            fifo_rd_ptr <= '0;
        end else if (fifo_read_en) begin
            if (fifo_rd_ptr == (FIFO_DEPTH[4:0] - 1'b1))
                fifo_rd_ptr <= '0;
            else
                fifo_rd_ptr <= fifo_rd_ptr + 1'b1;
        end
    end

    // FIFO Occupancy Counter
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            fifo_count <= '0;
        end else begin
            case ({cpld_match && !fifo_full, fifo_read_en})
                2'b10: fifo_count <= fifo_count + 1'b1;
                2'b01: fifo_count <= fifo_count - 1'b1;
                default: ; // no change
            endcase
        end
    end

    // User AXI-Stream outputs
    assign m_axis_tvalid = !fifo_empty;
    assign m_axis_tdata  = fifo_mem[fifo_rd_ptr][AXIS_WIDTH-1:0];
    assign m_axis_tlast  = fifo_mem[fifo_rd_ptr][AXIS_WIDTH];

    // --------------------------------------------------------------------------
    // FSM Control Path
    // --------------------------------------------------------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= IDLE;
        end else case (state)
            IDLE:         if (dispatch_valid) state <= ACCEPT;
            ACCEPT:       state <= ISSUE_RD_REQ;
            ISSUE_RD_REQ: if (tlp_req_ack) state <= WAIT_CPLD;
            WAIT_CPLD: begin
                if (cpld_match && cpld_last && !fifo_full) begin
                    if (bytes_remaining <= MAX_READ_REQ_BYTES)
                        state <= DONE_PENDING;
                    else
                        state <= NEXT_REQ;
                end else if (cpld_malformed) begin
                    state <= ERROR;
                end
            end
            NEXT_REQ:     state <= ISSUE_RD_REQ;
            // Wait for user side to completely drain the buffered completion beats
            DONE_PENDING: if (fifo_empty) state <= DONE;
            DONE:         state <= IDLE;
            ERROR:        state <= IDLE;
            default:      state <= IDLE;
        endcase
    end

    // Datapath registers
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            bytes_remaining <= '0;
            cur_src_addr    <= '0;
            cur_tag         <= '0;
        end else if (state == ACCEPT) begin
            bytes_remaining <= xfer_len;
            cur_src_addr    <= src_addr;
            cur_tag         <= 10'd0;
        end else if (state == NEXT_REQ) begin
            cur_tag <= cur_tag + 1'b1;
        end else if (state == WAIT_CPLD && cpld_match && cpld_last && !fifo_full) begin
            bytes_remaining <= (bytes_remaining > MAX_READ_REQ_BYTES) ?
                               bytes_remaining - MAX_READ_REQ_BYTES : 32'd0;
            cur_src_addr    <= cur_src_addr + MAX_READ_REQ_BYTES;
        end
    end

    assign dispatch_ack  = (state == ACCEPT);

    // TLP request: Memory Read (type=0)
    assign tlp_req_valid   = (state == ISSUE_RD_REQ);
    assign tlp_req_type    = 3'd0;  // MRd
    assign tlp_req_addr    = cur_src_addr;
    assign tlp_req_len     = req_chunk_len;
    assign tlp_req_tag     = cur_tag;
    assign tlp_req_payload = '0;

    assign xfer_done  = (state == DONE);
    assign xfer_error = (state == ERROR);

endmodule

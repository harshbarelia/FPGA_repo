//==============================================================================
// desc_fetch.sv
// Descriptor fetch FSM: IDLE -> FETCH -> WAIT_FETCH_DATA -> DECODE -> DISPATCH
// -> WAIT_XFER -> WRITEBACK -> WAIT_WB -> ADVANCE_EXTRACT.
//
// This module owns the control flow. It does NOT do the actual AXI/TLP
// transfer -- it hands off a decoded descriptor to c2h_engine or h2c_engine
// via dispatch_valid/dispatch_* signals, then waits for xfer_done before
// moving to WRITEBACK.
//==============================================================================
module desc_fetch #(
    parameter int RING_DEPTH   = 128,
    parameter int PTR_WIDTH    = $clog2(RING_DEPTH) + 1,
    parameter int MAX_XFER_LEN = 32'h0400_0000
)(
    input  logic                   clk,
    input  logic                   rst_n,

    // Descriptor ring base address from register block
    input  logic [63:0]            desc_base_addr,

    // From ring manager
    input  logic                   extract_valid,
    input  logic [PTR_WIDTH-1:0]   extract_ptr,
    output logic                   extract_ptr_update,
    output logic                   extract_valid_req,

    // Descriptor read interface (to TLP generator for host memory read)
    output logic                   desc_rd_req,
    output logic [63:0]            desc_rd_addr,
    input  logic                   desc_rd_valid,
    input  logic [255:0]           desc_rd_data,

    // Decoded descriptor fields
    output logic [63:0]            desc_src_addr,
    output logic [63:0]            desc_dst_addr,
    output logic [31:0]            desc_len,
    output logic                   desc_dir,
    output logic                   desc_irq_en,
    output logic                   decode_error,

    // Dispatch to c2h_engine / h2c_engine
    output logic                   dispatch_valid,
    input  logic                   dispatch_ack,
    input  logic                   xfer_done,
    input  logic                   xfer_error,

    // Writeback trigger to desc_completion.sv
    output logic                   writeback_req,
    input  logic                   writeback_done,

    output logic [3:0]             state_dbg
);

    typedef enum logic [3:0] {
        IDLE            = 4'd0,
        FETCH           = 4'd1,
        WAIT_FETCH_DATA = 4'd2,
        DECODE          = 4'd3,
        DISPATCH        = 4'd4,
        WAIT_XFER       = 4'd5,
        WRITEBACK       = 4'd6,
        WAIT_WB         = 4'd7,
        ADVANCE_EXTRACT = 4'd8
    } state_t;

    state_t state, state_n;

    logic [255:0] desc_raw;

    assign state_dbg = state;

    //--------------------------------------------------------------------------
    // extract_valid_req: tells ring_mgr we want to check for a descriptor.
    // Asserted when we're idle or ready for the next descriptor.
    //--------------------------------------------------------------------------
    assign extract_valid_req = (state == IDLE) || (state == ADVANCE_EXTRACT);

    //--------------------------------------------------------------------------
    // State register
    //--------------------------------------------------------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            state <= IDLE;
        else
            state <= state_n;
    end

    //--------------------------------------------------------------------------
    // Next-state logic
    //--------------------------------------------------------------------------
    always_comb begin
        state_n = state;
        unique case (state)
            IDLE:            if (extract_valid)      state_n = FETCH;
            // FETCH asserts desc_rd_req for one cycle, then unconditionally
            // moves to WAIT_FETCH_DATA. The external memory/TLP subsystem
            // latches the request on seeing desc_rd_req high.
            FETCH:                                   state_n = WAIT_FETCH_DATA;
            WAIT_FETCH_DATA: if (desc_rd_valid)      state_n = DECODE;
            DECODE:                                  state_n = DISPATCH;
            DISPATCH:        if (decode_error)       state_n = WRITEBACK;
                             else if (dispatch_ack)  state_n = WAIT_XFER;
            WAIT_XFER:       if (xfer_done || xfer_error) state_n = WRITEBACK;
            WRITEBACK:                               state_n = WAIT_WB;
            WAIT_WB:         if (writeback_done)     state_n = ADVANCE_EXTRACT;
            ADVANCE_EXTRACT:                         state_n = IDLE;
            default:                                 state_n = IDLE;
        endcase
    end

    //--------------------------------------------------------------------------
    // Descriptor read request: asserted for exactly one cycle in FETCH state
    //--------------------------------------------------------------------------
    assign desc_rd_req  = (state == FETCH);
    assign desc_rd_addr = desc_base_addr + ({48'd0, extract_ptr[PTR_WIDTH-2:0]} * 32);

    //--------------------------------------------------------------------------
    // Raw descriptor capture
    //--------------------------------------------------------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            desc_raw <= '0;
        else if (state == WAIT_FETCH_DATA && desc_rd_valid)
            desc_raw <= desc_rd_data;
    end

    //--------------------------------------------------------------------------
    // Decode + validation
    // Descriptor layout (per interface_spec.md):
    //   [63:0]    src_addr
    //   [127:64]  dst_addr
    //   [159:128] length
    //   [160]     dir       (0=H2C, 1=C2H)
    //   [161]     reserved
    //   [162]     irq_en
    //--------------------------------------------------------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            desc_src_addr <= '0;
            desc_dst_addr <= '0;
            desc_len      <= '0;
            desc_dir      <= 1'b0;
            desc_irq_en   <= 1'b0;
            decode_error  <= 1'b0;
        end else if (state == DECODE) begin
            desc_src_addr <= desc_raw[63:0];
            desc_dst_addr <= desc_raw[127:64];
            desc_len      <= desc_raw[159:128];
            desc_dir      <= desc_raw[160];
            desc_irq_en   <= desc_raw[162];
            // Validation: zero length, oversized, or misaligned src/dst address
            decode_error  <= (desc_raw[159:128] == 32'd0) ||
                             (desc_raw[159:128] > MAX_XFER_LEN) ||
                             (desc_raw[1:0] != 2'b00) ||
                             (desc_raw[65:64] != 2'b00);
        end else if (state == IDLE) begin
            // Clear decode_error when returning to IDLE so stale flags
            // don't leak into the next descriptor's processing.
            decode_error <= 1'b0;
        end
    end

    //--------------------------------------------------------------------------
    // Dispatch / writeback / pointer advance
    //--------------------------------------------------------------------------
    assign dispatch_valid      = (state == DISPATCH) && !decode_error;
    assign writeback_req       = (state == WRITEBACK);
    assign extract_ptr_update  = (state == ADVANCE_EXTRACT);

endmodule
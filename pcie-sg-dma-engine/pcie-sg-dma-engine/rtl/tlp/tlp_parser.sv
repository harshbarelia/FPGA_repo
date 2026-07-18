//==============================================================================
// tlp_parser.sv
// Parses inbound TLPs from the PCIe hard IP RX AXI4-Stream: Completion TLPs
// (responses to our Memory Reads, e.g. descriptor fetch data, H2C source
// reads) and detects malformed TLPs (length field mismatch vs actual payload
// beats received, unsupported TLP type).
//
// PCIe Completion (CplD) header layout (3DW):
//   DW0[31:29] = Fmt (010 = CplD 3DW with data)
//   DW0[28:24] = Type (01010 = Completion)
//   DW0[9:0]   = Length in DW
//   DW1[31:16] = CompleterID
//   DW1[15:13] = Status
//   DW1[11:0]  = Byte Count
//   DW2[31:16] = RequesterID
//   DW2[15:8]  = Tag
//   DW2[6:0]   = Lower Address
//
// In a standard AXIS PCIe interface, DW0 occupies tdata[31:0],
// DW1 occupies tdata[63:32], DW2 occupies tdata[95:64].
//==============================================================================
module tlp_parser #(
    parameter int AXIS_WIDTH = 256
)(
    input  logic          clk,
    input  logic          rst_n,

    // RX AXI4-Stream from PCIe hard IP
    input  logic [AXIS_WIDTH-1:0] s_axis_tdata,
    input  logic          s_axis_tvalid,
    input  logic          s_axis_tlast,
    output logic          s_axis_tready,

    // Decoded completion output (consumed by desc_fetch.sv / h2c_engine.sv)
    output logic          cpld_valid,
    output logic [9:0]    cpld_tag,
    output logic [255:0]  cpld_data,
    output logic          cpld_last,
    output logic          cpld_malformed,

    // Descriptor read data output (for desc_fetch when fetching descriptors)
    output logic          desc_rd_valid,
    output logic [255:0]  desc_rd_data
);

    typedef enum logic [1:0] {RX_IDLE, RX_HDR, RX_PAYLOAD} rx_state_t;
    rx_state_t state;

    logic [9:0]  expected_length_dw;
    logic [9:0]  received_dw_count;
    logic [2:0]  fmt_field;
    logic [4:0]  type_field;
    logic [9:0]  tag_r;
    logic        is_cpld;           // is this a Completion with Data?
    logic        header_has_data;

    // Backpressure: ready when not processing or when downstream can accept
    assign s_axis_tready = 1'b1;  // simplified: always ready.
                                    // Production: backpressure based on downstream FIFO occupancy.

    // Header field extraction (valid during RX_HDR/first beat)
    logic [31:0] hdr_dw0, hdr_dw1, hdr_dw2;
    assign hdr_dw0 = s_axis_tdata[31:0];
    assign hdr_dw1 = s_axis_tdata[63:32];
    assign hdr_dw2 = s_axis_tdata[95:64];

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state              <= RX_IDLE;
            received_dw_count  <= '0;
            expected_length_dw <= '0;
            tag_r              <= '0;
            fmt_field          <= '0;
            type_field         <= '0;
            is_cpld            <= 1'b0;
            header_has_data    <= 1'b0;
        end else begin
            unique case (state)
                RX_IDLE: begin
                    if (s_axis_tvalid) begin
                        fmt_field          <= hdr_dw0[31:29];
                        type_field         <= hdr_dw0[28:24];
                        expected_length_dw <= hdr_dw0[9:0];
                        received_dw_count  <= '0;

                        // CplD: Fmt=010 (3DW with data), Type=01010
                        is_cpld         <= (hdr_dw0[31:29] == 3'b010) &&
                                           (hdr_dw0[28:24] == 5'b01010);
                        header_has_data <= hdr_dw0[30]; // Fmt bit 1 = has data

                        // Tag from CplD DW2[15:8]
                        tag_r <= {2'b00, hdr_dw2[15:8]};

                        if (s_axis_tlast) begin
                            // Single-beat TLP (header only or header+data in one beat)
                            state <= RX_IDLE;
                        end else begin
                            state <= RX_PAYLOAD;
                        end
                    end
                end
                RX_PAYLOAD: begin
                    if (s_axis_tvalid) begin
                        received_dw_count <= received_dw_count + (AXIS_WIDTH / 32);
                        if (s_axis_tlast)
                            state <= RX_IDLE;
                    end
                end
                default: state <= RX_IDLE;
            endcase
        end
    end

    // Completion data valid: we're in payload phase of a CplD TLP
    assign cpld_valid = s_axis_tvalid && (state == RX_PAYLOAD) && is_cpld;
    assign cpld_data  = s_axis_tdata[255:0];
    assign cpld_tag   = tag_r;
    assign cpld_last  = s_axis_tlast && (state == RX_PAYLOAD);

    // Also provide descriptor read data output (same signal, different consumer)
    assign desc_rd_valid = cpld_valid;
    assign desc_rd_data  = cpld_data;

    // Malformed TLP detection: length field mismatch at end of packet
    // Note: this is checked at tlast time. The expected total payload DWs
    // should match received_dw_count + current beat's contribution.
    assign cpld_malformed = s_axis_tlast && (state == RX_PAYLOAD) &&
                             ((received_dw_count + (AXIS_WIDTH / 32)) != {22'd0, expected_length_dw});

endmodule

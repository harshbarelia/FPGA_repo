//==============================================================================
// axi4_stream_bridge.sv
// Width/clock adaptation between the core-clock-domain AXI4-Stream consumer
// logic (BRAM interface, capture pipeline) and the PCIe hard IP's native
// AXI4-Stream width/clock. Instantiates async_fifo.sv for the CDC crossing
// and a width converter if AXIS widths differ.
//==============================================================================
module axi4_stream_bridge #(
    parameter int CORE_AXIS_WIDTH = 256,
    parameter int PCIE_AXIS_WIDTH = 256,   // set equal if no width conversion needed
    parameter int FIFO_ADDR_WIDTH = 5       // 32-deep CDC buffer
)(
    input  logic          core_clk,
    input  logic          core_rst_n,
    input  logic [CORE_AXIS_WIDTH-1:0] core_tdata,
    input  logic          core_tvalid,
    input  logic          core_tlast,
    output logic          core_tready,

    input  logic          pcie_clk,
    input  logic          pcie_rst_n,
    output logic [PCIE_AXIS_WIDTH-1:0] pcie_tdata,
    output logic          pcie_tvalid,
    output logic          pcie_tlast,
    input  logic          pcie_tready
);

    // NOTE: width conversion (CORE_AXIS_WIDTH != PCIE_AXIS_WIDTH) is NOT
    // implemented in this stub -- if your core datapath and PCIe hard IP
    // widths differ, insert a proper AXI4-Stream width converter (packing/
    // unpacking beats) BEFORE or AFTER this CDC stage, not combined with it.
    // Combining width conversion and CDC in one module is a common source
    // of subtle bugs (partial-beat handling across the clock boundary);
    // keep them as separate, separately-testable blocks.

    generate
        if (CORE_AXIS_WIDTH != PCIE_AXIS_WIDTH) begin : g_width_mismatch
            // synthesis translate_off
            initial $error("axi4_stream_bridge: width conversion not implemented, CORE_AXIS_WIDTH must equal PCIE_AXIS_WIDTH in this version");
            // synthesis translate_on
        end
    endgenerate

    localparam PACKED_WIDTH = CORE_AXIS_WIDTH + 1; // +1 for tlast, packed through the async FIFO

    logic fifo_wr_en, fifo_rd_en, fifo_full, fifo_empty;
    logic [PACKED_WIDTH-1:0] fifo_wr_data, fifo_rd_data;

    assign fifo_wr_data = {core_tlast, core_tdata};
    assign fifo_wr_en   = core_tvalid && !fifo_full;
    assign core_tready  = !fifo_full;

    async_fifo #(
        .DATA_WIDTH(PACKED_WIDTH),
        .ADDR_WIDTH(FIFO_ADDR_WIDTH)
    ) u_cdc_fifo (
        .wr_clk   (core_clk),
        .wr_rst_n (core_rst_n),
        .wr_en    (fifo_wr_en),
        .wr_data  (fifo_wr_data),
        .wr_full  (fifo_full),

        .rd_clk   (pcie_clk),
        .rd_rst_n (pcie_rst_n),
        .rd_en    (fifo_rd_en),
        .rd_data  (fifo_rd_data),
        .rd_empty (fifo_empty)
    );

    assign fifo_rd_en   = !fifo_empty && pcie_tready;
    assign pcie_tvalid  = !fifo_empty;
    assign pcie_tlast   = fifo_rd_data[PACKED_WIDTH-1];
    assign pcie_tdata   = fifo_rd_data[PCIE_AXIS_WIDTH-1:0];

endmodule

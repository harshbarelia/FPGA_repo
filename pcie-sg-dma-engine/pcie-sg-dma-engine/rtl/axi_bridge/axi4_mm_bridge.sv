//==============================================================================
// axi4_mm_bridge.sv
// AXI4 memory-mapped bridge exposing the DMA engine's BAR-mapped register
// space (insert/extract pointers, descriptor base addr, WB_INTR_TIMEOUT,
// MSI-X table access) to an AXI4-Lite master (e.g. from an embedded soft
// CPU, or driven by the PCIe hard IP's config/BAR access path).
//
// AXI4-Lite compliance: AW and W channels are handled independently.
// The bridge accepts each channel as soon as it arrives and waits for both
// before performing the write. This matches the AXI4-Lite specification
// which allows AW and W to arrive in any order.
//==============================================================================
module axi4_mm_bridge #(
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32
)(
    input  logic          clk,
    input  logic          rst_n,

    // AXI4-Lite slave interface
    input  logic [ADDR_WIDTH-1:0] s_axi_awaddr,
    input  logic          s_axi_awvalid,
    output logic          s_axi_awready,
    input  logic [DATA_WIDTH-1:0] s_axi_wdata,
    input  logic          s_axi_wvalid,
    output logic          s_axi_wready,
    output logic [1:0]    s_axi_bresp,
    output logic          s_axi_bvalid,
    input  logic          s_axi_bready,

    input  logic [ADDR_WIDTH-1:0] s_axi_araddr,
    input  logic          s_axi_arvalid,
    output logic          s_axi_arready,
    output logic [DATA_WIDTH-1:0] s_axi_rdata,
    output logic [1:0]    s_axi_rresp,
    output logic          s_axi_rvalid,
    input  logic          s_axi_rready,

    // Register outputs to internal blocks
    output logic [63:0]   reg_desc_ring_base,
    output logic [31:0]   reg_wb_intr_timeout,
    output logic [31:0]   sw_insert_ptr_wr,
    output logic          sw_insert_ptr_wr_en,
    input  logic [31:0]   hw_extract_ptr_rd,

    // MSI-X table register passthrough
    output logic          msix_reg_wr_en,
    output logic [31:0]   msix_reg_wr_addr,
    output logic [31:0]   msix_reg_wr_data,

    // MSI-X table read passthrough
    output logic          msix_reg_rd_en,
    output logic [31:0]   msix_reg_rd_addr,
    input  logic [31:0]   msix_reg_rd_data
);

    // Register offset map (see docs/interface_spec.md for the authoritative table)
    localparam ADDR_DESC_BASE_LO   = 32'h00;
    localparam ADDR_DESC_BASE_HI   = 32'h04;
    localparam ADDR_INSERT_PTR     = 32'h08;
    localparam ADDR_EXTRACT_PTR    = 32'h0C;   // read-only from HW perspective
    localparam ADDR_WB_TIMEOUT     = 32'h10;
    localparam ADDR_MSIX_TABLE_BASE= 32'h1000; // 16B stride per vector, see msix_table.sv

    logic [63:0] desc_ring_base_r;
    logic [31:0] wb_intr_timeout_r;
    logic [31:0] insert_ptr_r;

    // ---- Write path (AXI4-Lite compliant: AW and W can arrive independently) ----
    // Capture AW and W channels independently, perform write when both available
    logic aw_captured, w_captured;
    logic [ADDR_WIDTH-1:0] aw_addr_r;
    logic [DATA_WIDTH-1:0] w_data_r;

    typedef enum logic [1:0] {WR_IDLE, WR_EXECUTE, WR_RESP} wr_state_t;
    wr_state_t wr_state;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            wr_state          <= WR_IDLE;
            aw_captured       <= 1'b0;
            w_captured        <= 1'b0;
            aw_addr_r         <= '0;
            w_data_r          <= '0;
            desc_ring_base_r  <= '0;
            wb_intr_timeout_r <= 32'd256;   // default WB_INTR_TIMEOUT
            insert_ptr_r      <= '0;
            sw_insert_ptr_wr_en <= 1'b0;
            msix_reg_wr_en    <= 1'b0;
        end else begin
            sw_insert_ptr_wr_en <= 1'b0;
            msix_reg_wr_en      <= 1'b0;

            case (wr_state)
                WR_IDLE: begin
                    // Independently capture AW and W channels
                    if (s_axi_awvalid && !aw_captured) begin
                        aw_addr_r   <= s_axi_awaddr;
                        aw_captured <= 1'b1;
                    end
                    if (s_axi_wvalid && !w_captured) begin
                        w_data_r   <= s_axi_wdata;
                        w_captured <= 1'b1;
                    end
                    // Both captured (or arriving simultaneously): execute write
                    if ((aw_captured || s_axi_awvalid) && (w_captured || s_axi_wvalid)) begin
                        // Capture any that haven't been captured yet
                        if (!aw_captured) aw_addr_r <= s_axi_awaddr;
                        if (!w_captured)  w_data_r  <= s_axi_wdata;
                        wr_state <= WR_EXECUTE;
                    end
                end
                WR_EXECUTE: begin
                    unique case (aw_addr_r)
                        ADDR_DESC_BASE_LO: desc_ring_base_r[31:0]  <= w_data_r;
                        ADDR_DESC_BASE_HI: desc_ring_base_r[63:32] <= w_data_r;
                        ADDR_INSERT_PTR: begin
                            insert_ptr_r        <= w_data_r;
                            sw_insert_ptr_wr    <= w_data_r;
                            sw_insert_ptr_wr_en <= 1'b1;
                        end
                        ADDR_WB_TIMEOUT: wb_intr_timeout_r <= w_data_r;
                        default: begin
                            if (aw_addr_r >= ADDR_MSIX_TABLE_BASE) begin
                                msix_reg_wr_en   <= 1'b1;
                                msix_reg_wr_addr <= aw_addr_r - ADDR_MSIX_TABLE_BASE;
                                msix_reg_wr_data <= w_data_r;
                            end
                        end
                    endcase
                    aw_captured <= 1'b0;
                    w_captured  <= 1'b0;
                    wr_state    <= WR_RESP;
                end
                WR_RESP: begin
                    if (s_axi_bready) wr_state <= WR_IDLE;
                end
            endcase
        end
    end

    assign s_axi_awready = (wr_state == WR_IDLE) && !aw_captured;
    assign s_axi_wready  = (wr_state == WR_IDLE) && !w_captured;
    assign s_axi_bvalid  = (wr_state == WR_RESP);
    assign s_axi_bresp   = 2'b00;  // OKAY

    assign reg_desc_ring_base  = desc_ring_base_r;
    assign reg_wb_intr_timeout = wb_intr_timeout_r;

    // ---- Read path ----
    typedef enum logic [1:0] {RD_IDLE, RD_READ, RD_RESP} rd_state_t;
    rd_state_t rd_state;
    logic [31:0] rdata_r;
    logic [ADDR_WIDTH-1:0] rd_addr_r;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rd_state       <= RD_IDLE;
            rdata_r        <= '0;
            rd_addr_r      <= '0;
            msix_reg_rd_en <= 1'b0;
        end else begin
            msix_reg_rd_en <= 1'b0;
            case (rd_state)
                RD_IDLE: begin
                    if (s_axi_arvalid) begin
                        rd_addr_r <= s_axi_araddr;
                        rd_state  <= RD_READ;
                    end
                end
                RD_READ: begin
                    unique case (rd_addr_r)
                        ADDR_DESC_BASE_LO: rdata_r <= desc_ring_base_r[31:0];
                        ADDR_DESC_BASE_HI: rdata_r <= desc_ring_base_r[63:32];
                        ADDR_INSERT_PTR:   rdata_r <= insert_ptr_r;         // readback insert ptr
                        ADDR_EXTRACT_PTR:  rdata_r <= hw_extract_ptr_rd;
                        ADDR_WB_TIMEOUT:   rdata_r <= wb_intr_timeout_r;
                        default: begin
                            if (rd_addr_r >= ADDR_MSIX_TABLE_BASE) begin
                                msix_reg_rd_en   <= 1'b1;
                                msix_reg_rd_addr <= rd_addr_r - ADDR_MSIX_TABLE_BASE;
                                rdata_r          <= msix_reg_rd_data;
                            end else begin
                                rdata_r <= 32'hDEAD_BEEF;  // unmapped register
                            end
                        end
                    endcase
                    rd_state <= RD_RESP;
                end
                RD_RESP: if (s_axi_rready) rd_state <= RD_IDLE;
            endcase
        end
    end

    assign s_axi_arready = (rd_state == RD_IDLE);
    assign s_axi_rvalid  = (rd_state == RD_RESP);
    assign s_axi_rdata   = rdata_r;
    assign s_axi_rresp   = 2'b00;  // OKAY

endmodule

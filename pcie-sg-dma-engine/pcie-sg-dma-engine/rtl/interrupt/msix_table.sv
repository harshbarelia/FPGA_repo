//==============================================================================
// msix_table.sv
// MSI-X vector table + PBA (Pending Bit Array), memory-mapped per PCIe MSI-X
// capability structure spec. Table entries: {Message Addr Lo, Message Addr Hi,
// Message Data, Vector Control}. This is a minimal single-vector-table
// implementation -- extend NUM_VECTORS for multi-queue designs.
//==============================================================================
module msix_table #(
    parameter int NUM_VECTORS = 8
)(
    input  logic         clk,
    input  logic          rst_n,

    // BAR-mapped register access (from axi4_mm_bridge.sv)
    input  logic          reg_wr_en,
    input  logic [31:0]   reg_wr_addr,   // byte offset into table (16B per entry)
    input  logic [31:0]   reg_wr_data,
    input  logic          reg_rd_en,
    input  logic [31:0]   reg_rd_addr,
    output logic [31:0]   reg_rd_data,

    // Fire request from msix_ctrl.sv
    input  logic          msix_fire,
    input  logic [7:0]    msix_vector_sel,

    // Outbound MSI-X memory write (TLP) -- goes through tlp_generator.sv
    output logic          msix_wr_req,
    output logic [63:0]   msix_wr_addr,
    output logic [31:0]   msix_wr_data,
    input  logic          msix_wr_ack
);

    typedef struct packed {
        logic [31:0] addr_lo;
        logic [31:0] addr_hi;
        logic [31:0] msg_data;
        logic [31:0] vector_ctrl;   // bit0 = mask
    } msix_entry_t;

    msix_entry_t table_mem [0:NUM_VECTORS-1];
    logic [NUM_VECTORS-1:0] pba;   // pending bit array, for masked vectors

    typedef enum logic [1:0] {MX_IDLE, MX_ISSUE, MX_WAIT} mx_state_t;
    mx_state_t state;

    // ---- Register access (simplified word-addressed, 4 words per entry) ----
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (int i = 0; i < NUM_VECTORS; i++) table_mem[i] <= '0;
        end else if (reg_wr_en) begin
            unique case (reg_wr_addr[3:2])
                2'd0: table_mem[reg_wr_addr[31:4]].addr_lo    <= reg_wr_data;
                2'd1: table_mem[reg_wr_addr[31:4]].addr_hi    <= reg_wr_data;
                2'd2: table_mem[reg_wr_addr[31:4]].msg_data   <= reg_wr_data;
                2'd3: table_mem[reg_wr_addr[31:4]].vector_ctrl<= reg_wr_data;
            endcase
        end
    end

    always_comb begin
        unique case (reg_rd_addr[3:2])
            2'd0: reg_rd_data = table_mem[reg_rd_addr[31:4]].addr_lo;
            2'd1: reg_rd_data = table_mem[reg_rd_addr[31:4]].addr_hi;
            2'd2: reg_rd_data = table_mem[reg_rd_addr[31:4]].msg_data;
            2'd3: reg_rd_data = table_mem[reg_rd_addr[31:4]].vector_ctrl;
            default: reg_rd_data = 32'h0;
        endcase
    end

    // ---- Fire sequence: if masked, set PBA bit instead of firing ----
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= MX_IDLE;
            pba   <= '0;
        end else case (state)
            MX_IDLE:
                if (msix_fire) begin
                    if (table_mem[msix_vector_sel].vector_ctrl[0]) begin
                        pba[msix_vector_sel] <= 1'b1;   // masked: latch pending, do not send
                    end else begin
                        state <= MX_ISSUE;
                    end
                end
            MX_ISSUE: state <= MX_WAIT;
            MX_WAIT:  if (msix_wr_ack) state <= MX_IDLE;
            default:  state <= MX_IDLE;
        endcase
    end

    assign msix_wr_req  = (state == MX_ISSUE);
    assign msix_wr_addr = {table_mem[msix_vector_sel].addr_hi, table_mem[msix_vector_sel].addr_lo};
    assign msix_wr_data = table_mem[msix_vector_sel].msg_data;

endmodule

// -----------------------------------------------------------------------------
// symbol_table.sv
// Maps ITCH 5.0 Stock Locate codes to compact internal symbol_id values.
// Write port driven by market_message_decoder.sv on 'R' messages.
// -----------------------------------------------------------------------------

module symbol_table #(
    parameter int NUM_SYMBOLS   = 1024,
    parameter int SYMBOL_ID_W   = 16,
    parameter int ADDR_W        = $clog2(NUM_SYMBOLS)
)(
    input  logic                      clk,
    input  logic                      rst_n,
    input  logic                      wr_en,
    input  logic [15:0]               wr_stock_locate,
    input  logic [63:0]               wr_stock8,
    output logic [SYMBOL_ID_W-1:0]    wr_assigned_symbol_id,
    input  logic                      rd_req,
    input  logic [15:0]               rd_stock_locate,
    output logic                      rd_hit,
    output logic [SYMBOL_ID_W-1:0]    rd_symbol_id
);

  logic                    valid_mem   [NUM_SYMBOLS];
  logic [63:0]             stock8_mem  [NUM_SYMBOLS];
  logic [SYMBOL_ID_W-1:0]  symbol_id_mem [NUM_SYMBOLS];
  logic [SYMBOL_ID_W-1:0] next_symbol_id;
  wire [ADDR_W-1:0] wr_addr = wr_stock_locate[ADDR_W-1:0];
  wire [ADDR_W-1:0] rd_addr = rd_stock_locate[ADDR_W-1:0];
  integer i;

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      for (i = 0; i < NUM_SYMBOLS; i++) valid_mem[i] = 1'b0;
      next_symbol_id <= {SYMBOL_ID_W{1'b0}} + 1'b1;
      wr_assigned_symbol_id <= '0;
    end else begin
      if (wr_en) begin
        if (!valid_mem[wr_addr]) begin
          valid_mem[wr_addr]     <= 1'b1;
          stock8_mem[wr_addr]    <= wr_stock8;
          symbol_id_mem[wr_addr] <= next_symbol_id;
          wr_assigned_symbol_id  <= next_symbol_id;
          next_symbol_id          <= next_symbol_id + 1'b1;
        end else begin
          stock8_mem[wr_addr]   <= wr_stock8;
          wr_assigned_symbol_id <= symbol_id_mem[wr_addr];
        end
      end
    end
  end

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      rd_hit      <= 1'b0;
      rd_symbol_id <= '0;
    end else begin
      rd_hit       <= rd_req & valid_mem[rd_addr];
      rd_symbol_id <= valid_mem[rd_addr] ? symbol_id_mem[rd_addr] : '0;
    end
  end

  a_no_zero_symbol_id: assert property (
    @(posedge clk) disable iff (!rst_n)
    (wr_en && !valid_mem[wr_addr]) |=> (wr_assigned_symbol_id != '0))
  else $error("symbol_table assigned reserved symbol_id 0");

  a_hit_implies_nonzero_id: assert property (
    @(posedge clk) disable iff (!rst_n)
    rd_hit |-> (rd_symbol_id != '0))
  else $error("symbol_table hit returned symbol_id 0");

endmodule : symbol_table

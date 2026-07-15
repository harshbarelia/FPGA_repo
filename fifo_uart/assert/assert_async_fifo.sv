module assert_async_fifo #(
    parameter int ADDR_W = 4
) (
    input logic wr_clk,
    input logic wr_rst_n,
    input logic wr_en,
    input logic full,
    input logic [ADDR_W:0] wr_ptr_bin,
    input logic [ADDR_W:0] wr_ptr_gray_next,
    input logic [ADDR_W:0] rd_ptr_gray_sync2,

    input logic rd_clk,
    input logic rd_rst_n,
    input logic rd_en,
    input logic empty,
    input logic [ADDR_W:0] rd_ptr_bin,
    input logic [ADDR_W:0] rd_ptr_gray,
    input logic [ADDR_W:0] wr_ptr_gray_sync2
);

    property p_no_write_when_full;
        @(posedge wr_clk) disable iff (!wr_rst_n)
        (wr_en && full) |=> $stable(wr_ptr_bin);
    endproperty
    ap_no_write_when_full: assert property(p_no_write_when_full);

    property p_wr_inc;
        @(posedge wr_clk) disable iff (!wr_rst_n)
        (wr_en && !full) |=> (wr_ptr_bin == $past(wr_ptr_bin) + 1'b1);
    endproperty
    ap_wr_inc: assert property(p_wr_inc);

    property p_no_read_when_empty;
        @(posedge rd_clk) disable iff (!rd_rst_n)
        (rd_en && empty) |=> $stable(rd_ptr_bin);
    endproperty
    ap_no_read_when_empty: assert property(p_no_read_when_empty);

    property p_rd_inc;
        @(posedge rd_clk) disable iff (!rd_rst_n)
        (rd_en && !empty) |=> (rd_ptr_bin == $past(rd_ptr_bin) + 1'b1);
    endproperty
    ap_rd_inc: assert property(p_rd_inc);

    property p_empty_flag;
        @(posedge rd_clk) disable iff (!rd_rst_n)
        empty |-> (wr_ptr_gray_sync2 == rd_ptr_gray);
    endproperty
    ap_empty_flag: assert property(p_empty_flag);

    property p_full_flag;
        @(posedge wr_clk) disable iff (!wr_rst_n)
        full |-> (wr_ptr_gray_next ==
                 {~rd_ptr_gray_sync2[ADDR_W:ADDR_W-1],
                   rd_ptr_gray_sync2[ADDR_W-2:0]});
    endproperty
    ap_full_flag: assert property(p_full_flag);

endmodule

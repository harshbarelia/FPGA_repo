module assert_sync_fifo #(
    parameter int ADDR_W = 4
) (
    input logic clk,
    input logic rst_n,
    input logic wr_en,
    input logic rd_en,
    input logic full,
    input logic empty,
    input logic [ADDR_W:0] wr_ptr,
    input logic [ADDR_W:0] rd_ptr
);

    property p_no_write_when_full;
        @(posedge clk) disable iff (!rst_n)
        (wr_en && full) |=> $stable(wr_ptr);
    endproperty
    ap_no_write_when_full: assert property(p_no_write_when_full);

    property p_no_read_when_empty;
        @(posedge clk) disable iff (!rst_n)
        (rd_en && empty) |=> $stable(rd_ptr);
    endproperty
    ap_no_read_when_empty: assert property(p_no_read_when_empty);

    property p_wr_inc;
        @(posedge clk) disable iff (!rst_n)
        (wr_en && !full) |=> (wr_ptr == $past(wr_ptr) + 1'b1);
    endproperty
    ap_wr_inc: assert property(p_wr_inc);

    property p_rd_inc;
        @(posedge clk) disable iff (!rst_n)
        (rd_en && !empty) |=> (rd_ptr == $past(rd_ptr) + 1'b1);
    endproperty
    ap_rd_inc: assert property(p_rd_inc);

    property p_empty_flag;
        @(posedge clk) disable iff (!rst_n)
        empty |-> (wr_ptr == rd_ptr);
    endproperty
    ap_empty_flag: assert property(p_empty_flag);

    property p_full_flag;
        @(posedge clk) disable iff (!rst_n)
        full |-> (wr_ptr[ADDR_W] != rd_ptr[ADDR_W]) &&
                 (wr_ptr[ADDR_W-1:0] == rd_ptr[ADDR_W-1:0]);
    endproperty
    ap_full_flag: assert property(p_full_flag);

endmodule

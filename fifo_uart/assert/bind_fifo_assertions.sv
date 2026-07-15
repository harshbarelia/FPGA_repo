bind sync_fifo assert_sync_fifo #(
    .ADDR_W(ADDR_W)
) u_assert_sync_fifo (
    .clk   (clk),
    .rst_n (rst_n),
    .wr_en (wr_en),
    .rd_en (rd_en),
    .full  (full),
    .empty (empty),
    .wr_ptr(wr_ptr),
    .rd_ptr(rd_ptr)
);

bind async_fifo assert_async_fifo #(
    .ADDR_W(ADDR_W)
) u_assert_async_fifo (
    .wr_clk           (wr_clk),
    .wr_rst_n         (wr_rst_n),
    .wr_en            (wr_en),
    .full             (full),
    .wr_ptr_bin       (wr_ptr_bin),
    .wr_ptr_gray_next (wr_ptr_gray_next),
    .rd_ptr_gray_sync2(rd_ptr_gray_sync2),
    .rd_clk           (rd_clk),
    .rd_rst_n         (rd_rst_n),
    .rd_en            (rd_en),
    .empty            (empty),
    .rd_ptr_bin       (rd_ptr_bin),
    .rd_ptr_gray      (rd_ptr_gray),
    .wr_ptr_gray_sync2(wr_ptr_gray_sync2)
);

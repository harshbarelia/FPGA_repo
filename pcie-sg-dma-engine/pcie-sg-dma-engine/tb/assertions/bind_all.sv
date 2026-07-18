//==============================================================================
// bind_all.sv
// Single point of truth for all assertion bindings. Never bind inside RTL
// or inline in testbench top -- keep this file as the only place bindings
// happen, so anyone reviewing the repo can find every checker in one spot.
// Include this file in your simulation compile list (not in synthesis).
//
// NOTE: sva_descriptor_invariants needs signals from BOTH desc_ring_mgr
// AND desc_fetch. We bind it at the pcie_dma_top level using hierarchical
// references to pull signals from both submodules.
//==============================================================================

// Bind at pcie_dma_top level to access both ring_mgr and desc_fetch signals
bind pcie_dma_top sva_descriptor_invariants #(
    .RING_DEPTH(RING_DEPTH)
) u_sva_desc (
    .clk(core_clk),
    .rst_n(core_rst_n),
    .insert_ptr(u_ring_mgr.insert_ptr),
    .extract_ptr(u_ring_mgr.extract_ptr),
    .extract_valid(u_ring_mgr.extract_valid),
    .insert_ptr_update_dbg(u_ring_mgr.insert_ptr_update_dbg),
    .extract_ptr_update_dbg(u_ring_mgr.extract_ptr_update_dbg),
    .state_dbg(u_desc_fetch.state_dbg),
    .decode_error(u_desc_fetch.decode_error),
    .xfer_done(xfer_done),
    .writeback_valid(u_desc_fetch.writeback_req),
    .writeback_done(u_desc_completion.writeback_done),
    .desc_addr(u_desc_fetch.desc_rd_addr[31:0]),
    .desc_len(u_desc_fetch.desc_len)
);

bind msix_ctrl sva_msix_protocol u_sva_msix (
    .clk(clk), .rst_n(rst_n),
    .msix_fire(msix_fire),
    .pending_completions(pending_completions),
    .wb_intr_timeout_cfg(wb_intr_timeout_cfg),
    .wb_event_pulse(wb_event_pulse)
);

bind async_fifo sva_gray_code_cdc #(
    .ADDR_WIDTH(ADDR_WIDTH)
) u_sva_gray (
    .wr_clk(wr_clk), .wr_rst_n(wr_rst_n), .wr_en(wr_en),
    .wr_ptr_gray(wr_ptr_gray),
    .rd_clk(rd_clk), .rd_rst_n(rd_rst_n), .rd_en(rd_en),
    .rd_ptr_gray(rd_ptr_gray)
);

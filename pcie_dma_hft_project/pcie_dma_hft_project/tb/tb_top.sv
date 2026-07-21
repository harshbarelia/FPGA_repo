`timescale 1ns/1ps
import uvm_pkg::*;
`include "uvm_macros.svh"

`include "uvm/dma_seq_item.sv"
`include "uvm/dma_sequencer.sv"
`include "uvm/dma_driver.sv"
`include "uvm/dma_monitor.sv"
`include "uvm/dma_coverage.sv"
`include "uvm/dma_scoreboard.sv"
`include "uvm/dma_basic_seq.sv"
`include "uvm/dma_wrap_seq.sv"
`include "uvm/dma_env.sv"
`include "uvm/dma_test.sv"

module tb_top;
    logic clk;
    logic rst_n;

    dma_if dma_vif(.clk(clk), .rst_n(rst_n));

    // Internal inter-module signals
    logic [127:0] desc_pop_data;
    logic         desc_pop_valid;
    logic         desc_pop_ready;

    logic [3:0]   m_axi_awid;
    logic [63:0]  m_axi_awaddr;
    logic [7:0]   m_axi_awlen;
    logic [2:0]   m_axi_awsize;
    logic [1:0]   m_axi_awburst;
    logic         m_axi_awvalid;
    logic         m_axi_awready;

    logic [511:0] m_axi_wdata;
    logic [63:0]  m_axi_wstrb;
    logic         m_axi_wvalid;
    logic         m_axi_wready;
    logic         m_axi_wlast;

    logic [3:0]   m_axi_bid;
    logic [1:0]   m_axi_bresp;
    logic         m_axi_bvalid;
    logic         m_axi_bready;

    // Instantiate Descriptor Ring Buffer
    descriptor_ring_buffer u_ring (
        .clk(clk),
        .rst_n(rst_n),
        .push_valid(dma_vif.push_valid),
        .push_data(dma_vif.push_data),
        .push_ready(dma_vif.push_ready),
        .pop_valid(desc_pop_valid),
        .pop_data(desc_pop_data),
        .pop_ready(desc_pop_ready),
        .wr_ptr(),
        .rd_ptr(),
        .occupancy(),
        .ring_full(),
        .ring_empty(),
        .ring_almost_full(),
        .ring_almost_empty()
    );

    // Instantiate Scatter-Gather DMA Engine
    sg_dma_engine u_dma (
        .clk(clk),
        .rst_n(rst_n),
        .desc_pop_ready(desc_pop_ready),
        .desc_pop_valid(desc_pop_valid),
        .desc_pop_data(desc_pop_data),
        .m_axi_awid(m_axi_awid),
        .m_axi_awaddr(m_axi_awaddr),
        .m_axi_awlen(m_axi_awlen),
        .m_axi_awsize(m_axi_awsize),
        .m_axi_awburst(m_axi_awburst),
        .m_axi_awvalid(m_axi_awvalid),
        .m_axi_awready(m_axi_awready),
        .m_axi_wdata(m_axi_wdata),
        .m_axi_wstrb(m_axi_wstrb),
        .m_axi_wvalid(m_axi_wvalid),
        .m_axi_wready(m_axi_wready),
        .m_axi_wlast(m_axi_wlast),
        .m_axi_bid(m_axi_bid),
        .m_axi_bresp(m_axi_bresp),
        .m_axi_bvalid(m_axi_bvalid),
        .m_axi_bready(m_axi_bready),
        .s_axis_tdata(dma_vif.s_axis_tdata),
        .s_axis_tkeep('1),
        .s_axis_tvalid(dma_vif.s_axis_tvalid),
        .s_axis_tready(dma_vif.s_axis_tready),
        .s_axis_tlast(dma_vif.s_axis_tlast),
        .dma_enable(1'b1),
        .dma_busy(),
        .dma_done_irq(dma_vif.dma_done_irq),
        .dma_completed_count()
    );

    // Bind Assertions Module directly to Ring Buffer
    bind descriptor_ring_buffer sva_assertions u_sva_bind (
        .clk(clk),
        .rst_n(rst_n),
        .push_valid(push_valid),
        .push_ready(push_ready),
        .pop_valid(pop_valid),
        .pop_ready(pop_ready),
        .ring_full(ring_full),
        .ring_empty(ring_empty),
        .wr_ptr(wr_ptr),
        .rd_ptr(rd_ptr)
    );

    // Clock Generation (300 MHz -> 3.333 ns period)
    initial begin
        clk = 0;
        forever #1.666 clk = ~clk;
    end

    // Reset & AXI Slave Memory Responder
    initial begin
        rst_n = 0;
        m_axi_awready = 1'b1;
        m_axi_wready  = 1'b1;
        m_axi_bvalid  = 1'b0;
        m_axi_bresp   = 2'b00;
        m_axi_bid     = 4'b0000;
        repeat (10) @(posedge clk);
        rst_n = 1;
    end

    always @(posedge clk) begin
        if (m_axi_wvalid && m_axi_wready && m_axi_wlast)
            m_axi_bvalid <= 1'b1;
        else if (m_axi_bready)
            m_axi_bvalid <= 1 meb0;
    end

    // UVM Config DB Setup and Test Launcher
    initial begin
        uvm_config_db#(virtual dma_if)::set(null, "*", "dma_vif", dma_vif);
        run_test("dma_test");
    end

endmodule

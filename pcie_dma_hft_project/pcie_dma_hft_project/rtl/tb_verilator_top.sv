// Top Module Wrapper for Verilator Simulation
// Connects Ethernet Parser, Latency Counter, Ring Buffer, and AXI4 Master DMA Engine

module tb_verilator_top (
    input  logic        clk,
    input  logic        rst_n,
    input  logic        dma_enable,
    input  logic [15:0] target_udp_dport,

    // Raw MAC RX AXI-Stream Input
    input  logic [511:0] s_axis_tdata,
    input  logic [63:0]  s_axis_tkeep,
    input  logic         s_axis_tvalid,
    output logic         s_axis_tready,
    input  logic         s_axis_tlast,

    // Interrupt / Status Output
    output logic         dma_done_irq,
    output logic [31:0]  dma_completed_count
);

    logic [64-1:0]  free_run_ts;
    logic [64-1:0]  free_run_ns;

    // Parser Outputs
    logic [511:0]   m_axis_tdata;
    logic [63:0]    m_axis_tkeep;
    logic           m_axis_tvalid;
    logic           m_axis_tready;
    logic           m_axis_tlast;
    logic [63:0]    m_axis_rx_timestamp;
    logic [15:0]    m_axis_udp_dport;

    // Ring Buffer Signals
    logic           push_valid;
    logic [127:0]   push_data;
    logic           push_ready;
    logic           pop_valid;
    logic [127:0]   pop_data;
    logic           pop_ready;

    // AXI4 Signals
    logic [3:0]     m_axi_awid;
    logic [63:0]    m_axi_awaddr;
    logic [7:0]     m_axi_awlen;
    logic [2:0]     m_axi_awsize;
    logic [1:0]     m_axi_awburst;
    logic           m_axi_awvalid;
    logic           m_axi_awready;

    logic [511:0]   m_axi_wdata;
    logic [63:0]    m_axi_wstrb;
    logic           m_axi_wlast;
    logic           m_axi_wvalid;
    logic           m_axi_wready;

    logic [3:0]     m_axi_bid;
    logic [1:0]     m_axi_bresp;
    logic           m_axi_bvalid;
    logic           m_axi_bready;

    // Instantiate Timestamp Counter
    latency_timestamp_unit #(
        .TS_WIDTH(64),
        .CLK_FREQ_MHZ(300)
    ) u_ts (
        .clk(clk),
        .rst_n(rst_n),
        .free_run_ts(free_run_ts),
        .free_run_ns(free_run_ns)
    );

    // Instantiate Ethernet UDP Parser
    eth_udp_parser #(
        .DATA_WIDTH(512),
        .TS_WIDTH(64)
    ) u_parser (
        .clk(clk),
        .rst_n(rst_n),
        .enable_filter(1'b1),
        .target_udp_dport(target_udp_dport),
        .s_axis_tdata(s_axis_tdata),
        .s_axis_tkeep(s_axis_tkeep),
        .s_axis_tvalid(s_axis_tvalid),
        .s_axis_tready(s_axis_tready),
        .s_axis_tlast(s_axis_tlast),
        .free_run_ts(free_run_ts),
        .m_axis_tdata(m_axis_tdata),
        .m_axis_tkeep(m_axis_tkeep),
        .m_axis_tvalid(m_axis_tvalid),
        .m_axis_tready(m_axis_tready),
        .m_axis_tlast(m_axis_tlast),
        .m_axis_rx_timestamp(m_axis_rx_timestamp),
        .m_axis_udp_dport(m_axis_udp_dport),
        .err_ethertype(),
        .err_ipv4_proto(),
        .err_checksum(),
        .pkt_parsed_count()
    );

    // Instantiate Ring Buffer
    descriptor_ring_buffer #(
        .RING_DEPTH(256),
        .DESC_WIDTH(128)
    ) u_ring (
        .clk(clk),
        .rst_n(rst_n),
        .push_valid(push_valid),
        .push_data(push_data),
        .push_ready(push_ready),
        .pop_valid(pop_valid),
        .pop_data(pop_data),
        .pop_ready(pop_ready),
        .wr_ptr(),
        .rd_ptr(),
        .occupancy(),
        .ring_full(),
        .ring_empty(),
        .ring_almost_full(),
        .ring_almost_empty()
    );

    // Instantiate Scatter-Gather DMA Engine
    sg_dma_engine #(
        .ADDR_WIDTH(64),
        .DATA_WIDTH(512),
        .DESC_WIDTH(128)
    ) u_dma (
        .clk(clk),
        .rst_n(rst_n),
        .desc_pop_ready(pop_ready),
        .desc_pop_valid(pop_valid),
        .desc_pop_data(pop_data),
        .m_axi_awid(m_axi_awid),
        .m_axi_awaddr(m_axi_awaddr),
        .m_axi_awlen(m_axi_awlen),
        .m_axi_awsize(m_axi_awsize),
        .m_axi_awburst(m_axi_awburst),
        .m_axi_awvalid(m_axi_awvalid),
        .m_axi_awready(m_axi_awready),
        .m_axi_wdata(m_axi_wdata),
        .m_axi_wstrb(m_axi_wstrb),
        .m_axi_wlast(m_axi_wlast),
        .m_axi_wvalid(m_axi_wvalid),
        .m_axi_wready(m_axi_wready),
        .m_axi_bid(m_axi_bid),
        .m_axi_bresp(m_axi_bresp),
        .m_axi_bvalid(m_axi_bvalid),
        .m_axi_bready(m_axi_bready),
        .s_axis_tdata(m_axis_tdata),
        .s_axis_tkeep(m_axis_tkeep),
        .s_axis_tvalid(m_axis_tvalid),
        .s_axis_tready(m_axis_tready),
        .s_axis_tlast(m_axis_tlast),
        .dma_enable(dma_enable),
        .dma_busy(),
        .dma_done_irq(dma_done_irq),
        .dma_completed_count(dma_completed_count)
    );

    // Simulated Host AXI Memory Slave Logic
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            m_axi_awready <= 1'b1;
            m_axi_wready  <= 1'b1;
            m_axi_bvalid  <= 1'b0;
            m_axi_bresp   <= 2'b00;
            m_axi_bid     <= 4'b0;
        end else begin
            if (m_axi_wvalid && m_axi_wready && m_axi_wlast) begin
                m_axi_bvalid <= 1'b1;
            end else if (m_axi_bready) begin
                m_axi_bvalid <= 1'b0;
            end
        end
    end

    // Auto-push dummy descriptor when ring is empty and DMA enabled
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            push_valid <= 1'b0;
            push_data  <= '0;
        end else begin
            if (dma_enable && push_ready && !push_valid) begin
                push_valid <= 1'b1;
                // Host Addr = 0x8000_0000, Length = 64 Bytes, Control = 0x01
                push_data  <= {64'h0000_0000_8000_0000, 32'd64, 32'h0000_0001};
            end else if (push_valid && push_ready) begin
                push_valid <= 1'b0;
            end
        end
    end

endmodule

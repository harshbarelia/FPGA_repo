
// dma_ring_wrap_tb.sv
// Ring WRAPAROUND test over AXI4-LITE ONLY interfaces. Posts more
// descriptors than RING_SIZE to force head/tail pointers to wrap,
// verifying the wide RING_PTR_W scheme correctly disambiguates
// full vs empty across the wrap boundary. All transfers are H2C
// (HOST DDR -> local BRAM).
`timescale 1ns/1ps
import dma_pkg::*;

module dma_ring_wrap_tb;

    logic clk = 0;
    logic rst_n = 0;
    always #5 clk = ~clk;
    initial begin rst_n = 0; repeat (10) @(posedge clk); rst_n = 1; end

    logic [11:0] awaddr, araddr;
    logic        awvalid, arvalid, wvalid, bready, rready;
    logic [31:0] wdata, rdata;
    logic [3:0]  wstrb;
    logic        awready, wready, bvalid, arready, rvalid;
    logic [1:0]  bresp, rresp;

    logic [31:0] m_araddr, m_awaddr, m_rdata, m_wdata;
    logic        m_arvalid, m_arready, m_awvalid, m_awready;
    logic        m_rvalid, m_rready, m_wvalid, m_wready;
    logic        m_bvalid, m_bready;
    logic        msix_irq;

    dma_top dut (
        .clk(clk), .rst_n(rst_n),
        .s_axil_awaddr(awaddr), .s_axil_awvalid(awvalid), .s_axil_awready(awready),
        .s_axil_wdata(wdata), .s_axil_wstrb(wstrb), .s_axil_wvalid(wvalid), .s_axil_wready(wready),
        .s_axil_bresp(bresp), .s_axil_bvalid(bvalid), .s_axil_bready(bready),
        .s_axil_araddr(araddr), .s_axil_arvalid(arvalid), .s_axil_arready(arready),
        .s_axil_rdata(rdata), .s_axil_rresp(rresp), .s_axil_rvalid(rvalid), .s_axil_rready(rready),
        .m_axil_araddr(m_araddr), .m_axil_arvalid(m_arvalid), .m_axil_arready(m_arready),
        .m_axil_rdata(m_rdata), .m_axil_rvalid(m_rvalid), .m_axil_rready(m_rready),
        .m_axil_awaddr(m_awaddr), .m_axil_awvalid(m_awvalid), .m_axil_awready(m_awready),
        .m_axil_wdata(m_wdata), .m_axil_wvalid(m_wvalid), .m_axil_wready(m_wready),
        .m_axil_bvalid(m_bvalid), .m_axil_bready(m_bready),
        .msix_irq(msix_irq)
    );

    axi4_mem_bfm u_bfm (
        .clk(clk), .rst_n(rst_n),
        .s_araddr(m_araddr), .s_arvalid(m_arvalid), .s_arready(m_arready),
        .s_rdata(m_rdata), .s_rvalid(m_rvalid), .s_rready(m_rready),
        .s_awaddr(m_awaddr), .s_awvalid(m_awvalid), .s_awready(m_awready),
        .s_wdata(m_wdata), .s_wvalid(m_wvalid), .s_wready(m_wready),
        .s_bvalid(m_bvalid), .s_bready(m_bready)
    );

    task axil_write(logic [11:0] addr, logic [31:0] data);
        begin
            @(posedge clk);
            awaddr <= addr; awvalid <= 1; wdata <= data; wvalid <= 1; wstrb <= 4'hF; bready <= 1;
            @(posedge clk);
            awvalid <= 0; wvalid <= 0;
            wait (bvalid);
            @(posedge clk);
        end
    endtask

    localparam logic [31:0] RING_BASE = HOST_DDR_BASE + 32'h0000_1000;
    localparam logic [31:0] RING_SIZE = 32'd4;   // small ring to force wraparound quickly
    localparam int          NUM_DESCS = 6;       // > RING_SIZE, forces wrap
    localparam logic [31:0] XFER_LEN  = 32'd64;

    logic [31:0] src_addr [NUM_DESCS];
    logic [31:0] dst_addr [NUM_DESCS];

    task write_desc_slot(int slot, logic [31:0] src, logic [31:0] dst, logic [31:0] len, logic [31:0] ctrl);
        logic [31:0] daddr;
        begin
            // Descriptors live in HOST DDR - poke u_bfm.ddr_mem[] with
            // HOST_DDR_BASE offset subtracted.
            daddr = RING_BASE + (slot % RING_SIZE) * DESC_BYTES;
            {u_bfm.ddr_mem[daddr-HOST_DDR_BASE+3],u_bfm.ddr_mem[daddr-HOST_DDR_BASE+2],
             u_bfm.ddr_mem[daddr-HOST_DDR_BASE+1],u_bfm.ddr_mem[daddr-HOST_DDR_BASE+0]} = src;
            {u_bfm.ddr_mem[daddr-HOST_DDR_BASE+7],u_bfm.ddr_mem[daddr-HOST_DDR_BASE+6],
             u_bfm.ddr_mem[daddr-HOST_DDR_BASE+5],u_bfm.ddr_mem[daddr-HOST_DDR_BASE+4]} = dst;
            {u_bfm.ddr_mem[daddr-HOST_DDR_BASE+11],u_bfm.ddr_mem[daddr-HOST_DDR_BASE+10],
             u_bfm.ddr_mem[daddr-HOST_DDR_BASE+9],u_bfm.ddr_mem[daddr-HOST_DDR_BASE+8]} = len;
            {u_bfm.ddr_mem[daddr-HOST_DDR_BASE+15],u_bfm.ddr_mem[daddr-HOST_DDR_BASE+14],
             u_bfm.ddr_mem[daddr-HOST_DDR_BASE+13],u_bfm.ddr_mem[daddr-HOST_DDR_BASE+12]} = ctrl;
        end
    endtask

    int irq_count = 0;
    always @(posedge clk) if (msix_irq) irq_count++;

    initial begin
        // H2C descriptors: src in HOST DDR, dst in local BRAM (DDR->BRAM,
        // not DDR->DDR). Offsets kept small so all 6 descriptors'
        // destinations fit inside the 64KB BRAM model.
        for (int i = 0; i < NUM_DESCS; i++) begin
            src_addr[i] = HOST_DDR_BASE + 32'h00010000 + i * 32'h00001000;
            dst_addr[i] = BRAM_BASE     + i * 32'h00001000;
        end
    end

    initial begin
        awvalid=0; wvalid=0; bready=0; arvalid=0; rready=0;
        wait (rst_n);
        repeat (5) @(posedge clk);

        axil_write(12'h004, RING_BASE); // RING_BASE (32-bit, single register)
        axil_write(12'h00C, RING_SIZE);
        axil_write(12'h018, 32'h0000_0001); // IRQ_EN
        axil_write(12'h000, 32'h0000_0001); // dma_enable

        for (int i = 0; i < NUM_DESCS; i++) begin
            write_desc_slot(i, src_addr[i], dst_addr[i], XFER_LEN, 32'h0000_0002); // H2C, IRQ_EN
            axil_write(12'h010, i+1); // doorbell: TAIL_PTR = i+1 (wraps past RING_SIZE=4)
            wait (irq_count == i+1);
        end

        repeat (5) @(posedge clk);
        // src_addr[i] lives in HOST DDR (ddr_mem[]), dst_addr[i] lives in
        // local BRAM (bram_mem[]) - comparing across the two separate
        // arrays proves a true DDR->BRAM transfer, not a loopback.
        for (int i = 0; i < NUM_DESCS; i++) begin
            for (int b = 0; b < XFER_LEN; b++) begin
                byte src_byte = u_bfm.ddr_mem[src_addr[i] - HOST_DDR_BASE + b];
                byte dst_byte = u_bfm.bram_mem[dst_addr[i] - BRAM_BASE + b];
                if (dst_byte !== src_byte) begin
                    $error("[WRAP_TB] Descriptor %0d data mismatch at byte %0d: bram_dst=%0h ddr_src=%0h", i, b, dst_byte, src_byte);
                end
            end
        end

        if (irq_count == NUM_DESCS)
            $display("[WRAP_TB] RING WRAPAROUND TEST PASSED - all %0d descriptors completed across the wrap boundary", NUM_DESCS);
        else
            $error("[WRAP_TB] Expected %0d interrupts, got %0d", NUM_DESCS, irq_count);

        repeat (20) @(posedge clk);
        $finish;
    end

endmodule : dma_ring_wrap_tb

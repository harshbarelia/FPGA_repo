`timescale 1ns/1ps
module tb_eth_ipv4_udp_parser;
  localparam int MSG_BYTES = 64;
  localparam int MSG_W = MSG_BYTES * 8;
  logic clk=0, rst_n=0;
  logic [7:0] s_rx_byte; logic s_rx_valid, s_rx_sof, s_rx_eof, s_rx_ready;
  logic [MSG_W-1:0] m_msg_data; logic [15:0] m_msg_len; logic m_msg_valid, m_msg_ready;
  logic err_invalid_eth, err_invalid_ip, err_invalid_udp, err_oversize;
  eth_ipv4_udp_parser dut(.clk(clk), .rst_n(rst_n), .s_rx_byte(s_rx_byte), .s_rx_valid(s_rx_valid), .s_rx_sof(s_rx_sof), .s_rx_eof(s_rx_eof), .s_rx_ready(s_rx_ready), .m_msg_data(m_msg_data), .m_msg_len(m_msg_len), .m_msg_valid(m_msg_valid), .m_msg_ready(m_msg_ready), .err_invalid_eth(err_invalid_eth), .err_invalid_ip(err_invalid_ip), .err_invalid_udp(err_invalid_udp), .err_oversize(err_oversize));
  always #5 clk=~clk;
  int pass=0, fail=0; task automatic check(string n, logic c); if(c) begin pass++; $display("[PASS] %s", n); end else begin fail++; $error("[FAIL] %s", n); end endtask
  task automatic send_frame(input logic [7:0] bytes[$], input int n); begin for (int i=0; i<n; i++) begin s_rx_byte = bytes[i]; s_rx_valid = 1; s_rx_sof = (i==0); s_rx_eof = (i==n-1); @(posedge clk); end s_rx_valid=0; s_rx_sof=0; s_rx_eof=0; @(posedge clk); end endtask
  logic [7:0] good [$];
  logic [7:0] bad  [$];
  initial begin
    m_msg_ready=0; s_rx_valid=0; s_rx_sof=0; s_rx_eof=0; s_rx_byte=0; rst_n=0; repeat(3) @(posedge clk); rst_n=1; @(posedge clk);
    // 78-byte frame: 14 Eth + 20 IP + 8 UDP + 36-byte ITCH Add Order payload
    // IP total len = 64 (0x40), UDP len = 44 (0x2C)
    good = '{8'h00,8'h11,8'h22,8'h33,8'h44,8'h55,8'h66,8'h77,8'h88,8'h99,8'hAA,8'hBB,8'h08,8'h00,8'h45,8'h00,8'h00,8'h40,8'h00,8'h01,8'h00,8'h00,8'h40,8'h11,8'h00,8'h00,8'h0A,8'h00,8'h00,8'h01,8'h0A,8'h00,8'h00,8'h02,8'h1F,8'h90,8'h1F,8'h90,8'h00,8'h2C,8'h00,8'h00,8'h41,8'h00,8'h01,8'h00,8'h00,8'h00,8'h00,8'h07,8'h5B,8'hCD,8'h15,8'h00,8'h00,8'h00,8'h00,8'h00,8'h00,8'h03,8'hE9,8'h42,8'h00,8'h00,8'h00,8'h64,8'h41,8'h41,8'h50,8'h4C,8'h20,8'h20,8'h20,8'h20,8'h00,8'h16,8'hE3,8'h60};
    send_frame(good, 78);
    repeat(5) @(posedge clk);  // wait for parser to assert m_msg_valid
    check("valid frame emitted message", m_msg_valid);
    check("payload length captured", m_msg_len == 16'd36);
    check("no errors on valid frame", !err_invalid_eth && !err_invalid_ip && !err_invalid_udp);
    m_msg_ready = 1; @(posedge clk); m_msg_ready = 0;  // consume the output
    bad = '{8'h00,8'h11,8'h22,8'h33,8'h44,8'h55,8'h66,8'h77,8'h88,8'h99,8'hAA,8'hBB,8'h08,8'h06,8'h45,8'h00,8'h00,8'h1C,8'h00,8'h01,8'h00,8'h00,8'h40,8'h11,8'h00,8'h00,8'h0A,8'h00,8'h00,8'h01,8'h0A,8'h00,8'h00,8'h02,8'h1F,8'h90,8'h1F,8'h90,8'h00,8'h08,8'h00,8'h00};
    send_frame(bad, 42);
    repeat(4) @(posedge clk);
    check("malformed ethertype flagged", err_invalid_eth);
    $display("SUMMARY pass=%0d fail=%0d", pass, fail); $finish;
  end
endmodule

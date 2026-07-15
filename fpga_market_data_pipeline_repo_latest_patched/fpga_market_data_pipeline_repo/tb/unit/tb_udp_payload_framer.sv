`timescale 1ns/1ps
module tb_udp_payload_framer;
  localparam int MSG_BYTES = 64;
  localparam int MSG_W = MSG_BYTES * 8;
  logic clk=0, rst_n=0;
  logic [MSG_W-1:0] s_msg_data, m_msg_data; logic [15:0] s_msg_len, m_msg_len; logic s_msg_valid, s_msg_ready, m_msg_valid, m_msg_ready;
  udp_payload_framer dut(.clk(clk), .rst_n(rst_n), .s_msg_data(s_msg_data), .s_msg_len(s_msg_len), .s_msg_valid(s_msg_valid), .s_msg_ready(s_msg_ready), .m_msg_data(m_msg_data), .m_msg_len(m_msg_len), .m_msg_valid(m_msg_valid), .m_msg_ready(m_msg_ready));
  always #5 clk=~clk;
  int pass=0, fail=0; task automatic check(string n, logic c); if(c) begin pass++; $display("[PASS] %s", n); end else begin fail++; $error("[FAIL] %s", n); end endtask
  initial begin
    m_msg_ready=0; s_msg_valid=0; s_msg_data=0; s_msg_len=0; rst_n=0; repeat(3) @(posedge clk); rst_n=1; @(posedge clk);
    s_msg_data = '0; s_msg_data[63:0] = 64'hDEADBEEFCAFEBABE; s_msg_len=16'd4; s_msg_valid=1; @(posedge clk); s_msg_valid=0;
    // Keep m_msg_ready low so output stays valid until we check it
    repeat(5) @(posedge clk);
    check("framer emits valid", m_msg_valid);
    check("framer forwards len", m_msg_len==16'd4);
    m_msg_ready=1; @(posedge clk); // release handshake
    $display("SUMMARY pass=%0d fail=%0d", pass, fail); $finish;
  end
endmodule

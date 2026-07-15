// -----------------------------------------------------------------------------
// itch_vectors.svh
// Hand-packed, byte-exact ITCH 5.0 message vectors for unit testbenches.
// -----------------------------------------------------------------------------

localparam bit [8*36-1:0] MSG_A_VALID = {
  8'h41, 8'h00, 8'h01, 8'h00, 8'h00, 8'h00, 8'h00, 8'h07, 8'h5B, 8'hCD, 8'h15, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h03, 8'hE9, 8'h42, 8'h00, 8'h00, 8'h00, 8'h64, 8'h41, 8'h41, 8'h50, 8'h4C, 8'h20, 8'h20, 8'h20, 8'h20, 8'h00, 8'h16, 8'hE3, 8'h60
};
localparam int MSG_A_VALID_LEN = 36;

localparam bit [8*19-1:0] MSG_D_VALID = {
  8'h44, 8'h00, 8'h01, 8'h00, 8'h00, 8'h00, 8'h00, 8'h07, 8'h5B, 8'hCD, 8'hE7, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h03, 8'hE9
};
localparam int MSG_D_VALID_LEN = 19;

localparam bit [8*30-1:0] MSG_A_BAD_LENGTH = {
  8'h41, 8'h00, 8'h01, 8'h00, 8'h00, 8'h00, 8'h00, 8'h07, 8'h5B, 8'hCD, 8'h15, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h03, 8'hE9, 8'h42, 8'h00, 8'h00, 8'h00, 8'h64, 8'h41, 8'h41, 8'h50, 8'h4C, 8'h20, 8'h20
};
localparam int MSG_A_BAD_LENGTH_LEN = 30;

localparam bit [8*5-1:0] MSG_UNSUPPORTED = {
  8'h5A, 8'h00, 8'h01, 8'h00, 8'h00
};
localparam int MSG_UNSUPPORTED_LEN = 5;

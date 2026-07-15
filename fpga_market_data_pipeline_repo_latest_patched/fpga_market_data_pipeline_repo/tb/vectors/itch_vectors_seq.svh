// -----------------------------------------------------------------------------
// itch_vectors_seq.svh
// Extended byte-exact ITCH 5.0 sequence vectors for the integration testbench.
// Sequence: R(bootstrap) -> ADD bid(11) -> ADD ask(22) -> EXEC(11,20)
//   -> CANCEL(11,30) -> REPLACE(22->33) -> DELETE(33)
// -----------------------------------------------------------------------------

localparam bit [8*39-1:0] MSG_R_DIRECTORY = {
  8'h52, 8'h00, 8'h01, 8'h00, 8'h00, 8'h00, 8'h00, 8'h07, 8'h5B, 8'hCC, 8'hBC, 8'h41, 8'h41, 8'h50, 8'h4C, 8'h20, 8'h20, 8'h20, 8'h20, 8'h51, 8'h20, 8'h00, 8'h00, 8'h00, 8'h64, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00
};
localparam int MSG_R_DIRECTORY_LEN = 39;

localparam bit [8*36-1:0] MSG_A2_ADD_ASK = {
  8'h41, 8'h00, 8'h01, 8'h00, 8'h00, 8'h00, 8'h00, 8'h07, 8'h5B, 8'hCD, 8'h20, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h16, 8'h53, 8'h00, 8'h00, 8'h00, 8'h28, 8'h41, 8'h41, 8'h50, 8'h4C, 8'h20, 8'h20, 8'h20, 8'h20, 8'h00, 8'h10, 8'h05, 8'h90
};
localparam int MSG_A2_ADD_ASK_LEN = 36;

localparam bit [8*31-1:0] MSG_E_EXEC = {
  8'h45, 8'h00, 8'h01, 8'h00, 8'h00, 8'h00, 8'h00, 8'h07, 8'h5B, 8'hCD, 8'h52, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h0B, 8'h00, 8'h00, 8'h00, 8'h14, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h02, 8'h2B
};
localparam int MSG_E_EXEC_LEN = 31;

localparam bit [8*23-1:0] MSG_X_CANCEL = {
  8'h58, 8'h00, 8'h01, 8'h00, 8'h00, 8'h00, 8'h00, 8'h07, 8'h5B, 8'hCD, 8'h84, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h0B, 8'h00, 8'h00, 8'h00, 8'h1E
};
localparam int MSG_X_CANCEL_LEN = 23;

localparam bit [8*35-1:0] MSG_U_REPLACE = {
  8'h55, 8'h00, 8'h01, 8'h00, 8'h00, 8'h00, 8'h00, 8'h07, 8'h5B, 8'hCD, 8'hB6, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h16, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h21, 8'h00, 8'h00, 8'h00, 8'h23, 8'h00, 8'h0F, 8'hB7, 8'h70
};
localparam int MSG_U_REPLACE_LEN = 35;

localparam bit [8*19-1:0] MSG_D2_DELETE_NEW = {
  8'h44, 8'h00, 8'h01, 8'h00, 8'h00, 8'h00, 8'h00, 8'h07, 8'h5B, 8'hCD, 8'hE8, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h00, 8'h21
};
localparam int MSG_D2_DELETE_NEW_LEN = 19;

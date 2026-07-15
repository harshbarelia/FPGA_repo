// -----------------------------------------------------------------------------
// be_extract.sv
// Big-endian field extraction helpers for ITCH 5.0 message decoding.
// -----------------------------------------------------------------------------

package be_extract_pkg;

  function automatic logic [7:0] get_u8(
      input logic [2047:0] data,
      input int            msg_w_bytes,
      input int            idx
  );
    int bit_hi;
    begin
      bit_hi = (msg_w_bytes - 1 - idx) * 8;
      get_u8 = data[bit_hi +: 8];
    end
  endfunction

  function automatic logic [15:0] get_be16(
      input logic [2047:0] data,
      input int            msg_w_bytes,
      input int            idx
  );
    begin
      get_be16 = { get_u8(data, msg_w_bytes, idx),
                   get_u8(data, msg_w_bytes, idx+1) };
    end
  endfunction

  function automatic logic [31:0] get_be32(
      input logic [2047:0] data,
      input int            msg_w_bytes,
      input int            idx
  );
    begin
      get_be32 = { get_u8(data, msg_w_bytes, idx),
                   get_u8(data, msg_w_bytes, idx+1),
                   get_u8(data, msg_w_bytes, idx+2),
                   get_u8(data, msg_w_bytes, idx+3) };
    end
  endfunction

  function automatic logic [47:0] get_be48(
      input logic [2047:0] data,
      input int            msg_w_bytes,
      input int            idx
  );
    begin
      get_be48 = { get_u8(data, msg_w_bytes, idx),
                   get_u8(data, msg_w_bytes, idx+1),
                   get_u8(data, msg_w_bytes, idx+2),
                   get_u8(data, msg_w_bytes, idx+3),
                   get_u8(data, msg_w_bytes, idx+4),
                   get_u8(data, msg_w_bytes, idx+5) };
    end
  endfunction

  function automatic logic [63:0] get_be64(
      input logic [2047:0] data,
      input int            msg_w_bytes,
      input int            idx
  );
    begin
      get_be64 = { get_u8(data, msg_w_bytes, idx),
                   get_u8(data, msg_w_bytes, idx+1),
                   get_u8(data, msg_w_bytes, idx+2),
                   get_u8(data, msg_w_bytes, idx+3),
                   get_u8(data, msg_w_bytes, idx+4),
                   get_u8(data, msg_w_bytes, idx+5),
                   get_u8(data, msg_w_bytes, idx+6),
                   get_u8(data, msg_w_bytes, idx+7) };
    end
  endfunction

  function automatic logic [63:0] pack_stock8(
      input logic [2047:0] data,
      input int            msg_w_bytes,
      input int            idx
  );
    begin
      pack_stock8 = get_be64(data, msg_w_bytes, idx);
    end
  endfunction

endpackage : be_extract_pkg

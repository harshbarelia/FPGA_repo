class dma_seq_item extends uvm_sequence_item;
    rand bit [63:0] host_addr;
    rand bit [31:0] byte_len;
    rand bit [31:0] ctrl;
    rand bit [511:0] payload_q[$];

    constraint c_len_nonzero { byte_len inside {[64:4096]}; }
    constraint c_aligned     { host_addr[5:0] == 6'b0; byte_len % 64 == 0; }
    constraint c_payload_sz  { payload_q.size() == (byte_len / 64); }

    `uvm_object_utils_begin(dma_seq_item)
        `uvm_field_int(host_addr, UVM_ALL_ON)
        `uvm_field_int(byte_len,  UVM_ALL_ON)
        `uvm_field_int(ctrl,      UVM_ALL_ON)
        `uvm_field_queue_int(payload_q, UVM_ALL_ON)
    `uvm_object_utils_end

    function new(string name = "dma_seq_item");
        super.new(name);
    endfunction

    function bit [127:0] pack_desc();
        return {host_addr, byte_len, ctrl};
    endfunction
endclass

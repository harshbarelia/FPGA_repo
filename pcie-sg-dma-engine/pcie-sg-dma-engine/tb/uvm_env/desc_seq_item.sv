//==============================================================================
// desc_seq_item.sv
// UVM sequence item representing a single scatter-gather descriptor to be
// driven into the ring. This is the transaction-level object used by
// desc_sequencer -> desc_driver -> DUT, and independently checked by
// desc_scoreboard against desc_monitor observations.
//==============================================================================
class desc_seq_item extends uvm_sequence_item;
    rand bit [63:0] src_addr;
    rand bit [63:0] dst_addr;
    rand bit [31:0] length;
    rand bit        dir;        // 0=H2C, 1=C2H
    rand bit        irq_en;

    // Constraint: majority of random descriptors should be legal so the
    // ring actually makes forward progress; a smaller weighted subset
    // intentionally generates malformed descriptors to hit decode_error
    // coverage bins.
    constraint c_length_valid {
        length dist { 0 := 5, [1:64'h0400_0000] := 90, [64'h0400_0001:64'hFFFF_FFFF] := 5 };
    }
    constraint c_addr_alignment {
        src_addr[1:0] dist { 2'b00 := 90, [2'b01:2'b11] := 10 };
        dst_addr[1:0] dist { 2'b00 := 90, [2'b01:2'b11] := 10 };
    }

    `uvm_object_utils_begin(desc_seq_item)
        `uvm_field_int(src_addr, UVM_ALL_ON)
        `uvm_field_int(dst_addr, UVM_ALL_ON)
        `uvm_field_int(length,   UVM_ALL_ON)
        `uvm_field_int(dir,      UVM_ALL_ON)
        `uvm_field_int(irq_en,   UVM_ALL_ON)
    `uvm_object_utils_end

    function new(string name = "desc_seq_item");
        super.new(name);
    endfunction
endclass

//==============================================================================
// desc_sequence.sv
// Base sequence: N randomized descriptors. Extend this for targeted
// sequences (ring_full_sequence, malformed_burst_sequence, etc.) rather
// than cramming every scenario into one sequence class.
//==============================================================================
class desc_base_sequence extends uvm_sequence #(desc_seq_item);
    `uvm_object_utils(desc_base_sequence)

    rand int num_descriptors = 50;

    function new(string name = "desc_base_sequence");
        super.new(name);
    endfunction

    task body();
        repeat (num_descriptors) begin
            desc_seq_item item = desc_seq_item::type_id::create("item");
            start_item(item);
            if (!item.randomize())
                `uvm_error("SEQ", "Randomization failed")
            finish_item(item);
        end
    endtask
endclass

//==============================================================================
// ring_full_sequence.sv (same file for brevity -- split into separate file
// in a real repo per your one-class-per-file convention)
//==============================================================================
class ring_full_sequence extends uvm_sequence #(desc_seq_item);
    `uvm_object_utils(ring_full_sequence)

    function new(string name = "ring_full_sequence");
        super.new(name);
    endfunction

    task body();
        // Push exactly RING_DEPTH descriptors back-to-back with zero delay
        // to force the ring-full condition and hit the full/near-full
        // coverage bins defined in sva_descriptor_invariants.sv
        repeat (128) begin
            desc_seq_item item = desc_seq_item::type_id::create("item");
            start_item(item);
            item.length = 4096;   // fixed valid length, isolate ring-full behavior
            item.src_addr = 64'h1000_0000;
            item.dst_addr = 64'h2000_0000;
            item.dir = 1;
            finish_item(item);
        end
    endtask
endclass

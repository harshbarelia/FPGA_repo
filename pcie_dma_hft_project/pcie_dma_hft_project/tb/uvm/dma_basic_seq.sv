class dma_basic_seq extends uvm_sequence #(dma_seq_item);
    `uvm_object_utils(dma_basic_seq)
    function new(string name = "dma_basic_seq");
        super.new(name);
    endfunction

    task body();
        dma_seq_item req;
        repeat (16) begin
            req = dma_seq_item::type_id::create("req");
            start_item(req);
            assert(req.randomize() with {
                host_addr inside {[64'h0000_1000:64'h0001_0000]};
                byte_len  inside {64, 128, 256, 512, 1024};
            });
            finish_item(req);
        end
    endtask
endclass

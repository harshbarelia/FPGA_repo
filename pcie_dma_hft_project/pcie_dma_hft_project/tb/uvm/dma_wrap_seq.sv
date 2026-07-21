class dma_wrap_seq extends uvm_sequence #(dma_seq_item);
    `uvm_object_utils(dma_wrap_seq)
    function new(string name = "dma_wrap_seq");
        super.new(name);
    endfunction

    task body();
        dma_seq_item req;
        repeat (300) begin
            req = dma_seq_item::type_id::create("req");
            start_item(req);
            assert(req.randomize() with {
                host_addr[63:12] == 52'h0;
                byte_len == 64;
            });
            finish_item(req);
        end
    endtask
endclass

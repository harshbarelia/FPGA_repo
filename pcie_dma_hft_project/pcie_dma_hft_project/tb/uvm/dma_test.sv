class dma_test extends uvm_test;
    `uvm_component_utils(dma_test)
    dma_env env;

    function new(string name = "dma_test", uvm_component parent = null);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        env = dma_env::type_id::create("env", this);
    endfunction

    task run_phase(uvm_phase phase);
        dma_basic_seq seq;
        phase.raise_objection(this);
        seq = dma_basic_seq::type_id::create("seq");
        seq.start(env.seqr);
        #1000ns;
        phase.drop_objection(this);
    endtask
endclass

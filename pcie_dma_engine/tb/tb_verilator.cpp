// tb_verilator.cpp
// Verilator C++ Testbench for PCIe Scatter-Gather DMA Engine (dma_top)
// Simulates AXI4-Lite CSR configuration, dual-memory slave response (Host DDR vs BRAM),
// descriptor fetching, H2C data transfer, MSI-X interrupt detection, and data integrity verification.

#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
#include <memory>

#include "Vdma_top.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

// Constants matching dma_pkg.sv
constexpr uint32_t HOST_DDR_BASE = 0x00000000;
constexpr uint32_t HOST_DDR_SIZE = 0x01000000; // 16MB
constexpr uint32_t BRAM_BASE     = 0x80000000;
constexpr uint32_t BRAM_SIZE     = 0x00010000; // 64KB
constexpr uint32_t DESC_BYTES    = 16;

// Dual Memory Slave Model for AXI4-Lite Master Port
class DualMemoryModel {
public:
    std::vector<uint8_t> ddr_mem;
    std::vector<uint8_t> bram_mem;

    DualMemoryModel() : ddr_mem(HOST_DDR_SIZE, 0), bram_mem(BRAM_SIZE, 0) {
        // Initialize DDR memory with test pattern
        for (size_t i = 0; i < ddr_mem.size(); ++i) {
            ddr_mem[i] = static_cast<uint8_t>(i & 0xFF);
        }
    }

    bool in_bram(uint32_t addr) const {
        return (addr >= BRAM_BASE && addr < (BRAM_BASE + BRAM_SIZE));
    }

    uint32_t read_word(uint32_t addr) const {
        uint32_t val = 0;
        if (in_bram(addr)) {
            uint32_t offset = addr - BRAM_BASE;
            val |= static_cast<uint32_t>(bram_mem[offset + 0]) << 0;
            val |= static_cast<uint32_t>(bram_mem[offset + 1]) << 8;
            val |= static_cast<uint32_t>(bram_mem[offset + 2]) << 16;
            val |= static_cast<uint32_t>(bram_mem[offset + 3]) << 24;
        } else {
            uint32_t offset = addr - HOST_DDR_BASE;
            val |= static_cast<uint32_t>(ddr_mem[offset + 0]) << 0;
            val |= static_cast<uint32_t>(ddr_mem[offset + 1]) << 8;
            val |= static_cast<uint32_t>(ddr_mem[offset + 2]) << 16;
            val |= static_cast<uint32_t>(ddr_mem[offset + 3]) << 24;
        }
        return val;
    }

    void write_word(uint32_t addr, uint32_t data) {
        if (in_bram(addr)) {
            uint32_t offset = addr - BRAM_BASE;
            bram_mem[offset + 0] = static_cast<uint8_t>(data & 0xFF);
            bram_mem[offset + 1] = static_cast<uint8_t>((data >> 8) & 0xFF);
            bram_mem[offset + 2] = static_cast<uint8_t>((data >> 16) & 0xFF);
            bram_mem[offset + 3] = static_cast<uint8_t>((data >> 24) & 0xFF);
        } else {
            uint32_t offset = addr - HOST_DDR_BASE;
            ddr_mem[offset + 0] = static_cast<uint8_t>(data & 0xFF);
            ddr_mem[offset + 1] = static_cast<uint8_t>((data >> 8) & 0xFF);
            ddr_mem[offset + 2] = static_cast<uint8_t>((data >> 16) & 0xFF);
            ddr_mem[offset + 3] = static_cast<uint8_t>((data >> 24) & 0xFF);
        }
    }

    void write_descriptor(uint32_t ring_base, int slot, uint32_t src, uint32_t dst, uint32_t len, uint32_t ctrl) {
        uint32_t desc_addr = ring_base + (slot * DESC_BYTES);
        write_word(desc_addr + 0,  src);
        write_word(desc_addr + 4,  dst);
        write_word(desc_addr + 8,  len);
        write_word(desc_addr + 12, ctrl);
    }
};

vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

void tick(Vdma_top* top, VerilatedVcdC* tfp) {
    top->clk = 0;
    top->eval();
    if (tfp) tfp->dump(main_time);
    main_time += 5;

    top->clk = 1;
    top->eval();
    if (tfp) tfp->dump(main_time);
    main_time += 5;
}

// Perform AXI4-Lite CSR write transaction
void axil_write(Vdma_top* top, VerilatedVcdC* tfp, uint16_t addr, uint32_t data) {
    top->s_axil_awaddr  = addr;
    top->s_axil_awvalid = 1;
    top->s_axil_wdata   = data;
    top->s_axil_wvalid  = 1;
    top->s_axil_wstrb   = 0xF;
    top->s_axil_bready  = 1;

    do {
        tick(top, tfp);
    } while (!top->s_axil_bvalid);

    top->s_axil_awvalid = 0;
    top->s_axil_wvalid  = 0;
    top->s_axil_bready  = 0;
    tick(top, tfp);
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    auto top = std::make_unique<Vdma_top>();
    auto tfp = std::make_unique<VerilatedVcdC>();

    top->trace(tfp.get(), 99);
    tfp->open("dma_top_verilator.vcd");

    DualMemoryModel mem;

    // Reset sequence
    top->rst_n = 0;
    top->s_axil_awvalid = 0;
    top->s_axil_wvalid  = 0;
    top->s_axil_arvalid = 0;
    top->s_axil_bready  = 0;
    top->s_axil_rready  = 0;
    top->m_axil_arready = 0;
    top->m_axil_rvalid  = 0;
    top->m_axil_awready = 0;
    top->m_axil_wready  = 0;
    top->m_axil_bvalid  = 0;

    for (int i = 0; i < 10; ++i) tick(top.get(), tfp.get());
    top->rst_n = 1;
    tick(top.get(), tfp.get());

    std::cout << "[VERILATOR TB] Reset released. Initializing Host DDR descriptor..." << std::endl;

    // Setup Test Descriptor in Host DDR:
    // H2C transfer (DIR=0, IRQ_EN=1 -> ctrl=0x00000002)
    uint32_t ring_base = HOST_DDR_BASE + 0x1000;
    uint32_t ring_size = 16;
    uint32_t src_addr  = HOST_DDR_BASE + 0x2000;
    uint32_t dst_addr  = BRAM_BASE;
    uint32_t xfer_len  = 256; // 256 bytes

    mem.write_descriptor(ring_base, 0, src_addr, dst_addr, xfer_len, 0x00000002);

    std::cout << "[VERILATOR TB] Writing CSR registers over AXI4-Lite BAR0 interface..." << std::endl;

    axil_write(top.get(), tfp.get(), 0x004, ring_base);  // ADDR_RING_BASE
    axil_write(top.get(), tfp.get(), 0x00C, ring_size);  // ADDR_RING_SIZE
    axil_write(top.get(), tfp.get(), 0x018, 0x00000001); // ADDR_IRQ_EN
    axil_write(top.get(), tfp.get(), 0x000, 0x00000001); // ADDR_CTRL (dma_enable=1)

    std::cout << "[VERILATOR TB] Ringing Doorbell: TAIL_PTR = 1..." << std::endl;
    axil_write(top.get(), tfp.get(), 0x010, 1); // ADDR_TAIL_PTR

    // Main Simulation Loop with Memory Slave Logic
    bool irq_seen = false;
    int timeout = 5000;

    while (main_time < 100000 && timeout-- > 0) {
        // Handle AXI-Lite Master Read Channel (m_axil_ar / m_axil_r)
        if (top->m_axil_arvalid && !top->m_axil_arready) {
            top->m_axil_arready = 1;
            uint32_t araddr = top->m_axil_araddr;
            tick(top.get(), tfp.get());
            top->m_axil_arready = 0;

            top->m_axil_rdata = mem.read_word(araddr);
            top->m_axil_rvalid = 1;
            do {
                tick(top.get(), tfp.get());
            } while (!top->m_axil_rready);
            top->m_axil_rvalid = 0;
        }

        // Handle AXI-Lite Master Write Channel (m_axil_aw / m_axil_w / m_axil_b)
        if (top->m_axil_awvalid && top->m_axil_wvalid && !top->m_axil_awready) {
            top->m_axil_awready = 1;
            top->m_axil_wready  = 1;
            uint32_t awaddr = top->m_axil_awaddr;
            uint32_t wdata  = top->m_axil_wdata;
            mem.write_word(awaddr, wdata);

            tick(top.get(), tfp.get());
            top->m_axil_awready = 0;
            top->m_axil_wready  = 0;

            top->m_axil_bvalid = 1;
            do {
                tick(top.get(), tfp.get());
            } while (!top->m_axil_bready);
            top->m_axil_bvalid = 0;
        }

        if (top->msix_irq) {
            std::cout << "[VERILATOR TB] SUCCESS: MSI-X Interrupt received at time " << main_time << " ns!" << std::endl;
            irq_seen = true;
            break;
        }

        tick(top.get(), tfp.get());
    }

    assert(irq_seen && "ERROR: MSI-X Interrupt was not received within timeout!");

    // Verify Data Integrity: Compare Host DDR source vs Local BRAM destination
    bool mismatch = false;
    for (uint32_t i = 0; i < xfer_len; ++i) {
        uint8_t src_b = mem.ddr_mem[(src_addr - HOST_DDR_BASE) + i];
        uint8_t dst_b = mem.bram_mem[(dst_addr - BRAM_BASE) + i];
        if (src_b != dst_b) {
            std::cerr << "[VERILATOR TB] Data Mismatch at byte " << i
                      << ": BRAM=" << std::hex << (int)dst_b
                      << " DDR=" << (int)src_b << std::dec << std::endl;
            mismatch = true;
        }
    }

    if (!mismatch) {
        std::cout << "[VERILATOR TB] DATA INTEGRITY PASSED: 256 bytes successfully transferred Host DDR -> BRAM!" << std::endl;
    } else {
        std::cerr << "[VERILATOR TB] DATA INTEGRITY FAILED!" << std::endl;
        return 1;
    }

    tfp->close();
    std::cout << "[VERILATOR TB] Waveforms saved to dma_top_verilator.vcd" << std::endl;
    return 0;
}

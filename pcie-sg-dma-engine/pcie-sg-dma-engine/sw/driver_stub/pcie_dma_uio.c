/*
 * pcie_dma_uio.c
 * Minimal Linux UIO-based userspace driver stub for the pcie-sg-dma-engine.
 * Uses UIO (Userspace I/O) instead of a full kernel char driver because it
 * is dramatically simpler to get bring-up working (no kernel module needed
 * beyond the generic uio_pci_generic, which ships in-tree), while still
 * proving you understand BAR mapping, MMIO register access, and triggering
 * a DMA transfer from userspace.
 *
 * THIS HAS NOT BEEN TESTED AGAINST REAL HARDWARE. It compiles against
 * standard Linux headers conceptually but has not been run against an
 * actual FPGA board with this DMA engine synthesized onto it. Treat it as
 * a structurally-correct starting point, not a proven driver.
 *
 * Prerequisites for real bring-up:
 *   1. FPGA board enumerates as a PCIe device (lspci shows your vendor/device ID)
 *   2. Bind uio_pci_generic to the device:
 *        echo "vendor_id device_id" > /sys/bus/pci/drivers/uio_pci_generic/new_id
 *   3. /dev/uio0 (or similar) appears
 *   4. BAR0 resource file exists at /sys/class/uio/uio0/device/resource0
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

/* Register offsets -- MUST match docs/interface_spec.md BAR0 map exactly */
#define REG_DESC_RING_BASE_LO   0x00
#define REG_DESC_RING_BASE_HI   0x04
#define REG_INSERT_PTR          0x08
#define REG_EXTRACT_PTR         0x0C
#define REG_WB_INTR_TIMEOUT     0x10

#define BAR0_SIZE               0x2000   /* must match actual BAR size from PCIe config space, verify with lspci -vvv */

struct dma_descriptor {
    uint64_t src_addr;
    uint64_t dst_addr;
    uint32_t length;
    uint32_t dir_irq;   /* bit0 = dir, bit2 = irq_en, matches desc_fetch.sv DECODE bit layout */
    uint64_t reserved;
} __attribute__((packed));   /* 32 bytes total -- static_assert this against sizeof() before trusting it */

static volatile uint8_t *bar0_map = NULL;

static int map_bar0(const char *resource_path) {
    int fd = open(resource_path, O_RDWR | O_SYNC);
    if (fd < 0) {
        perror("open BAR0 resource file");
        return -1;
    }
    bar0_map = mmap(NULL, BAR0_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (bar0_map == MAP_FAILED) {
        perror("mmap BAR0");
        close(fd);
        return -1;
    }
    /* fd intentionally left open for the lifetime of the mapping; close on
       program exit via cleanup path (not shown -- add proper teardown) */
    return 0;
}

static inline void reg_write32(uint32_t offset, uint32_t value) {
    *(volatile uint32_t *)(bar0_map + offset) = value;
}

static inline uint32_t reg_read32(uint32_t offset) {
    return *(volatile uint32_t *)(bar0_map + offset);
}

/*
 * Allocate a host-resident descriptor ring buffer that the FPGA can DMA
 * to/from. In production this MUST be physically contiguous memory pinned
 * for DMA (e.g. via hugepages, or a kernel-allocated DMA buffer exposed
 * through a proper char driver with dma_alloc_coherent()). This stub uses
 * a plain malloc'd buffer, which is WRONG for real DMA -- userspace malloc
 * memory is not guaranteed physically contiguous and its physical address
 * is not directly knowable from userspace without IOMMU/VFIO plumbing.
 *
 * This is flagged explicitly because pretending a malloc buffer works for
 * real DMA is the single most common mistake in "toy" PCIe driver code,
 * and any competent interviewer will ask about this immediately.
 */
static struct dma_descriptor *alloc_descriptor_ring(int num_entries) {
    struct dma_descriptor *ring = calloc(num_entries, sizeof(struct dma_descriptor));
    if (!ring) {
        perror("calloc descriptor ring");
        return NULL;
    }
    fprintf(stderr,
        "WARNING: descriptor ring allocated via malloc, NOT physically contiguous "
        "pinned DMA memory. Replace with VFIO/UIO DMA buffer allocation "
        "(see docs/design_decisions.md TODO) before running against real hardware.\n");
    return ring;
}

static void push_descriptor(struct dma_descriptor *ring, int idx,
                             uint64_t src, uint64_t dst, uint32_t len,
                             int dir, int irq_en) {
    ring[idx].src_addr = src;
    ring[idx].dst_addr = dst;
    ring[idx].length   = len;
    ring[idx].dir_irq  = (dir & 0x1) | ((irq_en & 0x1) << 2);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s /sys/class/uio/uio0/device/resource0\n", argv[0]);
        return 1;
    }

    if (map_bar0(argv[1]) != 0) return 1;

    printf("Current EXTRACT_PTR (hw progress): %u\n", reg_read32(REG_EXTRACT_PTR));

    struct dma_descriptor *ring = alloc_descriptor_ring(128);
    if (!ring) return 1;

    /* NOTE: the physical address of `ring` is NOT `(uint64_t)ring`. This
       program does not actually have a way to get the correct physical
       address from a malloc'd buffer -- this line is a placeholder that
       WILL NOT WORK on real hardware. Fixing this requires either VFIO
       (preferred, gives you an IOMMU-mapped DMA-capable buffer with a
       real IOVA) or a kernel driver using dma_alloc_coherent(). */
    uint64_t ring_phys_addr_PLACEHOLDER = (uint64_t)ring;

    reg_write32(REG_DESC_RING_BASE_LO, (uint32_t)(ring_phys_addr_PLACEHOLDER & 0xFFFFFFFF));
    reg_write32(REG_DESC_RING_BASE_HI, (uint32_t)(ring_phys_addr_PLACEHOLDER >> 32));
    reg_write32(REG_WB_INTR_TIMEOUT, 256);

    push_descriptor(ring, 0, 0x1000000, 0x2000000, 4096, /*dir=C2H*/1, /*irq*/1);

    reg_write32(REG_INSERT_PTR, 1);   /* tell hardware one descriptor is ready */

    printf("Descriptor pushed, insert_ptr advanced. Poll EXTRACT_PTR to observe progress:\n");
    for (int i = 0; i < 10; i++) {
        printf("  EXTRACT_PTR = %u\n", reg_read32(REG_EXTRACT_PTR));
        usleep(100000);
    }

    return 0;
}

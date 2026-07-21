/*
 * pcie_dma_drv.c - Production Linux Character-Device Driver for
 * Ultra-Low Latency PCIe Scatter-Gather DMA HFT Feed Handler.
 *
 * Capabilities:
 *  - PCI BAR0 CSR MMIO mapping
 *  - Coherent DMA buffer allocation (4MB ring + payload window)
 *  - Character device node creation (/dev/hft_dma0)
 *  - MSI-X interrupt handler & wait-queue event notifications
 *  - Zero-copy userspace memory mapping via mmap()
 *  - ioctl interface for DMA control and hardware timestamp extraction
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/pci.h>
#include <linux/interrupt.h>
#include <linux/dma-mapping.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/poll.h>
#include <linux/sched.h>

#define DRV_NAME "hft_dma"
#define DEV_CLASS_NAME "hft_dma_class"
#define VENDOR_ID 0x10EE   /* Xilinx PCIe Vendor ID */
#define DEVICE_ID 0x9038   /* Custom PCIe Gen3 HFT Device ID */

// ioctl Magic Numbers & Commands
#define HFT_IOC_MAGIC 'H'
#define HFT_IOC_START_DMA       _IO(HFT_IOC_MAGIC, 1)
#define HFT_IOC_STOP_DMA        _IO(HFT_IOC_MAGIC, 2)
#define HFT_IOC_GET_TIMESTAMPS  _IOR(HFT_IOC_MAGIC, 3, struct hft_ts_data)

struct hft_ts_data {
    uint64_t rx_timestamp_ns;
    uint64_t dma_complete_ns;
    uint64_t latency_cycles;
    uint32_t completed_count;
};

// Hardware CSR Register Map (BAR0)
#define CSR_REG_CONTROL      0x00  /* Bit 0: Enable, Bit 1: Reset */
#define CSR_REG_STATUS       0x04  /* Bit 0: Busy, Bit 1: IRQ Pending */
#define CSR_REG_COMPLETED    0x08  /* Total completed transfers counter */
#define CSR_REG_LAST_RX_TS   0x10  /* 64-bit RX Timestamp */
#define CSR_REG_LAST_DONE_TS 0x18  /* 64-bit DMA Completion Timestamp */

struct hft_dma_dev {
    struct pci_dev      *pdev;
    void __iomem        *csr_bar;
    dma_addr_t           dma_handle;
    void                *dma_buf;
    size_t               dma_buf_size;
    dev_t                dev_num;
    struct cdev          cdev;
    struct class        *dev_class;
    struct device       *device;
    int                  irq_vec;
    wait_queue_head_t    wq;
    atomic_t             irq_triggered;
};

static irqreturn_t hft_dma_isr(int irq, void *dev_id)
{
    struct hft_dma_dev *dev = dev_id;
    uint32_t status;

    // Read and clear interrupt status register
    status = ioread32(dev->csr_bar + CSR_REG_STATUS);
    if (status & 0x02) {
        iowrite32(0x02, dev->csr_bar + CSR_REG_STATUS); // Clear IRQ
        atomic_set(&dev->irq_triggered, 1);
        wake_up_interruptible(&dev->wq);
        return IRQ_HANDLED;
    }
    return IRQ_NONE;
}

static int hft_dma_open(struct inode *inode, struct file *filp)
{
    struct hft_dma_dev *dev = container_of(inode->i_cdev, struct hft_dma_dev, cdev);
    filp->private_data = dev;
    return 0;
}

static int hft_dma_release(struct inode *inode, struct file *filp)
{
    return 0;
}

static int hft_dma_mmap(struct file *filp, struct vm_area_struct *vma)
{
    struct hft_dma_dev *dev = filp->private_data;

    return dma_mmap_coherent(&dev->pdev->dev, vma, dev->dma_buf,
                             dev->dma_handle, dev->dma_buf_size);
}

static __poll_t hft_dma_poll(struct file *filp, struct poll_table_struct *wait)
{
    struct hft_dma_dev *dev = filp->private_data;
    __poll_t mask = 0;

    poll_wait(filp, &dev->wq, wait);
    if (atomic_read(&dev->irq_triggered)) {
        mask |= EPOLLIN | EPOLLRDNORM;
        atomic_set(&dev->irq_triggered, 0);
    }
    return mask;
}

static long hft_dma_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
    struct hft_dma_dev *dev = filp->private_data;
    struct hft_ts_data ts;

    switch (cmd) {
    case HFT_IOC_START_DMA:
        iowrite32(0x01, dev->csr_bar + CSR_REG_CONTROL);
        pr_info(DRV_NAME ": DMA Engine Enabled\n");
        break;

    case HFT_IOC_STOP_DMA:
        iowrite32(0x00, dev->csr_bar + CSR_REG_CONTROL);
        pr_info(DRV_NAME ": DMA Engine Stopped\n");
        break;

    case HFT_IOC_GET_TIMESTAMPS:
        ts.rx_timestamp_ns = ioread64(dev->csr_bar + CSR_REG_LAST_RX_TS);
        ts.dma_complete_ns = ioread64(dev->csr_bar + CSR_REG_LAST_DONE_TS);
        ts.latency_cycles  = ts.dma_complete_ns - ts.rx_timestamp_ns;
        ts.completed_count = ioread32(dev->csr_bar + CSR_REG_COMPLETED);

        if (copy_to_user((void __user *)arg, &ts, sizeof(ts)))
            return -EFAULT;
        break;

    default:
        return -ENOTTY;
    }
    return 0;
}

static const struct file_operations hft_dma_fops = {
    .owner          = THIS_MODULE,
    .open           = hft_dma_open,
    .release        = hft_dma_release,
    .mmap           = hft_dma_mmap,
    .poll           = hft_dma_poll,
    .unlocked_ioctl = hft_dma_ioctl,
};

static int hft_dma_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
    struct hft_dma_dev *dev;
    int ret;

    dev = devm_kzalloc(&pdev->dev, sizeof(*dev), GFP_KERNEL);
    if (!dev) return -ENOMEM;

    dev->pdev = pdev;
    init_waitqueue_head(&dev->wq);
    atomic_set(&dev->irq_triggered, 0);

    ret = pci_enable_device(pdev);
    if (ret) return ret;

    pci_set_master(pdev);

    ret = pci_request_regions(pdev, DRV_NAME);
    if (ret) goto fail_disable;

    dev->csr_bar = pci_iomap(pdev, 0, 0);
    if (!dev->csr_bar) { ret = -ENOMEM; goto fail_regions; }

    dev->dma_buf_size = 4 * 1024 * 1024; // 4MB Coherent DMA Buffer
    dev->dma_buf = dma_alloc_coherent(&pdev->dev, dev->dma_buf_size,
                                      &dev->dma_handle, GFP_KERNEL);
    if (!dev->dma_buf) { ret = -ENOMEM; goto fail_iomap; }

    // Allocate 1 MSI-X Vector
    ret = pci_alloc_irq_vectors(pdev, 1, 1, PCI_IRQ_MSIX);
    if (ret < 0) goto fail_dma;
    dev->irq_vec = pci_irq_vector(pdev, 0);

    ret = request_irq(dev->irq_vec, hft_dma_isr, 0, DRV_NAME, dev);
    if (ret) goto fail_irq_vec;

    // Register Character Device /dev/hft_dma0
    ret = alloc_chrdev_region(&dev->dev_num, 0, 1, DRV_NAME);
    if (ret) goto fail_free_irq;

    cdev_init(&dev->cdev, &hft_dma_fops);
    ret = cdev_add(&dev->cdev, dev->dev_num, 1);
    if (ret) goto fail_unreg_chrdev;

    dev->dev_class = class_create(DEV_CLASS_NAME);
    if (IS_ERR(dev->dev_class)) { ret = PTR_ERR(dev->dev_class); goto fail_cdev_del; }

    dev->device = device_create(dev->dev_class, NULL, dev->dev_num, NULL, "hft_dma0");
    if (IS_ERR(dev->device)) { ret = PTR_ERR(dev->device); goto fail_class_destroy; }

    pci_set_drvdata(pdev, dev);
    pr_info(DRV_NAME ": Device Probe Successful. Bound to /dev/hft_dma0\n");
    return 0;

fail_class_destroy: class_destroy(dev->dev_class);
fail_cdev_del:      cdev_del(&dev->cdev);
fail_unreg_chrdev:  unregister_chrdev_region(dev->dev_num, 1);
fail_free_irq:      free_irq(dev->irq_vec, dev);
fail_irq_vec:       pci_free_irq_vectors(pdev);
fail_dma:           dma_free_coherent(&pdev->dev, dev->dma_buf_size, dev->dma_buf, dev->dma_handle);
fail_iomap:         pci_iounmap(pdev, dev->csr_bar);
fail_regions:       pci_release_regions(pdev);
fail_disable:       pci_disable_device(pdev);
    return ret;
}

static void hft_dma_remove(struct pci_dev *pdev)
{
    struct hft_dma_dev *dev = pci_get_drvdata(pdev);

    device_destroy(dev->dev_class, dev->dev_num);
    class_destroy(dev->dev_class);
    cdev_del(&dev->cdev);
    unregister_chrdev_region(dev->dev_num, 1);
    free_irq(dev->irq_vec, dev);
    pci_free_irq_vectors(pdev);
    dma_free_coherent(&pdev->dev, dev->dma_buf_size, dev->dma_buf, dev->dma_handle);
    pci_iounmap(pdev, dev->csr_bar);
    pci_release_regions(pdev);
    pci_disable_device(pdev);
    pr_info(DRV_NAME ": Device Unloaded Successfully\n");
}

static const struct pci_device_id hft_dma_ids[] = {
    { PCI_DEVICE(VENDOR_ID, DEVICE_ID) },
    { 0, }
};
MODULE_DEVICE_TABLE(pci, hft_dma_ids);

static struct pci_driver hft_dma_driver = {
    .name     = DRV_NAME,
    .id_table = hft_dma_ids,
    .probe    = hft_dma_probe,
    .remove   = hft_dma_remove,
};

module_pci_driver(hft_dma_driver);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("FPGA HFT Hardware Team");
MODULE_DESCRIPTION("Production PCIe Scatter-Gather DMA Driver for Ultra-Low Latency Feed Handler");

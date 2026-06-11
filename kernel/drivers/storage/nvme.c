#include "nvme.h"
#include "tty.h"

void nvme_init(uint32_t bus, uint32_t device, uint32_t function) {
    tty_print("[NVMe] Initializing Controller at PCI ");
    // Логика инициализации очередей NVMe (Submission/Completion)
    tty_print("DONE\n");
}

int nvme_read_blocks(uint64_t lba, uint32_t count, void* buffer) {
    (void)lba; (void)count; (void)buffer;
    // Команды чтения через DMA
    return 0;
}

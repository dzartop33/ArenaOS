#ifndef NVME_H
#define NVME_H

#include <stdint.h>

typedef struct {
    uint32_t bus;
    uint32_t device;
    uint32_t function;
    uint64_t bar0;
} nvme_device_t;

void nvme_init(uint32_t bus, uint32_t device, uint32_t function);
int nvme_read_blocks(uint64_t lba, uint32_t count, void* buffer);
int nvme_write_blocks(uint64_t lba, uint32_t count, const void* buffer);

#endif

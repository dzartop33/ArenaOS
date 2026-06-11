#ifndef GPT_H
#define GPT_H

#include <stdint.h>

typedef struct {
    uint8_t signature[8]; // "EFI PART"
    uint32_t revision;
    uint32_t header_size;
    uint32_t crc32;
    uint32_t reserved;
    uint64_t current_lba;
    uint64_t backup_lba;
    uint64_t first_usable_lba;
    uint64_t last_usable_lba;
    uint8_t disk_guid[16];
    uint64_t partition_entry_lba;
    uint32_t num_partitions;
    uint32_t partition_entry_size;
} __attribute__((packed)) gpt_header_t;

typedef struct {
    uint8_t type_guid[16];
    uint8_t unique_guid[16];
    uint64_t start_lba;
    uint64_t end_lba;
    uint64_t attributes;
    uint16_t name[36];
} __attribute__((packed)) gpt_entry_t;

int gpt_parse(void* disk_data);

#endif

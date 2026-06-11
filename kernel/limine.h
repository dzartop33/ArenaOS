#ifndef LIMINE_H
#define LIMINE_H 1

#include <stdint.h>

#define LIMINE_COMMON_MAGIC 0xc7b1dd3027952588, 0x8c86611264274951

struct limine_uuid {
    uint32_t a;
    uint16_t b;
    uint16_t c;
    uint8_t d[8];
};

#define LIMINE_PTR(TYPE) TYPE*

struct limine_framebuffer {
    uint64_t address;
    uint64_t width;
    uint64_t height;
    uint64_t pitch;
    uint16_t bpp;
    uint8_t memory_model;
    uint8_t red_mask_size;
    uint8_t red_mask_shift;
    uint8_t green_mask_size;
    uint8_t green_mask_shift;
    uint8_t blue_mask_size;
    uint8_t blue_mask_shift;
    uint8_t unused[7];
    uint64_t edid_size;
    uint64_t edid;
};

struct limine_framebuffer_request {
    uint64_t id[4];
    uint64_t revision;
    struct limine_framebuffer_response *response;
};

struct limine_framebuffer_response {
    uint64_t revision;
    uint64_t framebuffer_count;
    struct limine_framebuffer **framebuffers;
};

struct limine_smp_info {
    uint32_t processor_id;
    uint32_t lapic_id;
    uint64_t reserved;
    void (*goto_address)(struct limine_smp_info *);
    uint64_t extra_argument;
};

struct limine_smp_response {
    uint64_t revision;
    uint32_t flags;
    uint32_t bsp_lapic_id;
    uint64_t cpu_count;
    struct limine_smp_info **cpus;
};

struct limine_smp_request {
    uint64_t id[4];
    uint64_t revision;
    struct limine_smp_response *response;
};

struct limine_memmap_entry {
    uint64_t base;
    uint64_t length;
    uint64_t type;
};

#define LIMINE_MEMMAP_USABLE 0

struct limine_memmap_response {
    uint64_t revision;
    uint64_t entry_count;
    struct limine_memmap_entry **entries;
};

struct limine_memmap_request {
    uint64_t id[4];
    uint64_t revision;
    struct limine_memmap_response *response;
};

#endif

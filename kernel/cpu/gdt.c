#include "cpu/gdt.h"

struct gdt_entry gdt[7];
struct gdt_ptr gdt_p;
struct tss_entry tss;

extern void gdt_flush(struct gdt_ptr* ptr);

void gdt_init(void) {
    // Null segment
    gdt[0] = (struct gdt_entry){0, 0, 0, 0, 0, 0};
    
    // Kernel Code 64
    gdt[1] = (struct gdt_entry){0, 0, 0, 0x9A, 0x20, 0};
    
    // Kernel Data 64
    gdt[2] = (struct gdt_entry){0, 0, 0, 0x92, 0x00, 0};
    
    // User Data 64
    gdt[3] = (struct gdt_entry){0, 0, 0, 0xF2, 0x00, 0};
    
    // User Code 64
    gdt[4] = (struct gdt_entry){0, 0, 0, 0xFA, 0x20, 0};

    // TSS (takes 2 slots)
    uint64_t tss_base = (uint64_t)&tss;
    gdt[5].limit_low = sizeof(struct tss_entry);
    gdt[5].base_low = tss_base & 0xFFFF;
    gdt[5].base_middle = (tss_base >> 16) & 0xFF;
    gdt[5].access = 0x89;
    gdt[5].granularity = 0x00;
    gdt[5].base_high = (tss_base >> 24) & 0xFF;
    
    *((uint64_t*)&gdt[6]) = (tss_base >> 32);

    gdt_p.limit = sizeof(gdt) - 1;
    gdt_p.base = (uint64_t)&gdt;
    
    gdt_flush(&gdt_p);
}

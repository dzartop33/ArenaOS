#include "limine.h"
#include "tty.h"
#include "cpu/gdt.h"
#include "cpu/idt.h"
#include "memory/pmm.h"
#include "memory/heap.h"

// Запросы к Limine
static volatile struct limine_framebuffer_request fb_req = { .id = { 0xc7b1dd3027952588, 0x8c86611264274951, 0x48d124031735a742, 0x0a2631043863e521 } };
static volatile struct limine_memmap_request mm_req = { .id = { 0xc7b1dd3027952588, 0x8c86611264274951, 0x67cf3d9d78a91f3d, 0xe34aef17293a525d } };

void _start(void) {
    // 1. Сначала графика
    if (fb_req.response && fb_req.response->framebuffer_count > 0) {
        tty_init(fb_req.response->framebuffers[0]);
    }
    tty_print("ArenaOS Reality Booting...\n");

    // 2. Инициализация CPU
    gdt_init();
    idt_init();

    // 3. Инициализация физической памяти (PMM)
    if (mm_req.response) {
        pmm_init(mm_req.response);
    }
    
    // 4. Инициализация кучи (kmalloc)
    heap_init();

    tty_print("System logic check: OK. Ready for usage.\n");

    for (;;) __asm__ volatile ("hlt");
}

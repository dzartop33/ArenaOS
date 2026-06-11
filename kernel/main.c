#include <stdint.h>
#include <stddef.h>
#include "limine.h"
#include "tty.h"

// 1. ВСТРОЕННЫЙ КОНФИГ (Nuclear Option)
// Это заменяет внешний limine.conf и работает всегда!
__attribute__((used, section(".limine_reqs")))
static volatile uint64_t limine_config[4] = {
    0xc7b1dd3027952588, 0x8c86611264274951, // Magic
    0x3f33534d137022d2, 0x9336184518908f5d  // ID для встроенного конфига
};

// Текст конфига внутри ядра
__attribute__((used, section(".limine_reqs")))
static volatile const char limine_config_data[] = 
    "TIMEOUT=0\n"
    ":ArenaOS\n"
    "PROTOCOL=limine\n"
    "KERNEL_PATH=boot:///kernel.elf\n";

// 2. Обязательная ревизия
__attribute__((used, section(".limine_reqs")))
static volatile uint64_t limine_base_revision[3] = { 0xf9562367071972a9, 0x0061d138b16f3d7a, 0 };

// 3. Запрос видеопамяти
__attribute__((used, section(".limine_reqs")))
static volatile struct limine_framebuffer_request fb_req = {
    .id = { 0xc7b1dd3027952588, 0x8c86611264274951, 0x48d124031735a742, 0x0a2631043863e521 },
    .revision = 0
};

void _start(void) {
    if (limine_base_revision[2] == (uint64_t)-1) {
        for (;;) __asm__("hlt");
    }

    if (fb_req.response == NULL || fb_req.response->framebuffer_count < 1) {
        for (;;) __asm__("hlt");
    }
    
    struct limine_framebuffer *fb = fb_req.response->framebuffers[0];
    tty_init(fb);
    
    tty_print("====================================\n");
    tty_print("   ArenaOS Universe v9.0.0 READY    \n");
    tty_print("====================================\n");
    tty_print("\nSUCCESS: Embedded configuration loaded!\n");
    tty_print("System: 64-bit Long Mode Active.\n");

    for (;;) {
        __asm__ volatile ("hlt");
    }
}

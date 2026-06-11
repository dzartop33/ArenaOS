#include <stdint.h>
#include <stddef.h>
#include "limine.h"
#include "tty.h"

__attribute__((used, section(".limine_reqs"), aligned(8)))
static volatile uint64_t limine_base_revision[3] = { 0xf9562367071972a9, 0x0061d138b16f3d7a, 0 };

__attribute__((used, section(".limine_reqs"), aligned(8)))
static volatile struct limine_framebuffer_request fb_req = {
    .id = { 0xc7b1dd3027952588, 0x8c86611264274951, 0x48d124031735a742, 0x0a2631043863e521 },
    .revision = 0
};

void _start(void) {
    if (fb_req.response == NULL || fb_req.response->framebuffer_count < 1) {
        for (;;) __asm__("hlt");
    }
    
    struct limine_framebuffer *fb = fb_req.response->framebuffers[0];
    tty_init(fb);
    
    tty_print("ARENA OS: ONLINE\n");
    tty_print("----------------\n");
    tty_print("Bootloader Limine 8.x: Connected\n");
    tty_print("Kernel: Alive\n");

    for (;;) __asm__ volatile ("hlt");
}

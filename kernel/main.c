#include <stdint.h>
#include <stddef.h>
#include "limine.h"

// Обязательная ревизия для Limine 8.x
__attribute__((used, section(".limine_reqs")))
static volatile uint64_t limine_base_revision[3] = { 0xf9562367071972a9, 0x0061d138b16f3d7a, 0 };

// Запрос видео
__attribute__((used, section(".limine_reqs")))
static volatile struct limine_framebuffer_request fb_req = {
    .id = { 0xc7b1dd3027952588, 0x8c86611264274951, 0x48d124031735a742, 0x0a2631043863e521 },
    .revision = 0
};

void _start(void) {
    // Простейшая проверка: если видео есть, закрасим экран красным
    if (fb_req.response != NULL && fb_req.response->framebuffer_count > 0) {
        struct limine_framebuffer *fb = fb_req.response->framebuffers[0];
        uint32_t *fb_ptr = (uint32_t *)fb->address;
        for (size_t i = 0; i < fb->width * fb->height; i++) {
            fb_ptr[i] = 0xFF0000; // Red
        }
    }

    for (;;) {
        __asm__ volatile ("hlt");
    }
}

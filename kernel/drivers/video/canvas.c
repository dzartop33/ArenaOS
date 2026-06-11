#include "drivers/video/canvas.h"

static struct limine_framebuffer *active_fb;

void canvas_init(struct limine_framebuffer *fb) {
    active_fb = fb;
}

void canvas_blit(void) {
    // Копирование из заднего буфера в VRAM
}

void draw_rect(int x, int y, int w, int h, uint32_t color) {
    (void)x; (void)y; (void)w; (void)h; (void)color;
}

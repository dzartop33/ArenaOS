#include "tty.h"
#include "fonts/font8x16.h"

static struct limine_framebuffer *fb;
static uint32_t cursor_x = 0;
static uint32_t cursor_y = 0;
static uint32_t fg_color = 0xFFFFFFFF;
static uint32_t bg_color = 0x00000000;

void tty_init(struct limine_framebuffer *framebuffer) {
    fb = framebuffer;
    tty_clear();
}

void tty_clear(void) {
    uint32_t *ptr = (uint32_t *)fb->address;
    for (size_t i = 0; i < (fb->pitch / 4) * fb->height; i++) {
        ptr[i] = bg_color;
    }
    cursor_x = 0;
    cursor_y = 0;
}

static void draw_char(char c, uint32_t x, uint32_t y) {
    if (c < 0) return;
    uint32_t *ptr = (uint32_t *)fb->address;
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 8; j++) {
            if ((font_8x16[(uint8_t)c * 16 + i] >> (7 - j)) & 1) {
                ptr[(y + i) * (fb->pitch / 4) + (x + j)] = fg_color;
            }
        }
    }
}

void tty_putchar(char c) {
    if (c == '\n') {
        cursor_x = 0;
        cursor_y += 16;
    } else {
        draw_char(c, cursor_x, cursor_y);
        cursor_x += 8;
        if (cursor_x >= fb->width) {
            cursor_x = 0;
            cursor_y += 16;
        }
    }
    
    // Простейшая прокрутка
    if (cursor_y + 16 >= fb->height) {
        tty_clear(); // Пока просто очищаем
    }
}

void tty_print(const char *str) {
    while (*str) {
        tty_putchar(*str++);
    }
}

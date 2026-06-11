#ifndef TTY_H
#define TTY_H

#include <stdint.h>
#include <stddef.h>
#include "limine.h"

void tty_init(struct limine_framebuffer *fb);
void tty_putchar(char c);
void tty_print(const char *str);
void tty_set_color(uint32_t fg, uint32_t bg);
void tty_clear(void);

#endif

#ifndef CANVAS_H
#define CANVAS_H

#include <stdint.h>
#include "limine.h"

void canvas_init(struct limine_framebuffer *fb);
void canvas_blit(void);
void draw_rect(int x, int y, int w, int h, uint32_t color);

#endif

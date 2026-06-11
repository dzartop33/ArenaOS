#ifndef COMPOSITOR_H
#define COMPOSITOR_H

#include <stdint.h>

void compositor_render_frame(void);
void apply_blur(int x, int y, int w, int h);

#endif

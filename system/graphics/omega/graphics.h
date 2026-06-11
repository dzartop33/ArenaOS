#ifndef OMEGA_GFX_H
#define OMEGA_GFX_H

#include <stdint.h>

typedef struct {
    uint32_t width;
    uint32_t height;
    uint32_t refresh_rate;
    uint8_t hdr_enabled;
} omega_display_mode_t;

void omega_gfx_init(void);
void omega_gfx_set_mode(omega_display_mode_t mode);
void omega_gfx_submit_command_buffer(void *buffer); // Vulkan-like

#endif

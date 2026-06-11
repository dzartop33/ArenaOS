#ifndef HAL_H
#define HAL_H

#include <stdint.h>

typedef struct {
    void (*reboot)(void);
    void (*shutdown)(void);
    void (*get_cpu_vendor)(char *out);
} hal_ops_t;

void hal_init(void);
hal_ops_t *hal_get_ops(void);

#endif

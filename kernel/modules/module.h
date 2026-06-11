#ifndef MODULE_H
#define MODULE_H

#include <stdint.h>

typedef struct {
    char name[32];
    int (*init)(void);
    void (*exit)(void);
} module_t;

int module_load(const char *path);
int module_unload(const char *name);

#endif

#ifndef OMEGA_FS_H
#define OMEGA_FS_H

#include <stdint.h>

typedef struct {
    uint8_t hash[32]; // SHA-256 integrity
    uint64_t timestamp;
    uint32_t flags;
} omega_fs_entry_t;

void omega_fs_init(void);
int omega_fs_self_heal(void);
void omega_fs_snapshot_create(const char *label);

#endif

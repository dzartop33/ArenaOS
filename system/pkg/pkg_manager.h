#ifndef OMEGA_PKG_H
#define OMEGA_PKG_H

#include <stdint.h>

typedef struct {
    char name[64];
    char version[16];
    uint8_t signature[256]; // Nexus Security Omega Signature
    uint64_t payload_offset;
} omega_pkg_header_t;

int pkg_verify_and_install(const char *path);
int pkg_rollback(const char *name);

#endif

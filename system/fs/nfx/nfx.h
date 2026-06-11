#ifndef NFX_H
#define NFX_H

#include <stdint.h>

#define NFX_MAGIC 0x4F4D454741465358 // "OMEGAFSX"

typedef struct {
    uint64_t magic;
    uint64_t version;
    uint64_t block_size;
    uint64_t journal_start;
    uint64_t root_inode;
} nfx_superblock_t;

typedef struct {
    uint32_t uid;
    uint32_t gid;
    uint32_t mode;
    uint64_t size;
    uint64_t blocks[12];
    uint64_t checksum; // Контроль целостности Omega
} nfx_inode_t;

void nfx_init(void);
int nfx_create_snapshot(const char *name);

#endif

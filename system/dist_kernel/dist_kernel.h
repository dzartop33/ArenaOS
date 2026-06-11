#ifndef DIST_KERNEL_H
#define DIST_KERNEL_H

#include <stdint.h>

typedef struct {
    char node_name[64];
    uint32_t cpu_cores;
    uint64_t ram_total;
    uint32_t status;
} cluster_node_t;

void dist_kernel_init(void);
int dist_kernel_join_cluster(const char *master_ip);
void dist_kernel_offload_task(void (*task_ptr)(void));

#endif

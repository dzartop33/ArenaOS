#ifndef SMP_H
#define SMP_H

#include <stdint.h>

typedef struct {
    uint32_t lapic_id;
    uint32_t processor_id;
    uint32_t flags;
} cpu_info_t;

void smp_init(void);
void smp_boot_aps(void);
int smp_get_cpu_count(void);

#endif

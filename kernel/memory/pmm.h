#ifndef PMM_H
#define PMM_H

#include <stdint.h>

void pmm_init(void *memmap_response);
void *pmm_alloc(void);
void pmm_free(void *ptr);

#endif

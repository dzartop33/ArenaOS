#ifndef NPU_H
#define NPU_H

#include <stdint.h>

// Типы ускорителей
#define AI_ACCEL_CPU 0
#define AI_ACCEL_GPU 1
#define AI_ACCEL_NPU 2

typedef struct {
    uint32_t type;
    uint64_t memory_base;
    uint64_t memory_size;
    char name[64];
} ai_device_t;

void ai_driver_init(void);
void *ai_map_model_memory(uint64_t size);
void ai_unmap_model_memory(void *ptr);

#endif

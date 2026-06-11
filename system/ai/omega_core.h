#ifndef OMEGA_AI_CORE_H
#define OMEGA_AI_CORE_H

#include <stdint.h>

typedef struct {
    char key[64];
    char value[1024];
    uint64_t last_accessed;
} ai_memory_entry_t;

void omega_ai_init(void);
char* omega_ai_process_command(const char *natural_language_input);
void omega_ai_learn(const char *key, const char *value);

#endif

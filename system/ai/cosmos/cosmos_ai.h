#ifndef COSMOS_AI_H
#define COSMOS_AI_H

#include <stdint.h>

typedef enum {
    AI_MODEL_LLAMA_3,
    AI_MODEL_MISTRAL,
    AI_MODEL_STABLE_CODE,
    AI_MODEL_CUSTOM
} cosmos_ai_model_t;

typedef struct {
    char personality_name[64];
    uint32_t automation_level;
    uint32_t communication_style; // 0: Professional, 1: Technical, 2: Creative
} cosmos_personality_t;

void cosmos_ai_hypercore_init(void);
void cosmos_ai_switch_model(cosmos_ai_model_t model);
char* cosmos_ai_infer_multi(const char *prompt);

#endif

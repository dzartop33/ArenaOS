#ifndef LIBAI_H
#define LIBAI_H

#include <stdint.h>

typedef struct {
    char name[128];
    uint64_t param_count;
    uint32_t type; // GGUF, ONNX, etc.
    void *data;
} ai_model_t;

ai_model_t *ai_load_model(const char *path);
int ai_unload_model(ai_model_t *model);
char *ai_infer(ai_model_t *model, const char *prompt);

#endif

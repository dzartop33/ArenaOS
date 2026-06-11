#ifndef QUANTUM_SEC_H
#define QUANTUM_SEC_H

#include <stdint.h>

void quantum_security_init(void);
int quantum_verify_module(void *module_ptr, uint64_t size);
void quantum_protect_memory(uint64_t start, uint64_t end);

#endif

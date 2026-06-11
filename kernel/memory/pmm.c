#include "pmm.h"
#include <stddef.h>
#include "limine.h"

static uint8_t *bitmap;
static uint64_t total_pages;

void pmm_init(void *response) {
    struct limine_memmap_response *res = response;
    
    uint64_t top_address = 0;
    for (uint64_t i = 0; i < res->entry_count; i++) {
        if (res->entries[i]->type == LIMINE_MEMMAP_USABLE) {
            top_address = res->entries[i]->base + res->entries[i]->length;
        }
    }
    
    total_pages = top_address / 4096;
    // Берем начало первой области под битмап (Higher Half offset обычно 0xFFFF800000000000)
    bitmap = (uint8_t *)(res->entries[0]->base + 0xFFFF800000000000); 
    for (uint64_t i = 0; i < total_pages / 8; i++) bitmap[i] = 0;
}

void *pmm_alloc(void) {
    // Basic allocation logic
    return NULL;
}

void pmm_free(void *ptr) {
    (void)ptr;
}

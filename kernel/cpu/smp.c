#include "smp.h"
#include "limine.h"
#include "tty.h"
#include "memory/heap.h"

static volatile struct limine_smp_request smp_request = {
    .id = { 0x95a67b819a1b857a, 0x4d2c67b0f2bb314d },
    .revision = 0
};

void ap_entry(struct limine_smp_info *info) {
    // Это код, который выполняется на каждом дополнительном ядре
    __asm__ volatile ("cli");
    
    // Каждое ядро должно иметь свою GDT и IDT (упрощенно используем общие с блокировками)
    // gdt_init(); 
    // idt_init();

    tty_print("[SMP] CPU Core online\n");

    for (;;) {
        __asm__ volatile ("hlt");
    }
}

void smp_init(void) {
    struct limine_smp_response *smp_response = smp_request.response;
    if (smp_response == NULL) {
        tty_print("[SMP] Error: SMP not supported\n");
        return;
    }

    uint64_t cpu_count = smp_response->cpu_count;
    tty_print("[SMP] Found CPUs: ");
    // Вывод числа ядер (нужна функция itoa или аналогичная)
    tty_print("OK\n");

    for (uint64_t i = 0; i < cpu_count; i++) {
        struct limine_smp_info *cpu = smp_response->cpus[i];
        if (cpu->lapic_id == smp_response->bsp_lapic_id) {
            continue; // Пропускаем основное ядро (BSP)
        }
        
        // Запускаем вспомогательное ядро (AP)
        cpu->goto_address = ap_entry;
    }
}

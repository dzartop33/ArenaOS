#include "cpu/idt.h"
#include "tty.h"

struct idt_entry idt[256];
struct idt_ptr idt_p;

extern void isr0();
extern void isr1();
// ... (другие заглушки)
extern void irq0();
extern void irq1();

void idt_set_gate(uint8_t num, uint64_t base, uint16_t sel, uint8_t flags) {
    idt[num].offset_low = base & 0xFFFF;
    idt[num].offset_middle = (base >> 16) & 0xFFFF;
    idt[num].offset_high = (base >> 32) & 0xFFFFFFFF;
    idt[num].selector = sel;
    idt[num].ist = 0;
    idt[num].type_attr = flags;
    idt[num].reserved = 0;
}

void idt_init(void) {
    idt_p.limit = sizeof(idt) - 1;
    idt_p.base = (uint64_t)&idt;

    // В реальности здесь должен быть цикл или макрос для всех 32 исключений
    idt_set_gate(0, (uint64_t)isr0, 0x08, 0x8E);
    idt_set_gate(1, (uint64_t)isr1, 0x08, 0x8E);
    // ...
    idt_set_gate(32, (uint64_t)irq0, 0x08, 0x8E); // Timer
    idt_set_gate(33, (uint64_t)irq1, 0x08, 0x8E); // Keyboard

    __asm__ volatile ("lidt %0" : : "m"(idt_p));
}

void isr_handler(struct interrupt_frame *frame) {
    if (frame->int_no < 32) {
        tty_print("CPU EXCEPTION\n");
        for(;;);
    }
    
    if (frame->int_no >= 32 && frame->int_no < 48) {
        // Handle IRQ
        if (frame->int_no == 32) {
            // Timer
        }
        // Send EOI to PIC (simple)
        if (frame->int_no >= 40) __asm__ volatile ("outb %0, $0xA0" : : "a"((uint8_t)0x20));
        __asm__ volatile ("outb %0, $0x20" : : "a"((uint8_t)0x20));
    }
}

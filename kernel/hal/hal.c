#include "hal.h"
#include "tty.h"
#include "string.h"

static void x86_64_reboot(void) {
    uint8_t good = 0x02;
    while (good & 0x02) {
        __asm__ volatile("inb $0x64" : "=a"(good));
    }
    __asm__ volatile("outb %0, $0x64" : : "a"((uint8_t)0xFE));
}

static hal_ops_t x86_64_ops = {
    .reboot = x86_64_reboot,
    .shutdown = (void*)0,
};

void hal_init(void) {
    tty_print("[HAL] Hardware Abstraction Layer active for x86_64.\n");
}

hal_ops_t *hal_get_ops(void) {
    return &x86_64_ops;
}

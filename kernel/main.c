#include <stdint.h>
#include <stddef.h>
#include "limine.h"
#include "tty.h"

// Обязательная структура для Limine 5.x - 8.x
// Сообщает загрузчику, что ядро понимает современный протокол
__attribute__((used, section(".limine_reqs")))
static volatile uint64_t limine_base_revision[3] = { 0xf9562367071972a9, 0x0061d138b16f3d7a, 0 };

// Запрос на получение доступа к видеопамяти (Framebuffer)
__attribute__((used, section(".limine_reqs")))
static volatile struct limine_framebuffer_request fb_req = {
    .id = { 0xc7b1dd3027952588, 0x8c86611264274951, 0x48d124031735a742, 0x0a2631043863e521 },
    .revision = 0
};

// Функция бесконечного ожидания (Halt)
static void hcf(void) {
    __asm__ volatile ("cli");
    for (;;) {
        __asm__ volatile ("hlt");
    }
}

void _start(void) {
    // Проверка совместимости протокола
    if (limine_base_revision[2] == (uint64_t)-1) {
        hcf();
    }

    // Проверка: получили ли мы доступ к видео
    if (fb_req.response == NULL || fb_req.response->framebuffer_count < 1) {
        hcf();
    }
    
    // Берем первый доступный фреймбуфер
    struct limine_framebuffer *fb = fb_req.response->framebuffers[0];
    
    // Инициализируем наш текстовый терминал
    tty_init(fb);
    
    // Выводим приветственное сообщение
    tty_print("ArenaOS Reality [BUILD 8.7.0-FIXED]\n");
    tty_print("------------------------------------\n");
    tty_print("SUCCESS: Bootloader and Kernel connected!\n");
    tty_print("Status: CPU initialized, Graphics online.\n");
    tty_print("\nWelcome to your own Operating System!\n");

    // Ядро закончило работу, замираем
    hcf();
}

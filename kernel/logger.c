#include "tty.h"
#include <stdarg.h>

void log_kernel(const char* fmt, ...) {
    // В реальности: запись в кольцевой буфер и на диск /var/log/kernel.log
    tty_print("[LOG] ");
    tty_print(fmt);
    tty_print("\n");
}

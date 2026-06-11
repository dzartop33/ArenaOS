CC = gcc
LD = ld
AS = as

# Пути для Reality v9.0.0
CFLAGS = -Wall -Wextra -std=c11 -ffreestanding -fno-stack-protector -fno-stack-check -fno-lto -fPIE -m64 -march=x86-64 -mno-80387 -mno-mmx -mno-sse -mno-sse2 -mno-red-zone -Ikernel -I. -Isystem/ai/universe -Isystem/fs/omega_fs -Ikernel/hal
LDFLAGS = -T kernel/linker.ld -static -nostdlib -no-pie -z max-page-size=0x1000

# Исключаем installer из ядра
C_SOURCES = $(sort $(shell find kernel -name "*.c") $(shell find system -name "*.c" ! -path "system/installer/*"))
ASM_SOURCES = $(sort $(shell find kernel -name "*.s"))
OBJECTS = $(C_SOURCES:.c=.o) $(ASM_SOURCES:.s=.o)

all: kernel.elf installer.bin

kernel.elf: $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) -o $@

installer.bin: system/installer/main.c
	# Компилируем инсталлер как пользовательское приложение (упрощенно)
	$(CC) -O2 system/installer/main.c -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(AS) $< -o $@

clean:
	rm -rf $(OBJECTS) system/installer/*.o kernel.elf installer.bin ArenaOS-Reality.iso iso_root

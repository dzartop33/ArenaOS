CC = gcc
LD = ld
AS = as

CFLAGS = -Wall -Wextra -std=c11 -ffreestanding -fno-stack-protector -fno-stack-check -fPIE -m64 -march=x86-64 -mno-80387 -mno-mmx -mno-sse -mno-sse2 -mno-red-zone -Ikernel -I.
LDFLAGS = -T kernel/linker.ld -static -nostdlib -no-pie -z max-page-size=0x1000

# ВАЖНО: main.o должен быть первым в списке OBJECTS
C_SOURCES = kernel/main.c kernel/tty.c kernel/string.c kernel/fonts/font8x16.c
OBJECTS = kernel/main.o kernel/tty.o kernel/string.o kernel/fonts/font8x16.o

all: kernel.elf

kernel.elf: $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf kernel/*.o kernel.elf

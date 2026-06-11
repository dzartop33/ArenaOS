.intel_syntax noprefix
.global gdt_flush

gdt_flush:
    lgdt [rdi]
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    
    # В 64-битном режиме retfq используется для дальнего возврата
    # Но проще сделать far jmp через стек
    pop rsi              # Возвращаем адрес возврата
    mov rax, 0x08        # Сегмент кода
    push rax             # Push CS
    push rsi             # Push RIP
    lretq

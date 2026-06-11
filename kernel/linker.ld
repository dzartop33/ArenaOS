OUTPUT_FORMAT(elf64-x86-64)
ENTRY(_start)

PHDRS
{
    limine_requests PT_LOAD FLAGS(0x07); /* Read/Write/Execute */
    text PT_LOAD FLAGS(0x05);            /* Read/Execute */
    rodata PT_LOAD FLAGS(0x04);          /* Read Only */
    data PT_LOAD FLAGS(0x06);            /* Read/Write */
}

SECTIONS
{
    . = 0xffffffff80000000;

    /* Секция запросов Limine ДОЛЖНА быть первой */
    .limine_reqs : {
        KEEP(*(.limine_reqs))
    } :limine_requests

    .text : {
        *(.text .text.*)
    } :text

    .rodata : {
        *(.rodata .rodata.*)
    } :rodata

    .data : {
        *(.data .data.*)
    } :data

    .bss : {
        *(.bss .bss.*)
        *(COMMON)
    } :data

    /DISCARD/ : {
        *(.eh_frame)
        *(.note .note.*)
    }
}

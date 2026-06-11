#include "gpt.h"
#include "string.h"
#include "tty.h"

int gpt_parse(void* data) {
    uint8_t* ptr = (uint8_t*)data;
    // signature is 8 bytes
    const char* sig = "EFI PART";
    for(int i=0; i<8; i++) {
        if(ptr[512+i] != (uint8_t)sig[i]) return -1;
    }
    tty_print("[GPT] Valid Partition Table Found\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pdp11.h"


void w_write(Adress adr, word w) {
    assert(adr % 2 == 0);
    mem[adr] = w;
}


word w_read(Adress adr) {
    assert(adr % 2 == 0);
    return mem[adr];
}


void b_write(Adress adr, byte b) {
    if(adr % 2 == 0) {
            mem[adr] = (word)(b);
//            printf("%x\n", mem[adr]);
    }
    else{
//        printf("%02hhx", b);
        word w  = ((word)b) << 8;
//        printf("%x", b);
        mem[adr - 1] = mem[adr - 1] | w;
        printf("mem[%x] = %x\n", adr - 1,  mem[adr - 1]);
    }
}

byte b_read(Adress adr) {
    byte b;
    if(adr % 2 == 0)
        b = mem[adr] & 0xFF;
    else {
        word w = mem[adr-1];
        b = (w >> 8) & 0xFF;
    }
    return b;
}

void test_mem() {
//check ww
    Adress a = 2;
    word w0 = 0xba;//1 байт 0000абсд
    w_write(a, w0);
    word wres = w_read(2);
    printf("%x = %x\n", wres, w0);
    assert(w0 = wres);

//check bb
    Adress b = 4;
    byte b0 = 0x0a;
    b_write(b, b0);
    byte bres = b_read(b);
    printf("%02hhx = %02hhx\n", bres, b0);
    assert(b0 = bres);

//check bw
    Adress c = 5;
    byte b1 = 0xbc;
    word w = 0xbc0a;
    b_write(c, b1);
    wres = w_read(c - 1);
//  printf("%x\n", wres);
    printf("%04x = %02hhx%02hhx\n", wres, b1, b0);
    assert(wres = w);

//check wb
    Adress j = 8;
    w0 = 0x12bc;
    w_write(j, w0);
    wres = w_read(j);
    b0 = b_read(j);
    b1 = b_read(j + 1);
    printf("b0 = %02hhx\n", b0);//Внимание! можешь подумать ошибка выдаст b0 =..   
    printf("%x = %02hhx%02hhx\n", wres, b1, b0);
}

int main() {
    test_mem();
    return 0;
}

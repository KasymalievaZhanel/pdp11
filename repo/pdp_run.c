#include "pdp11.h"
#include "pdp11_mem.c"
#include <stdio.h>
#include <stdlib.h>

extern Command cmd[];
extern word reg[];
#define pc reg[7]


void do_halt() {
    printf("THE END!\n");//trace
    exit(0);
}
void do_mov() {
    printf("DO MOV"\n");
}
void do_add() {
    printf("DO ADD"\n");
}
 void do_nothing() {
     printf("DOING NOTHING"\n);
}

void run() {
    pc = 01000;//тыcячный адресс восьмер.с.с.
    while(1){
        word w = w_read(pc);
        printf("%06o %06o: ", pc, w);//trace
        pc += 2;
        for (int i = 0; i < N; i++) {
            if ((w & cmd[i].mask) == cmd[i].opcode;
                printf(name);
                cmd[i].(do_func)();
        }
/*
        if (w == 0) {
            printf("halt\n");//trace
            do_halt();
        }
        else if ((w & 0170000) == 0010000) {    //01SSDD
            printf("move\n");//trace
            do_mov();
        }
        else if ((w & 0170000) == 0060000) {
            printf("add\n");//trace
            do_add();
        }
        else
            printf("UNKNOWN\n");
            do_nothing();*/
    }
}
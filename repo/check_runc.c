#include <stdio.h>
#include <stdlib.h>
#define MEMSIZE 65536
typedef unsigned short int word;
static word mem[MEMSIZE];
typedef word Adress;

word reg[8];
#define pc reg[7]

void do_mov() {
    printf("DO MOV\n");
}

void do_add() {
    printf("DO ADD\n");
}

typedef struct {
    word mask;
    word opcode;
    char* name;
    void (*do_func)();
} Command;
Command cmd[] = {
    {0170000, 0010000, "mov", do_mov},
    {0170000, 0060000, "add", do_add},
};

void do_halt() {
    printf("THE END!\n");//trace
    exit(0);
}

 void do_nothing() {
     printf("DOING NOTHING\n");
}

word w_read(Adress adr) {
//    assert(adr % 2 == 0);
    return mem[adr];
}
void w_write(Adress adr, word w) {
//    assert(adr % 2 == 0);
    mem[adr] = w;
}


void run() {
    pc = 01000;//тыcячный адресс восьмер.с.с.
    while(1){
        word w = w_read(pc);
        printf("%06o %06o: ", pc, w);//trace
        pc += 2;
        for (int i = 0; i < 2; i++) {
            if ((w & cmd[i].mask) == cmd[i].opcode) {
                printf(cmd[i].name);
                printf(" ");
                cmd[i].do_func();
            }
            else
                printf("Unknown");
                exit(0);
        }
    }
}

int main() {
	Adress a = 01000;
    word w0 = 0010000;//1 байт 0000абсд
    w_write(a, w0);
    word w = w_read(a);
//    printf("%0o", w);
    run();
    return 0;
}
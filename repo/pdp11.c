#include <stdio.h>//пока не знаю нужно ли здесь stdio
#include "pdp11.h"
#include "pdp11_mem.c"
#define CONST 123

int main(int args, char* argv[]) {
    FILE *fp;
    char line[CONST];
    if ((fp=fopen(argv[2], "r") ) == NULL) {
        printf("Cannot open file.\n");
        return -1;
    }
    while(1) {
        char *estr = fgets(line, CONST, fp)) 
        test_mem(*estr);
    }
    fclose(f);
/*    if (argv[1] == "-d")//нужно дописать аргументы
        debug()
    else if (argv[1] == "-t")
        trace()*/
    return 0;
}


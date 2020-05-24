#include "stdio.h"
#include "stdlib.h"
int main(int argc, char *argv[], char *env[]) {
	int i;
	printf("Количество аргументов командной строки %d \n", argc);
	printf("Аргументы командной строки:\n);
	for(i = 0; i < argc; i++)
		printf("%s\n", argv[i]);
	printf("\nАргументы состояния среды:\n");
    return 0;
}
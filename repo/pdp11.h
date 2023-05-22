#include <stdio.h>
#define MEMSIZE 65536


typedef unsigned char byte;
typedef unsigned short int word;
typedef word Adress;
/* размер памяти 64кб 2 в 10 * 2 в 6 = 2 в 16 разных адресов. 
на 1 адресс нужен 16 бит.*/


static word mem[MEMSIZE];
word reg[8];

void b_write(Adress adr, byte b);
//пишем байт b по адрессу adr
byte b_read(Adress adr);
//читаем байт b по адрессу adr

void w_write(Adress adr, word w);
//пишем слово w  по адрессу adr
word w_read(Adress adr);
//читаем слово по адресс adr

//Лучше написать для него отдельный файл
void do_mov() {}//написать реализацию функций
void do_add() {}
void do_nothing() {}


typedef struct {
    word mask;
    word opcode;
    char* name;
    void (do_func)(void);

}Command;
Command cmd[] = {
    {0170000, 0010000, "mov", do_mov},
    {0170000, 0060000, "add", do_add},
//ЗДЕСЬ НЕОБХОДИМО ДОПИСАТЬ ЕЩЕ КОМАНДЫ
}
//До сюда новый файл
/*
void debug(const char *format, arg-list);

void trace(const char *format, arg-list);
*/
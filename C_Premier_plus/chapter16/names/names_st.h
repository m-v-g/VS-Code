//константы
#include <string.h>
#define SLEN 32
//обявление структуры
struct names_st
{
    char first[SLEN];
    char last[SLEN];
};
//определение тиров
typedef struct names_st names;
//прототипы функции
void get_names(names *);
void show_names(const names *);
char * s_gets(char * st, int n);
#include <stdio.h>
#include <string.h>
char * s_gets(char * st, int n);
#define MAXTITL 41
#define MAXAUTL 31

struct book
{
    char title[MAXTITL];
    char author [MAXAUTL];
    float value;
};

int main(void)
{
    struct book library;

}

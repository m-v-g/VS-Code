#include <stdio.h>
int main(int argc, char **argv[])
{
    printf("Количество аргументов, указанных в командной строке: %d\n", argc - 1);
    for (int count = 0; count < argc; count++)
    {
        printf("%d: %s\n", count, argv[count]);
    }
    printf("\n");
    return 0;
}
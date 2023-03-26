#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int times;
    if (argc < 2 || (times = atoi(argv[1])) < 1)
    {
        printf("Использование: %s положительное-число\n", argv[0]);
    }
    else
    {
        for (int i = 0; i < times; i++)
        {
            puts("Хорошего дня!");
        }
    }
    return 0;
}
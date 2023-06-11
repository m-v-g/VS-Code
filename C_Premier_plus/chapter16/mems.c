#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10

void show_array(const int ar[], int n);
_Static_assert(sizeof(double) == 2 * sizeof(int), "double не имеет двойной размер int");

int main(void)
{
    int values[SIZE] = {1,2,3,4,5,6,7,8,9,10};
    int target[SIZE];
    double curious[SIZE / 2] = {2.0, 2.0e5, 2.0e10, 2.0e20, 2.0e30};

    puts("Использование memcpy():\nзначения (исходные данные): ");
    show_array(values, SIZE);
    memcpy(target, values, SIZE * sizeof(int));
    puts("целевые данные (копия значений): ");
    show_array(target, SIZE);

    puts("\nИспользование memmove() с перекрывающимися областями:");
    memmove(values + 2, values, 5 * sizeof(int));
    puts("значения -- элементы 0-5 скопированы в злементы 2-7:");
    show_array(values, SIZE);

    puts("\nИспользование memmove() для копирования double в int:");
    memmove(target, curious, (SIZE / 2) * sizeof(double));
    puts("целевые данные --5 значений double в 10 позициях int:");
    show_array(target, SIZE / 2);
    show_array(target + 5, SIZE / 2);

    return 0;
}

void show_array(const int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }
    putchar('\n');
}
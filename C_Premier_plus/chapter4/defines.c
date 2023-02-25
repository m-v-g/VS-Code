#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(void)
{
    puts("Некоторые пределы чисел для данной системы");
    printf("Наибольшое значение типа int: %d\n", INT_MAX);
    printf("Наибольшое значение типа long: %d\n", LLONG_MAX);
    printf("Наибольшое значение типа double: %d\n", DBL_MAX);
    printf("В данной системе один байт = %d битов\n", CHAR_BIT);
    printf("Наименшее нормализованное значение типа float: %e\n", FLT_MIN);
    printf("Точное значение типа float = %d знаков\n", FLT_DIG);
    printf("Зазниса между 1,00 и минимальним значением float, которое больше 1,00 = %e\b", FLT_EPSILON);
    return 0;
}
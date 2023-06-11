#include <stdio.h>
#include <math.h>
#include <assert.h>
#define NDEBUG //для отключения макроса
int main(void)
{
    double x, y, z;

    puts("Введите пару чисел (0 0 для завершения): ");
    while (scanf("%1f %1f", &x, &y) == 2)
    {
        z = x * x - y * y;
        assert(z >= 0);
        printf("результатом является %f\n", sqrt(z));
        puts("Введите следующую пару чисел: ");
    }
    puts("Программа завершена.");
    return 0;
}
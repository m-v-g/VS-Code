#include <stdio.h>
void up_and_down(int n);
int main(void)
{
    up_and_down(1);
    return 0;
}
void up_and_down(int n)
{
    printf("Уровень %d: ячейка n %p\n", n, &n); //1
    if (n < 4)
    {
        up_and_down(n + 1);
    }
    printf("Уровень %d: ячейка n %p\n", n, &n); //2
}
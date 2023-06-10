#include <stdio.h>
#define PSQR(x) printf("Квадрвт " #x " равен %d.\n", ((x) * (x)))
int main(void)
{
    int y = 5;
    PSQR(y);
    PSQR(2 + 5);
    return 0;
}
#include <stdio.h>
int main(void)
{
    printf("Tip int imeet razmer %zd baytov.\n", sizeof(int));
    printf("Tip char imeet razmer %zd baytov.\n", sizeof(char));
    printf("Tip long imeet razmer %zd baytov.\n", sizeof(long));
    printf("Tip long long imeet razmer %zd baytov.\n", sizeof(long long));
    printf("Tip float imeet razmer %zd baytov.\n", sizeof(float));
    printf("Tip double imeet razmer %zd baytov.\n", sizeof(double));
    printf("Tip long long imeet razmer %zd baytov.\n", sizeof(long long));
    printf("Tip long double imeet razmer %zd baytov.\n", sizeof(long double));

    return 0;
}
#include <stdio.h>
#include <string.h>
int cube(int a);
int main(void)
{
    int x = 2;
    printf("x is now %i\n", x);
    printf("Cubing...\n");
    x = cube(x);
    printf("Cubed!\n");
    printf("x is noww %i\n", x);
}

int cube(int n){
    return n * n * n;
}
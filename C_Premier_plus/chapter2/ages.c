#include <stdio.h>
#include <stdlib.h>

int ages;
int days;

int main(void)
{
    puts("enter your ages");
    scanf("%d", &ages);
    days = ages * 365;
    printf("your days is %d\n", days);
    system("pause");
}
#include <stdio.h>
#include <stdlib.h>

float inches;
float cm;

int main(void)
{
    puts("vvedide jelaemoe chislo");
    scanf("%f", &inches);
    cm = 2.54*inches;
    printf("chislo v %f dyuymax ravno %f santimetram\n", inches, cm);

    system("pause");
}
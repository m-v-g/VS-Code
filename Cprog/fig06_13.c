#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void modifyArray(int b[], size_t size);
void modifyElement(int e);

int main(void)
{
    int a[SIZE] = {0, 1, 2, 3, 4};
    size_t i;

    puts("Effects of passing entire array by referance:\n\nThe "
    "value of the original array are:");
    //vivesti originalny masiv
    for (i = 0; i < SIZE; ++i)
    {
        printf("%3d", a[i]);
    }
    puts("");
    
    //peredat po ssilke masiv a funkcii modifyArray
    modifyArray(a, SIZE);

    puts("The values of the modified array are:");

    //vivesti soderjimoe izmenennogo masiva
    for ( i = 0; i < SIZE; ++i)
    {
        printf("%3d", a[i]);
    }
    printf("\n\n\nEffects of passing array element"
    "by value:\n\nThe value of a[3] is %d\n", a[3]);

    modifyElement(a[3]); // peredat po znacheniyu element a[3]
    printf("The value of a[3] is %d\n", a[3]);


    system("pause");
}

//funkciya modifyArray, "b" ssilaetsya na originalny masiv "a" v pamyati
void modifyArray(int b[], size_t size)
{
    size_t j;

    for ( j = 0; j < size; ++j)
    {
        b[j] *= 2;
    }
    
}

//funkciya modifyElement, "e" - eto lokalnaya kopiya elementa masiva a[3] peredannogo iz funkcii main
void modifyElement(int e)
{
    printf("Value in modifyElement is %d\n", e *= 2);
}
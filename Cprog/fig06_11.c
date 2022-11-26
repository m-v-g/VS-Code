#include <stdio.h>
#include <stdlib.h>

void staticArrayInit(void);
void automaticArrayInt(void);

int main(void)
{
    puts("First call to each function:");
    staticArrayInit();
    automaticArrayInt();

    puts("\n\nSecond call to each function:");
    staticArrayInit();
    automaticArrayInt();

    system("pause");
}

void staticArrayInit(void)
{
    static int array1[3];
    size_t i;

    puts("\nValues on entering staticArrayInit:");
    for ( i = 0; i <= 2; ++i)
    {
        printf("array1[ %u ] = %d", i, array1[i]);
    }
    puts("\nValues on exiting staticArrayInit:");
    for ( i = 0; i <= 2; ++i)
    {
        printf("array1[ %u ] = %d", i, array1[i]+=5);
    }
}

void automaticArrayInt(void)
{
    static int array2[3] = {1,2,3};
    size_t i;

    puts("\nValues on entering automaticArrayInit:");
    for ( i = 0; i <= 2; ++i)
    {
        printf("array2[ %u ] = %d", i, array2[i]);
    }
    puts("\nValues on exiting automaticArrayInit:");
    for ( i = 0; i <= 2; ++i)
    {
        printf("array2[ %u ] = %d", i, array2[i]+=5);
    }
}
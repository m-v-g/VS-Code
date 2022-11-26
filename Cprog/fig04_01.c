#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int counter = 1;

    while (counter <= 10)
    {
        printf ("%u\n", counter);
        ++counter;
    }
    
    system("pause");
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
unsigned int sum = 0;
unsigned int number;
 for (number = 0; number <= 100; number += 2)
 {
     sum += number;
 }
 
    printf("Sum is %u\n", sum);
    system("pause");
}
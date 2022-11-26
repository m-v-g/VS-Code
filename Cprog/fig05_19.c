#include <stdio.h>
#include <stdlib.h>
unsigned long long int fibonacci(unsigned int n);

int main(void)
{
    unsigned long long int result;
    unsigned int number;

    printf("%s", "Enter an integer: ");
    scanf("%u", &number);

    result = fibonacci(number);

    printf("Fibonacci(%u) = %llu\n", number, result);


    system("pause");
}

unsigned long long int fibonacci(unsigned int n)
{
    if (0 == n || 1 == n)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
    
}
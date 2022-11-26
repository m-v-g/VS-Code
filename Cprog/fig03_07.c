#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int passes = 0;
    unsigned int failures = 0;
    unsigned int student = 1;
    int result;

    while (student <= 10)
    {
        printf("%s", "enter result ( 1=pass,2=fail ): ");
        scanf("%d", &result);

        if (result == 1)
        {
            passes++;
        }
        else if (result == 2)
        {
            failures++;
        }
        else
        {
            puts("incorrect result\n");
        }
        student++;
    }

    printf("passed %u\n", passes);
    printf("failed %u\n", failures);

    if (passes > 8)
    {
        puts("bonus to instructor!");
    }
    system("pause");
}
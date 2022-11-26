#include <stdio.h>
#include <stdlib.h>

int main(void)
{
int grade;
unsigned int aCount = 0;
unsigned int bCount = 0;
unsigned int cCount = 0;
unsigned int dCount = 0;
unsigned int eCount = 0;
unsigned int fCount = 0;

puts("Enter the letter grades");
puts("Enter the EOF character to end input");

while ( ( grade = getchar() ) != EOF)
{
    switch (grade)
    {
        case 'A':
        case 'a':
        ++aCount;
        break;

        case 'B':
        case 'b':
        ++bCount;
        break;

        case 'C':
        case 'c':
        ++cCount;
        break;

        case 'D':
        case 'd':
        ++dCount;
        break;

        case 'E':
        case 'e':
        ++eCount;
        break;

        case 'F':
        case 'f':
        ++fCount;
        break;

        case '\n':
        case '\t':
        case ' ':
        break;

        defult:
        printf("%s", "Incorrect letter grade entered.");
        puts("Enter a new grade.");
        break;
    }
}

puts("\nTotals for each letter grade are:");
printf("A: %u\n", aCount);
printf("B: %u\n", bCount);
printf("C: %u\n", cCount);
printf("D: %u\n", dCount);
printf("E: %u\n", eCount);
printf("F: %u\n", fCount);

    system("pause");
}
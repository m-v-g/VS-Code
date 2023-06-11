#include <stdio.h>
#include <stdlib.h>

#define NUM 40
void fillarray(double ar[], int n);
void showarray(const double ar[], int n);
int mycomp(const void * p1, const void * p2);

int main(void)
{
    double vals[NUM];
    fillarray(vals, NUM);
    puts("Список случайных чисел:");
    showarray(vals, NUM);
    qsort(vals, NUM, sizeof(double), mycomp);
    puts("\nОтсартированный список:");
    showarray(vals, NUM);
    return 0;
}

void fillarray(double ar[], int n)
{
    for (int index = 0; index < n; index++)
    {
        ar[index] = (double)rand() / ((double)rand() + 0.1);
    }
    
}
void showarray(const double ar[], int n)
{
    int index;
    for (index = 0; index < n; index++)
    {
        printf("%9.4f ", ar[index]);
        if (index % 6 == 5)
        {
            putchar('\n');
        }
    }
    if (index % 6 != 0)
    {
        putchar('\n');
    }
    
}
int mycomp(const void * p1, const void * p2)
{
    /*для доступа к значениям необхадимо использовать укозатель на double*/
    const double * a1 = (const double *) p1;
    const double * a2 = (const double *) p2;

    if (*a1 < *a2)
    {
        return -1;
    }
    else if (*a1 == *a2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    
}
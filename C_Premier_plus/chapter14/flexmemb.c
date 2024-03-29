/*член типа гибкй массив (средство С99)*/
#include <stdio.h>
#include <stdlib.h>

struct flex
{
    size_t count;
    double average;
    double scores[]; //член с типом гибкй массив
};
void showFlex(const struct flex * p);

int main(void)
{
    struct flex * pf1, * pf2;
    int n = 5;
    int tot = 0;
    /*выделение памяти для структуры и массива*/
    pf1 = malloc(sizeof(struct flex) + n * sizeof(double));
    pf1->count = n;
    for (int i = 0; i < n; i++)
    {
        pf1->scores[i] = 20.0 - i;
        tot += pf1->scores[i];
    }
    pf1->average = tot / n;
    showFlex(pf1);
    n = 9;
    tot = 0;
    /*выделение памяти для структуры и массива*/
    pf2 = malloc(sizeof(struct flex) + n * sizeof(double));
    pf2->count = n;
    for (int i = 0; i < n; i++)
    {
        pf2->scores[i] = 20.0 - i / 2.0;
        tot += pf2->scores[i];
    }
    pf2->average = tot / n;
    showFlex(pf1);
    free(pf1);
    free(pf2);
    return 0;
}

void showFlex(const struct flex * p)
{
    printf("Рейтинг: ");
    for (int i = 0; i < p->count; i++)
    {
        printf("%g ", p->scores[i]);
    }
    printf("\nСреднее значение : %g\n", p->average);
}
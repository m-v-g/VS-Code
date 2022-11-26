#include <stdio.h>
#include <stdlib.h>

int main(void)

{
    unsigned int counter;
    int grade;
    int total;
    float average;

    total =0;
    counter = 0;

    printf("%s", "Enter grade, -1 to end:");
    scanf("%d", &grade);

    while(grade != -1)
    {
        total = total + grade;
        counter++;
        printf("%s", "Enter grade, -1 to end:");
        scanf("%d", &grade);
    }

    if(counter != 0)
    {
        average = ( float ) total / counter; //chtobi izbejat usecheniya vivesti srednne s tochnostyu do 2 znaka posle zapyatoy
        /*
        pro (float) ctr 80 yavnoe i ne yavnoe priobrazovanie tipov
        */
        printf("Class average is %.2f\n", average);
    }

    else
    {
        puts("No grade were enterd");
    }
    system ("pause");
}
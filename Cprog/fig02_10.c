#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

int main(void)
{
    int num1;
    int num2;
    

    printf("Enter two integers, and I will tell you\n");
    printf("the relationships they satisfy: \n");

    scanf("%d%d", &num1, num2);

    if(num1 == num2)
    {
        printf("%d is eqal to %d\n", num1, num2);
    }
    if(num1 != num2)
    {
        printf("%d is not eqal to %d\n", num1, num2);
    }
    if(num1 < num2)
    {
        printf("%d is less then to %d\n", num1, num2);
    }
    if(num1 > num2)
    {
        printf("%d is greater then to %d\n", num1, num2);
    }
    if(num1 <= num2)
    {
        printf("%d is less then or eqal to %d\n", num1, num2);
    }
    if(num1 >= num2)
    {
        printf("%d is greater then or eqal to %d\n", num1, num2);
    }
    system ("pause");
    //getch();
   // return 0;
}
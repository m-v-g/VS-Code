#include <stdio.h>
int main(void)
{
    printf("give me an integer between1 and 10");
    int n =Getstring();
    if (n >= 1 && n <= 3){
        printf("you picked a small number\n");
    }
    else if (n >= 3 && n <= 6){
        printf("you picked medium number\n");
    }
    else if (n >= 7 && n <= 10){
        printf("you picked a big number\n");
    }
    else{
        printf("you picked an invalid number\n");
    }
}
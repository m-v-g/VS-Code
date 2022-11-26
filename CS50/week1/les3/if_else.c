#include <stdio.h>
int main(void)
{
    printf("i'd like an integer please: ");
    int n = Getint();
    if (n > 0){
        printf("you picked a positive number\n");
    }
    else if (n == 0){
        printf("You placed zero\n");
    }
    else{
        printf("You picked a negativ number\n");
    }
}
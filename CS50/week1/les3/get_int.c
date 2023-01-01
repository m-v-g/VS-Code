#include <stdio.h>
int main(void)
{
   //sprosist polzovatelya na vvod
   printf("Give me an integer: ");
   int x = Getint();
   printf("Give me another integer: ");
   int y =Getint();
   //slojit cifra
   printf("The sum of %i and %i is %i!\n", x, y, x + y);
    
}
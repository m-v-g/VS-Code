#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int frequancy1 = 0;
    unsigned int frequancy2 = 0;
    unsigned int frequancy3 = 0;
    unsigned int frequancy4 = 0;
    unsigned int frequancy5 = 0;
    unsigned int frequancy6 = 0;

    unsigned int roll; //schotchik popitok ot 1 do 6000000
    int face; //tekushaya popitka  ot 1 do 6
     for ( roll = 1; roll <= 6000000; ++roll)
     {
         face = 1 + rand() % 6; //sluchaynoe chislo 1-6
         switch (face)
         {
         case 1:
             ++frequancy1;
             break;

         case 2:
             ++frequancy2;
             break;

         case 3:
             ++frequancy3;
             break;

         case 4:
             ++frequancy4;
             break;
         
         case 5:
             ++frequancy5;
             break;

         case 6:
             ++frequancy6;
             break;
         }
     }

     printf("%s%13s\n", "Face", "Frequancy");
     printf("1%13u\n", frequancy1);
     printf("2%13u\n", frequancy2);
     printf("3%13u\n", frequancy3);
     printf("4%13u\n", frequancy4);
     printf("5%13u\n", frequancy5);
     printf("6%13u\n", frequancy6);


    system("pause");
}
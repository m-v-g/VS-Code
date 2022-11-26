
#include <stdio.h>
#include <stdlib.h>
#include <math.h>  // chtobi ispolzovat funkciyu pow

int main(void)
{
    double          amount; //summa na schete
    double          principal = 1000.0; //nachalnaya summa
    double          rate = .05; //procentnaya stavka
    unsigned int    year; //schetchik let

    //vivesti zaglavki stolbcov
    printf("%4s%21s\n", "Year", "Amount on deposit");

    //vicheslit summu na schete dlya kajdogo goda
    for (year = 1; year <= 10; ++year)
    {
        /* vicheslit novuyu summu na schete dlya ukazonnogo goda goda */
        amount = principal * pow( 1.0 + rate, year); //funkciya pow vozvedet znachenie rate v stepen year
        
        //vivesti stroku tablici
        printf("%4u%21.2f\n", year, amount); //%21.2f 21-shirina polya vivoda .2-tochnost posle zapyatoy
    }
    


    system("pause");
}
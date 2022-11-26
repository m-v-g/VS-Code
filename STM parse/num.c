#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *p; // create char pointer
char str_1[] = "+CPBR: 1,\"077057066\",129,\"a\"    OK  ";
char str_2[] = "+CPBR: 2,\"096636201\",129,\"b\"    OK  ";
char str_3[] = "+CPBR: 2,\"096636201\",129,\"b\"    OK  ";
char str_4[] = "OK  ";
char str_5[] = "OK  ";

int main( void )
{
    for (int counter = 1; counter <= 9; counter++)
    {
        char ATCPBR[11];
        snprintf(ATCPBR, 11, "AT+CPBR=%u\n", counter); //pishem v masiv soobshenie
        printf( "%s", ATCPBR );
        snprintf(p, 11, "AT+CPBR=%u\n", counter); //pishem v masiv soobshenie
    }
    
}
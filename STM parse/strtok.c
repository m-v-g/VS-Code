// Fig. 8.26: fig08_26.c
// Using function strtok
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main( void )
{ 
   // initialize array string
   int long num;
   char str[] = "+CPBR: 1,\"077057066\",129,\"a\"    OK  ";
   //char str[] = "+CSPN: \"Beeline AM\",0    OK  ";
   //char str[] = "+CSPN: \"MTS Armenia\",0    OK  ";
   char *p; // create char pointer
   
   printf( "%s\n%s\n\n%s\n",
      "The string to be tokenized is:", str, 
      "The tokens are:" );
      
   p = strtok( str, "+CPBR: ," ); // begin tokenizing sentence
   p = strtok( NULL, "\"" ); // get next token
   num = atoi(p);

   printf( "%s\n", p );
   printf( "0%u\n", num );
} // end main
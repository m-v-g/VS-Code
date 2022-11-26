#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main( void )
{
       // initialize array string
   unsigned long num;
   //char str[] = "+CMT: \"+37477057066\",\"a\",\"22/01/30,16:06:22+16\"  asd  ";
   char str[] = "+CMT: \"+37433548810\",\"\",\"22/01/30,16:07:05+16\"  Test   ";
   char *p; // create char pointer
   
   printf( "%s\n%s\n\n%s\n",
      "The string to be tokenized is:", str, 
      "The tokens are:" );
      
   p = strtok( str, "+CMT: \"+" ); // begin tokenizing sentence
   num = atol(p);

   printf( "%s\n", p );
   num = num - 37400000000;
   printf( "%lu\n", num );
}
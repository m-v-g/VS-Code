#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main( void )
{
       // initialize array string
   int long num;
   //char str[] = "RING    +CLIP: \"077057066\",129,\"\",0,\"a\",0  ";
   char str[] = "RING    +CLIP: \"033548810\",129,\"\",0,\"\",0  ";
   char *p; // create char pointer
   
   printf( "%s\n%s\n\n%s\n",
      "The string to be tokenized is:", str, 
      "The tokens are:" );
      
   p = strtok( str, "RING    +CLIP: \"" ); // begin tokenizing sentence
   //p = strtok( NULL, "\"" ); // get next token
   num = atoi(p);

   printf( "%s\n", p );
   printf( "%u\n", num );
}
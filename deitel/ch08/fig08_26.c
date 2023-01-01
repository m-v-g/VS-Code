// Fig. 8.26: fig08_26.c
// Using function strtok
#include <stdio.h>
#include <string.h>

int main( void )
{ 
   // initialize array string
   //char string[] = "+CPBR: 1,\"077057066\",129,\"a\"    OK  ";
   char string[] = "+CBC: 0,91,4131    OK  ";
   char *tokenPtr; // create char pointer
   
   printf( "%s\n%s\n\n%s\n",
      "The string to be tokenized is:", string, 
      "The tokens are:" );
      
   tokenPtr = strtok( string, " " ); // begin tokenizing sentence

   // continue tokenizing sentence until tokenPtr becomes NULL
   while ( tokenPtr != NULL ) { 
      //printf( "%s\n", tokenPtr );
      tokenPtr = strtok( NULL, "," ); // get next token
      printf( "%s\n", tokenPtr );
   } // end while
} // end main



/**************************************************************************
 * (C) Copyright 1992-2013 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
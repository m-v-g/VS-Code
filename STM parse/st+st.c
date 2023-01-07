/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main( void )
{
    char sp_str = "checing speed ";
	char sp_num[7];
    itoa(57600, sp_num, 10);
	sp_str = sp_str + *sp_num;
    //printf("hjghjgsf");
    printf(sp_str);
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
char p[17];
itoa (1423, p, 10);
//*p = " 99";
printf(p);
return 0;
}
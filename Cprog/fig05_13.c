#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    unsigned int i;
    //unsigned int seed;

    //printf ("%s", "Enter seed:");
    //scanf("%u", &seed);

    srand(time(NULL)); //funkciya time chitaet kolichestvo sekund proshedshix s polunoch 1 yanv 1970 goda
    for (i=1; i<=10; ++i)
    {
        printf("%10d", 1 + (rand() % 6));
        if (i % 5 == 0)
        {
            puts("");
        }
    }

    system("pause");
}
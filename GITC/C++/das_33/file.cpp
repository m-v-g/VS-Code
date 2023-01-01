#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
    FILE* fwptr = fopen("inc or file.txt", "w"); //grelu permition
    //FILE - @ cuyc kuda fayleri katalogi mej fayli tex@ fopen-ov kbacenq fayl@ k@ndune 2 argument
    //1-fayli anun@ 2-te inc pemitionov kbacenq ed fayl@

    char abc[] = {'a', 'b', 'c', 'd', 'e'}; 
    
    fwrite(abc, 1, 5, fwptr); //k@ndune 4 argument obekti hascen te inc bdi gre, amen praxodi chap@ u te qani angam e lcnelu u fayli pointer@

    fclose(fwptr); //fayl@ resurs e ete bacel enq uremn bdi bari exninq pakenq

    FILE* frptr = fopen("inc or file.txt", "r"); //kardalu permition

    fseek(frptr, 0L, SEEK_END); //fayli mej kursori texn e poumolchaniyu inq cuyc kuda fayli skizb@
                                //menq ktexapoxenq fayli verj u krnanq nayev smeshenni tanq 
    size_t chap = ftell(frptr); //het kveradardzne fayli bayteri chap@ 
    fseek(frptr, 0L, SEEK_SET); //berecinq kursor@ fayli skizb



    char cba[chap];
    fread(cba, 1, chap, frptr); //k@ndune 4 argument obekti hascen te inc bdi karda, amen praxodi chap@ u te qani angam e kardalu u fayli pointer@
    fclose(frptr); //fayl@ resurs e ete bacel enq uremn bdi bari exninq pakenq

    for(int i = 0; i < chap; ++i)
    {
        printf("%c\t", cba[i]);
    }

    return 0;
}
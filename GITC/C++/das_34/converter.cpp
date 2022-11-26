#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bitset>

using namespace std;

int main()
{

    


    FILE* frptr = fopen("test_source.txt", "r"); //kardalu permition

    fseek(frptr, 0L, SEEK_END); //fayli mej kursori texn e poumolchaniyu inq cuyc kuda fayli skizb@
                                //menq ktexapoxenq fayli verj u krnanq nayev smeshenni tanq 
    size_t chap = ftell(frptr); //het kveradardzne fayli bayteri chap@ 
    fseek(frptr, 0L, SEEK_SET); //berecinq kursor@ fayli skizb



    char cba[chap];

    fread(cba, 1, chap, frptr); //k@ndune 4 argument obekti hascen te inc bdi karda, amen praxodi chap@ u te qani angam e kardalu u fayli pointer@
    fclose(frptr); //fayl@ resurs e ete bacel enq uremn bdi bari exninq pakenq

    FILE* fwptr = fopen("test_destination.txt", "w"); //grelu permition
    //FILE - @ cuyc kuda fayleri katalogi mej fayli tex@ fopen-ov kbacenq fayl@ k@ndune 2 argument
    //1-fayli anun@ 2-te inc pemitionov kbacenq ed fayl@

    //unsigned char endian[2] = {0xef, 0xff};
    //unsigned char endian[2] = {0xff, 0xef};

    unsigned short endian = 0xfffe; //0xFEFF (big-endian) kam 0xFFFE (little-endian)

    fwrite(&endian, 2, 1, fwptr); //k@ndune 4 argument obekti hascen te inc bdi gre, amen praxodi chap@ u te qani angam e lcnelu u fayli pointer@
    int o = 0;
    char16_t bh = 0;
    char16_t bhShift = 0;
    char16_t bl = 0;
    char16_t blShift = 0;
    char16_t out;
    bitset<16> bitset;

    for(int i = 0; i < chap; ++i)
    {
        //printf("%i\t", cba[i]);
        

        if(cba[i] >= 0)
        {
            fwrite(&o, 1, 1, fwptr);
            fwrite(&cba[i], 1, 1, fwptr);
        }
        else
        {
            bh = cba[i]; //kardacinq
            ++i; //ancanq myus bitin
            bl = cba[i]; //kardacinq
            /*
            bitset = bh;
            cout << "bh  : " << bitset << endl;
            */
            bh = bh & 0b0000000000011111; //bazmapatkinq
            bitset = bh;
            cout << "bh& : " << bitset << endl;
            
            //bhShift = bh << 6; //shift erinq
            /*
            bitset = bhShift;
            cout << "bh< : " << bitset << endl;
            */
            
            bl = bl & 0b0000000000111111;
            bitset = bl;
            cout << "bl& : " << bitset << endl;
            blShift = bl << 7; //shift erinq
            out = blShift | bh;
            //blShift = bl << 8; //shift erinq
            bitset = out;
            cout << "out : " << bitset << endl;
            fwrite(&out, 2, 1, fwptr);
            cout << endl;
            
        }
    }

    fclose(fwptr); //fayl@ resurs e ete bacel enq uremn bdi bari exninq pakenq

    return 0;
}
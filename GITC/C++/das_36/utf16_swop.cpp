#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bitset>
#include <fstream> //poderjka failogogo vvoda vivoda

#define debug

using namespace std;


int main(int argc, char** argv)
{
    #ifdef debug
        bitset<8> bitset8;
        bitset<16> bitset16;
    #endif

    if(argc != 3)
    {
        cout << "Cлишком мало аргументов !!!" << endl;
        cout << "В качестве первого аргумента введите название исходного файла" << endl;
        cout << "А в качестве второго аргумента введите название файла назначения" << endl;
        cout << "или команду \" print \" чтобы напечатать исходный файл в бинарном виде" << endl;
        cout << "Например \" ./a.out source.txt dest.txt \" или \" ./a.out source.txt print \"" << endl;
    }
    else
    {
        size_t chap = 0;
        string str = "print";
        FILE* frptr = fopen(argv[1], "r"); //kardalu permition

        fseek(frptr, 0L, SEEK_END); //fayli mej kursori texn e poumolchaniyu inq cuyc kuda fayli skizb@
                                    //menq ktexapoxenq fayli verj u krnanq nayev smeshenni tanq 
        
        chap = (ftell(frptr)) / 2; //het kveradardzne fayli bayteri qanak@

        uint16_t array[chap]; 

        fseek(frptr, 0L, SEEK_SET); //berecinq kursor@ fayli skizb

        fread(array, 2, chap, frptr); //k@ndune 4 argument obekti hascen te inc bdi karda, amen praxodi chap@ u te qani angam e kardalu u fayli pointer@
        fclose(frptr); //fayl@ resurs e ete bacel enq uremn bdi bari exninq pakenq

        if(argv[2] == str)
        {
            for(int i = 0; i < chap; ++i)
            {
                bitset16 = array[i];
                cout << bitset16 << endl;
            }
        }
        else
        {
            if (array[0] == 0b1111111011111111 || array[0] == 0b1111111111111110)
            {
                FILE* fwptr = fopen(argv[2], "w"); //grelu permition
                //FILE - @ cuyc kuda fayleri katalogi mej fayli tex@ fopen-ov kbacenq fayl@ k@ndune 2 argument
                //1-fayli anun@ 2-te inc pemitionov kbacenq ed fayl@

                uint16_t temp1 = 0;
                uint16_t temp2 = 0;
                for(int i = 0; i < chap; ++i)
                {                          // |A|B|C|D|E|F|G|H| |a|b|c|d|e|f|g|h|
                    temp1 = array[i] << 8; // |a|b|c|d|e|f|g|h| |0|0|0|0|0|0|0|0|
                    temp2 = array[i] >> 8; // |0|0|0|0|0|0|0|0| |A|B|C|D|E|F|G|H|
                    temp2 = temp2 | temp1; // |a|b|c|d|e|f|g|h| |A|B|C|D|E|F|G|H|
                    #ifdef debug
                        bitset16 = temp1;
                        //cout << "temp1 : " << bitset16 << endl;
                        bitset16 = temp2;
                        cout << "temp2 : " << bitset16 << endl;
                    #endif
                    fwrite(&temp2, 2, 1, fwptr);
                }
                fclose(fwptr); //fayl@ resurs e ete bacel enq uremn bdi bari exninq pakenq
            }
            else
            {
                cout << "Неправельная кодировка файла" << endl;
            }
            
           
        }
    }
    

    

    return 0;
}

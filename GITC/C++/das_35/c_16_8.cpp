#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bitset>
#include <fstream> //poderjka failogogo vvoda vivoda

//#define debug

using namespace std;


int main(int argc, char** argv)
{
    bitset<8> bitset8;
    bitset<16> bitset16;
    

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
            FILE* fwptr = fopen(argv[2], "w"); //grelu permition
            //FILE - @ cuyc kuda fayleri katalogi mej fayli tex@ fopen-ov kbacenq fayl@ k@ndune 2 argument
            //1-fayli anun@ 2-te inc pemitionov kbacenq ed fayl@

            if(array[0] == 0b1111111011111111) //little endian
            {
                #ifdef debug
                    cout << "Little Endian" << endl;
                #endif
                uint16_t temp = 0;
                uint8_t tmp = 0;
                uint8_t highByte = 0;
                uint8_t lowByte = 0;
                for(int i = 1; i < chap; ++i)
                {
                    temp = array[i];
                    temp = temp >> 8;
                    
                    if(temp == 0)
                    {
                        //  |0|0|0|0|0|0|0|0| |0|a|b|c|d|e|f|g|
                        tmp = array[i]; // |0|a|b|c|d|e|f|g|
                        if(tmp != 0)
                        {
                            fwrite(&tmp, 1, 1, fwptr); //ascii
                        }
                    }
                    else
                    { //  |?|?|A|B|C|D|E|F| |G|H|a|b|c|d|e|f|
                        highByte = array[i] >> 6;         // |A|B|C|D|E|F|G|H|
                        highByte = highByte | 0b11000000; // |1|1|C|D|E|F|G|H|
                        lowByte = array[i];               // |G|H|a|b|c|d|e|f|
                        lowByte = lowByte << 2;           // |a|b|c|d|e|f|0|0|
                        lowByte = lowByte >> 2;           // |0|0|a|b|c|d|e|f|
                        lowByte = lowByte | 0b10000000;   // |1|0|a|b|c|d|e|f|
                        fwrite(&highByte, 1, 1, fwptr);
                        fwrite(&lowByte, 1, 1, fwptr);  // |1|1|C|D|E|F|G|H| |1|0|a|b|c|d|e|f|
                        #ifdef debug
                            bitset8 = highByte;
                            cout << "OUT : " << bitset8 << " ";
                            bitset8 = lowByte;
                            cout << bitset8 << endl;
                        #endif
                    }
                }
            }
            else if(array[0] == 0b1111111111111110) //big endian
            {
                #ifdef debug
                    cout << "Big endian" << endl;
                #endif
                uint16_t temp = 0;
                uint8_t temp1 = 0;
                uint16_t temp2 = 0;
                uint8_t highByte = 0;
                uint8_t lowByte = 0;
                for(int i = 1; i < chap; ++i)
                {
                    temp = array[i]; // |0|a|b|c|d|e|f|g| |0|0|0|0|0|0|0|0|
                    temp = temp << 8;// |0|0|0|0|0|0|0|0| |0|0|0|0|0|0|0|0|
                    if (temp == 0) //ascii
                    {
                        
                        temp1 = array[i] >> 8; // |0|a|b|c|d|e|f|g|
                        if(temp1 != 0)
                        {
                            fwrite(&temp1, 1, 1, fwptr); //ascii
                        }
                    }
                    else
                    { // |A|B|C|D|E|F|G|H| |a|b|c|d|e|f|g|h|
                        lowByte = array[i] >> 8;          // |A|B|C|D|E|F|G|H|
                        lowByte = lowByte & 0b00111111;   // |0|0|C|D|E|F|G|H|
                        lowByte = lowByte | 0b10000000;   // |1|0|C|D|E|F|G|H|
                        temp1 = array[i] << 2;            // |c|d|e|f|g|h|0|0|
                        temp2 = array[i] >> 14;           // |0|0|0|0|0|0|0|0| |0|0|0|0|0|0|A|B|
                        highByte = temp2;                 // |0|0|0|0|0|0|A|B|
                        highByte = highByte | temp1;      // |c|d|e|f|g|h|A|B|
                        highByte = highByte | 0b11000000; // |1|1|e|f|g|h|A|B|
                        fwrite(&highByte, 1, 1, fwptr);
                        fwrite(&lowByte, 1, 1, fwptr);
                                                          // |1|1|e|f|g|h|A|B| |1|0|C|D|E|F|G|H|
                        #ifdef debug
                            bitset8 = highByte;
                            cout << "OUT : " << bitset8 << " ";
                            bitset8 = lowByte;
                            cout << bitset8 << endl;
                        #endif
                    } 
                }
            }
            fclose(fwptr); //fayl@ resurs e ete bacel enq uremn bdi bari exninq pakenq
        }
    }
    

    

    return 0;
}

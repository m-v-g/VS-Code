#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bitset>
#include <fstream> //poderjka failogogo vvoda vivoda

using namespace std;

void reed();
void print();
void printFile();
void utf16be();
void utf16le();

size_t chap;
int o = 0; //demi 0ner@ pahelu hamar

//uint8_t* array1 = new uint8_t[chap];
unsigned char* array1 = new unsigned char[chap];
unsigned short bigEndian = 0xfffe; //0xFEFF (big-endian) kam 0xFFFE (little-endian)
unsigned short littleEndian = 0xfeff; //0xFEFF (big-endian) kam 0xFFFE (little-endian)

int main()
{
    reed();
    //print();
    //printFile();
    utf16be();
    utf16le();


    delete[] array1;
    return 0;
}

void reed()
{
    FILE* frptr = fopen("source.txt", "r"); //kardalu permition

    fseek(frptr, 0L, SEEK_END); //fayli mej kursori texn e poumolchaniyu inq cuyc kuda fayli skizb@
                                //menq ktexapoxenq fayli verj u krnanq nayev smeshenni tanq 
    chap = ftell(frptr); //het kveradardzne fayli bayteri chap@ 
    fseek(frptr, 0L, SEEK_SET); //berecinq kursor@ fayli skizb

    fread(array1, 1, chap, frptr); //k@ndune 4 argument obekti hascen te inc bdi karda, amen praxodi chap@ u te qani angam e kardalu u fayli pointer@
    fclose(frptr); //fayl@ resurs e ete bacel enq uremn bdi bari exninq pakenq
}

void print()
{
    
    for(int i = 0; i < chap; ++i)
    {
        bitset<8> bitset8;
        bitset8 = array1[i];
        cout << (char)array1[i] << "\t" << (int)array1[i] << "\t" << bitset8 << endl;
    }
    
}

void printFile()
{
    bitset<8> bitset8;
    ofstream fout;            //sozdanie obekta dlya vivoda
    fout.open("ip_parsed.txt", ios::app); //asocaciya ego s faylom (append enenq)
    for(int i = 0; i <= chap; ++i)
    {
        bitset8 = array1[i];
        if(array1[i] >= 0 && array1[i] <= 127)
        {
            cout << bitset8 << endl;
            fout << bitset8 << endl;
        }
        else
        {
            cout << bitset8 << " ";
            fout << bitset8 << " ";
            ++i;
            bitset8 = array1[i];
            cout << bitset8 << endl;
            fout << bitset8 << endl;
        }
        
    }
        cout << bitset8 << " ";
        //bitset8 = array1[i];
    fout.close();
}

void utf16be()
{
    FILE* fwptr = fopen("destUTF16BE.txt", "w"); //grelu permition
    //FILE - @ cuyc kuda fayleri katalogi mej fayli tex@ fopen-ov kbacenq fayl@ k@ndune 2 argument
    //1-fayli anun@ 2-te inc pemitionov kbacenq ed fayl@
    fwrite(&bigEndian, 2, 1, fwptr); //k@ndune 4 argument obekti hascen te inc bdi gre, amen praxodi chap@ u te qani angam e lcnelu u fayli pointer@
    bitset<8> bitset8;
    bitset<16> bitset16;
    uint8_t highByte = 0;
    uint8_t lowByte = 0;
    uint16_t outByte = 0;
    for(int i = 0; i <= chap; ++i)
    {
        if(array1[i] > 0 && array1[i] <= 127) //ASCII 1 byte
        {
            fwrite(&o, 1, 1, fwptr);         //gremq 0 ner
            fwrite(&array1[i], 1, 1, fwptr); //grenq 2-rd byt@
        }
        else if (array1[i] >= 192 && array1[i] <= 223) //2 byte
        {
            highByte = array1[i]; //kardacinq
            ++i; //ancanq myus bitin
            lowByte = array1[i]; //kardacinq
 
            highByte = highByte & 0b00011111;
            bitset8 = highByte;
            cout << "bh& : " << bitset8 << endl;
            lowByte = lowByte & 0b00111111;
            bitset8 = lowByte;
            cout << "bl& : " << bitset8 << endl;
            
            outByte = highByte << 6;
            outByte = outByte | lowByte;
            bitset16 = outByte;
            cout << "out : " << bitset16 << endl;
            fwrite(&outByte, 2, 1, fwptr);
            cout << endl;
        }
        else if (array1[i] >= 224 && array1[i] <= 239) //3 byte
        {
            /* code */
        }
        else if (array1[i] >= 240 && array1[i] <= 247) //4 byte
        {
            /* code */
        }
        else
        {
            /* code */
        }
    }
    fclose(fwptr); //fayl@ resurs e ete bacel enq uremn bdi bari exninq pakenq
}

void utf16le()
{
    FILE* fwptr = fopen("destUTF16LE.txt", "w"); //grelu permition
    //FILE - @ cuyc kuda fayleri katalogi mej fayli tex@ fopen-ov kbacenq fayl@ k@ndune 2 argument
    //1-fayli anun@ 2-te inc pemitionov kbacenq ed fayl@
    fwrite(&littleEndian, 2, 1, fwptr); //k@ndune 4 argument obekti hascen te inc bdi gre, amen praxodi chap@ u te qani angam e lcnelu u fayli pointer@
    bitset<8> bitset8;
    bitset<16> bitset16;
    uint8_t highByte = 0;
    uint8_t lowByte = 0;
    uint16_t outByte = 0;
    for(int i = 0; i <= chap; ++i)
    {
        if(array1[i] > 0 && array1[i] <= 127) //ASCII 1 byte
        {
            fwrite(&array1[i], 1, 1, fwptr); //grenq 2-rd byt@
            fwrite(&o, 1, 1, fwptr);         //gremq 0 ner
        }
        else if (array1[i] >= 192 && array1[i] <= 223) //2 byte
        {
            highByte = array1[i]; //kardacinq
            ++i; //ancanq myus bitin
            lowByte = array1[i]; //kardacinq
 
            highByte = highByte & 0b00011111;
            bitset8 = highByte;
            cout << "bh& : " << bitset8 << endl;
            lowByte = lowByte & 0b00111111;
            bitset8 = lowByte;
            cout << "bl& : " << bitset8 << endl;
            
            outByte = highByte << 14;
            outByte = outByte | lowByte << 8;
            outByte = outByte | highByte >> 2;
            //outByte = outByte | highByte;
            bitset16 = outByte;
            cout << "out : " << bitset16 << endl;
            fwrite(&outByte, 2, 1, fwptr);
            cout << endl;
        }
        else if (array1[i] >= 224 && array1[i] <= 239) //3 byte
        {
            /* code */
        }
        else if (array1[i] >= 240 && array1[i] <= 247) //4 byte
        {
            /* code */
        }
        else
        {
            /* code */
        }
    }
    fclose(fwptr); //fayl@ resurs e ete bacel enq uremn bdi bari exninq pakenq
}
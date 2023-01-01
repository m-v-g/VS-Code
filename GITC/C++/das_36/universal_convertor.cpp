#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bitset>
#include <fstream> //poderjka failogogo vvoda vivoda
#include <regex>
#include <vector>

#define debug

using namespace std;

#ifdef debug
    bitset<8> bitset8;
    bitset<16> bitset16;
#endif

vector<uint8_t> myVector;
uint8_t pars = 0;
// |a|b|c|d|e|f|g|h|
//  | | | | | | | |
//  | | | | | | | |_ 4 rd argumenti verjum .txt nshac e te che
//  | | | | | | |_ 3 rd argumenti verjum .txt nshac e te che
//  | | | | | |_ 2 rd argumentov nshvac eutf8 te che
//  | | | | |_ 1 rd argumentov nshvac eutf8 te che
//  | | | |_ 2 rd argumentov nshvac big endian te che
//  | | |_ 2 rd argumentov nshvac little endian te che
//  | |_ 1 rd argumentov nshvac big endian te che
//  |_ 1 rd argumentov nshvac little endian te che
//ete isxodny fayli kodirovken nsvac e prost@ utf16 uremn |a|b| = |1|1|
//ete konechny fayli kodirovken nsvac e prost@ utf16 uremn |c|d| = |1|1|
char* argv1;
char* argv2;
char* argv3;
char* argv4;

void read();
void logic();
void parsing();
void swop();
void utf16be_utf8();
void utf16le_utf8();
void utf8_utf16be();
void utf8_utf16le();

int main(int argc, char** argv)
{
    if(argc != 5)
    {
        cout << "Неправильное количество аргументов !!!" << endl;
        cout << "В качестве первого аргумента введите тип кодировки исходного файла" << endl;
        cout << "А в качестве второго аргумента введите тип кодировки конечного файла" << endl;
        cout << "В качестве третьего аргумента введите название исходного файла" << endl;
        cout << "В качестве четвертого аргумента введите название конечного файла" << endl;
        cout << "Например \" ./a.out utf8 utf16 source.txt destination.txt \"" << endl;
    }
    else
    {
        try
        {
            argv1 = argv[1];
            argv2 = argv[2];
            argv3 = argv[3];
            argv4 = argv[4];
            parsing();
            //read();
            logic();
        }
        catch(const out_of_range& ex)
        {
            cout << ex.what() << endl << endl;
        }

    }
    
    
    return 0;
    
}

void parsing()
{
    string temp;
    smatch matches; //klas vor@ kpahi sparich informacia
    regex txt("(\\.txt)$", regex_constants::icase); //anuni verjum .txt aranc registr@ hasvi arnelu
    regex utf8("^(utf[\\-\\_]?8)$", regex_constants::icase); //kodirovken nsvac konkret utf8 1 angam aranc registr@ hasvi arnelu
    regex utf16be("^(utf[\\-\\_]?16be)$", regex_constants::icase); //kodirovken nsvac konkret utf16be 1 angam aranc registr@ hasvi arnelu
    regex utf16le("^(utf[\\-\\_]?16le)$", regex_constants::icase); //kodirovken nsvac konkret utf16le 1 angam aranc registr@ hasvi arnelu
    regex utf16("^(utf[\\-\\_]?16)$", regex_constants::icase); //kodirovken nsvac konkret utf16 1 angam aranc registr@ hasvi arnelu

    temp = argv3;
    regex_search(temp, matches, txt);
    if (!matches.empty())
    {
        pars = pars | 0b00000010;
    }

    temp = argv4;
    regex_search(temp, matches, txt);
    if (!matches.empty())
    {
        pars = pars | 0b00000001;
    }

    temp = argv1;
    regex_search(temp, matches, utf8);
    if (!matches.empty())
    {
        pars = pars | 0b00001000;
    }
    regex_search(temp, matches, utf16be);
    if (!matches.empty())
    {
        pars = pars | 0b01000000;
    }
    regex_search(temp, matches, utf16le);
    if (!matches.empty())
    {
        pars = pars | 0b10000000;
    }
    regex_search(temp, matches, utf16);
    if (!matches.empty())
    {
        pars = pars | 0b11000000;
    }

    temp = argv2;
    regex_search(temp, matches, utf8);
    if (!matches.empty())
    {
        pars = pars | 0b00000100;
    }
    regex_search(temp, matches, utf16be);
    if (!matches.empty())
    {
        pars = pars | 0b00010000;
    }
    regex_search(temp, matches, utf16le);
    if (!matches.empty())
    {
        pars = pars | 0b00100000;
    }
    regex_search(temp, matches, utf16);
    if (!matches.empty())
    {
        pars = pars | 0b00110000;
    }
    #ifdef debug
        bitset8 = pars;
        cout << "Pars: " << bitset8 << endl;
    #endif
}

void read()
{    
    FILE* frptr = fopen(argv3, "r"); //kardalu permition

    fseek(frptr, 0L, SEEK_END); //fayli mej kursori texn e poumolchaniyu inq cuyc kuda fayli skizb@
                                //menq ktexapoxenq fayli verj u krnanq nayev smeshenni tanq 
    size_t chap = 0;
    chap = ftell(frptr); //het kveradardzne fayli bayteri qanak@
    
    myVector.resize(chap); 
    uint8_t array[chap];
    
    fseek(frptr, 0L, SEEK_SET); //berecinq kursor@ fayli skizb

    fread(&myVector[0], 1, chap, frptr); //k@ndune 4 argument obekti hascen te ur bdi karda, amen praxodi chap@ u te qani angam e kardalu u fayli pointer@
    fclose(frptr); //fayl@ resurs e ete bacel enq uremn bdi bari exninq pakenq

    #ifdef debug
        for(int i = 0; i < myVector.size(); ++i)
            {
                bitset8 = myVector.at(i); //.at(i) metod@ dandax e bayc anvtang chi tuylta durs gal masivi granicneric
                //bitset8 = array[i];
                cout << bitset8 << endl;
            }
    #endif
}

void logic()
{
    switch (pars)
    {
    case 0:
        #ifdef debug
            cout << "case 0" << endl;
        #endif
        cout << "Ни один аргумент не указан правильно" << endl;
        break;
    case 1://stugenq rasshireniner@ chist grats en te che
        #ifdef debug
            cout << "case 1" << endl;
        #endif
        cout << "Вы указали неверное расширение для целевого и/или конечного файла" << endl;
        cout << "Укажите пожалуйста файлы с расширением .txt " << endl;
        break;
    case 2://stugenq rasshireniner@ chist grats en te che
        #ifdef debug
            cout << "case 2" << endl;
        #endif
        cout << "Вы указали неверное расширение для целевого и/или конечного файла" << endl;
        cout << "Укажите пожалуйста файлы с расширением .txt " << endl;
        break;
    case 3://stugenq te kodirovkeq@ chisht en grac te che
        #ifdef debug
            cout << "case 3" << endl;
        #endif
        cout << "Вы указали неверное тип кодировки для целевого и/или конечного файла" << endl;
        cout << "Укажите пожалуйста типи кодировки  utf8 и/или utf16 и/или utf16be и/или utf16be" << endl;
        break;
    case 15://ete grace utf8-ic utf8 
        #ifdef debug
            cout << "case 15" << endl;
        #endif
        cout << "Бессмысленно конвертировать с utf8 на utf8 можно попросту переименовать файл" << endl;
        break;
    case 27://ete nshvac e utf8 -ic utf16be
        #ifdef debug
            cout << "case 27" << endl;
        #endif
        read();
        if (!((myVector.at(0) == 0xfe) || (myVector.at(0) == 0xff)))
        {   //stugenq te ed fayl@ karox e arden utf16 e
            utf8_utf16be();
        }
        break;
    case 43: //ete nshvac e utf8 -ic utf16le
        #ifdef debug
            cout << "case 43" << endl;
        #endif
        read();
        if (!((myVector.at(0) == 0xfe) || (myVector.at(0) == 0xff)))
        {   //stugenq te ed fayl@ karox e arden utf16 e
            utf8_utf16le();
        }
        break;
    case 59://ete nshvac e utf8 -ic utf16
        #ifdef debug
            cout << "case 59" << endl;
        #endif
        read();
        if (!((myVector.at(0) == 0xfe) || (myVector.at(0) == 0xff)))
        {   //stugenq te ed fayl@ karox e arden utf16 e
            utf8_utf16be();
        }
        break;
    case 71://ete nshvac e utf16be -ic utf8
        #ifdef debug
            cout << "case 71" << endl;
        #endif
        read();
        if ((myVector.at(0) == 0xfe) && (myVector.at(1) == 0xff))
        {   //stugenq te ed fayl@ utf16be e
            utf16be_utf8();
        }
        else
        {
            cout << "Кодировка файла не соответствует utf16be" << endl;
        }
        break;
    case 83://ete grace utf16be-ic utf16be
        #ifdef debug
            cout << "case 83" << endl;
        #endif
        cout << "Бессмысленно конвертировать с utf16be на utf16be можно попросту переименовать файл" << endl;
        break;
    case 99://ete nshvac e utf16be -ic utf16le
        #ifdef debug
            cout << "case 99" << endl;
        #endif
        read();
        if ((myVector.at(0) == 0xfe) && (myVector.at(1) == 0xff))
        {   //bayc skzbic stugenq te ed fayl@ vabshe utf16be e gone
            swop();
        }
        else
        {
            cout << "Кодировка файла не соответствует utf16be" << endl;
        }
        break;
    case 115://ete nshvac e utf16be -ic utf16
        #ifdef debug
            cout << "case 115" << endl;
        #endif
        read();
        if ((myVector.at(0) == 0xfe) && (myVector.at(1) == 0xff))
        {   //bayc skzbic stugenq te ed fayl@ vabshe utf16be e gone
            swop();
        }
        else
        {
            cout << "Кодировка файла не соответствует utf16be" << endl;
        }
        break;
    case 135://ete nshvac e utf16le -ic utf8
        #ifdef debug
            cout << "case 135" << endl;
        #endif
        read();
        if ((myVector.at(0) == 0xff) && (myVector.at(1) == 0xfe))
        {   //stugenq te ed fayl@ utf16le e
            utf16le_utf8();
        }
        else
        {
            cout << "Кодировка файла не соответствует utf16le" << endl;
        }
        break;
    case 147://ete nshvac e utf16le -ic utf16be
        #ifdef debug
            cout << "case 147" << endl;
        #endif
        read();
        if ((myVector.at(0) == 0xff) && (myVector.at(1) == 0xfe))
        {   //bayc skzbic stugenq te ed fayl@ vabshe utf16le e gone
            swop();
        }
        else
        {
            cout << "Кодировка файла не соответствует utf16le" << endl;
        }
        break;
    case 163://ete grace utf16le-ic utf16le
        #ifdef debug
            cout << "case 163" << endl;
        #endif
        cout << "Бессмысленно конвертировать с utf16le на utf16le можно попросту переименовать файл" << endl;
        break;
    case 179://ete nshvac e utf16le -ic utf16
        #ifdef debug
            cout << "case 179" << endl;
        #endif
        read();
        if ((myVector.at(0) == 0xff) && (myVector.at(1) == 0xfe))
        {   //bayc skzbic stugenq te ed fayl@ vabshe utf16be e gone
            swop();
        }
        else
        {
            cout << "Кодировка файла не соответствует utf16le" << endl;
        }
        break;
    case 199://ete nshvac e utf16 -ic utf8
        #ifdef debug
            cout << "case 199" << endl;
        #endif
        read();
        if ((myVector.at(0) == 0xff) && (myVector.at(1) == 0xfe))
        {   //stugenq te ed fayl@ utf16le e
            #ifdef debug
                cout << "utf16le_utf8()" << endl;
            #endif
            utf16le_utf8();
        }
        else if ((myVector.at(0) == 0xfe) && (myVector.at(1) == 0xff))
        {   //stugenq te ed fayl@ utf16be e
            #ifdef debug
                cout << "utf16be_utf8()" << endl;
            #endif
            utf16be_utf8();
        }
        else
        {
            cout << "Кодировка файла не соответствует utf16" << endl;
        }
        break;
    case 243://ete grace utf16-ic utf16 uremn swop enenq karevor ch fayl@ be te le
        #ifdef debug
            cout << "case 243" << endl;
        #endif
        read();
        if (((myVector.at(0) == 0xff) && (myVector.at(1) == 0xfe)) || ((myVector.at(0) == 0xfe) && (myVector.at(1) == 0xff)))
        {   //bayc skzbic stugenq te ed fayl@ vabshe utf16 e gone
            swop();
        }
        else
        {
            cout << "Кодировка файла не соответствует utf16" << endl;
        }
        break;

    default:
        #ifdef debug
            cout << "case defult" << endl;
        #endif
        //cout << "Что то пошло не так !!!!!!!!!!!!!!!!" << endl;
        cout << "Один или несколько аргументов указаны неправильно" << endl;
        break;
    }
    
}

void swop() //utf16be -ic utf16le kam hakarak@
{
    #ifdef debug
        cout << "Function swop()" << endl;
    #endif
    FILE* fwptr = fopen(argv4, "w"); //grelu permition
    //FILE - @ cuyc kuda fayleri katalogi mej fayli tex@ fopen-ov kbacenq fayl@ k@ndune 2 argument
    //1-fayli anun@ 2-te inc pemitionov kbacenq ed fayl@
    for(int i = 0; i < myVector.size(); i+=2)
    {                          // |A|B|C|D|E|F|G|H| |a|b|c|d|e|f|g|h|
        fwrite(&myVector[i + 1], 1, 1, fwptr); // |a|b|c|d|e|f|g|h|
        fwrite(&myVector[i], 1, 1, fwptr);     // |A|B|C|D|E|F|G|H|
    }
    fclose(fwptr); //fayl@ resurs e ete bacel enq uremn bdi bari exninq pakenq
}

void utf16be_utf8()
{
    #ifdef debug
        cout << "Function utf16be_utf8()" << endl;
    #endif
    FILE* fwptr = fopen(argv4, "w"); //grelu permition
    //FILE - @ cuyc kuda fayleri katalogi mej fayli tex@ fopen-ov kbacenq fayl@ k@ndune 2 argument
    //1-fayli anun@ 2-te inc pemitionov kbacenq ed fayl@
    for (int i = 2; i < myVector.size(); ++i)
    {
        if (myVector[i] == 0) //ete ASCII simvol e
        {   // |0|a|b|c|d|e|f|g| |0|0|0|0|0|0|0|0|
            ++i;
            fwrite(&myVector[i], 1, 1, fwptr);  
        }
        else// |A|B|C|D|E|F|G|H| |a|b|c|d|e|f|g|h|
        {
            uint8_t highByte = myVector[i];      // |A|B|C|D|E|F|G|H|
            ++i;
            uint8_t lowByte = myVector[i]; // |a|b|c|d|e|f|g|h|
            lowByte = lowByte & 0b00111111;     // |0|0|C|D|E|F|G|H|
            lowByte = lowByte | 0b10000000;     // |1|0|C|D|E|F|G|H|
            highByte = highByte << 2;           // |c|d|e|f|g|h|0|0|
            uint8_t temp = myVector[i] >> 6;    // |0|0|0|0|0|0|A|B|
            highByte = highByte | temp;         // |c|d|e|f|g|h|A|B|
            highByte = highByte | 0b11000000;   // |1|1|e|f|g|h|A|B|
            fwrite(&highByte, 1, 1, fwptr);
            fwrite(&lowByte, 1, 1, fwptr);
        }
    }
    fclose(fwptr); //fayl@ resurs e ete bacel enq uremn bdi bari exninq pakenq
}

void utf16le_utf8()
{
    #ifdef debug
        cout << "Function utf16le_utf8()" << endl;
    #endif
    FILE* fwptr = fopen(argv4, "w"); //grelu permition
    //FILE - @ cuyc kuda fayleri katalogi mej fayli tex@ fopen-ov kbacenq fayl@ k@ndune 2 argument
    //1-fayli anun@ 2-te inc pemitionov kbacenq ed fayl@
    for (int i = 2; i < myVector.size(); ++i)
    {
        if (myVector[i + 1] == 0) //ete ASCII simvol e
        {   // |0|a|b|c|d|e|f|g| |0|0|0|0|0|0|0|0|
            fwrite(&myVector[i], 1, 1, fwptr);
            ++i;
        }
        else// |A|B|C|D|E|F|G|H| |a|b|c|d|e|f|g|h|
        {
            uint8_t lowByte = myVector[i];      // |A|B|C|D|E|F|G|H|
            uint8_t temp = myVector[i];         // |A|B|C|D|E|F|G|H|
            temp = temp >> 6;                   // |0|0|0|0|0|0|A|B|
            ++i;
            uint8_t highByte = myVector[i];     // |a|b|c|d|e|f|g|h|
            #ifdef debug
                bitset8 = highByte;
                cout << bitset8 << " ";
                bitset8 = lowByte;
                cout << bitset8 << endl;
            #endif
            highByte = highByte << 2;            // |c|d|e|f|g|h|0|0|
            highByte = highByte | temp;          // |c|d|e|f|g|g|A|B|
            highByte = highByte | 0b11000000;    // |1|1|e|f|g|h|A|B|
            lowByte = lowByte & 0b00111111;      // |0|0|C|D|E|F|G|H|
            lowByte = lowByte | 0b10000000;      // |1|0|C|D|E|F|G|H|
            fwrite(&highByte, 1, 1, fwptr);
            fwrite(&lowByte, 1, 1, fwptr);
        }
    }
    fclose(fwptr); //fayl@ resurs e ete bacel enq uremn bdi bari exninq pakenq
}

void utf8_utf16le()
{
    #ifdef debug
        cout << "Function utf8_utf16le()" << endl;
    #endif
    uint8_t bom1 = 0xff;
    uint8_t bom2 = 0xfe;
    uint8_t zero = 0;
    uint8_t highByte;
    uint8_t lowByte;
    uint8_t temp;
    FILE* fwptr = fopen(argv4, "w"); //grelu permition
    //FILE - @ cuyc kuda fayleri katalogi mej fayli tex@ fopen-ov kbacenq fayl@ k@ndune 2 argument
    //1-fayli anun@ 2-te inc pemitionov kbacenq ed fayl@
    fwrite(&bom1, 1, 1, fwptr);
    fwrite(&bom2, 1, 1, fwptr);
    for (int i = 0; i < myVector.size(); ++i)
    {
        if (myVector[i] > 0 && myVector[i] < 127)
        {
            fwrite(&myVector[i], 1, 1, fwptr);
            fwrite(&zero, 1, 1, fwptr);
        }
        else if (myVector[i] >= 192 && myVector[i] <= 223) //2 byte
        {
            highByte = myVector[i] & 0b00011111; //kardacinq
            temp = myVector[i] << 6;
            highByte = highByte >> 2;
            ++i; //ancanq myus bitin
            lowByte = myVector[i] & 0b00111111; //kardacinq
            lowByte = lowByte | temp;
            fwrite(&lowByte, 1, 1, fwptr);
            fwrite(&highByte, 1, 1, fwptr);
            #ifdef debug
                bitset8 = highByte;
                cout << bitset8 << " ";
                bitset8 = lowByte;
                cout << bitset8 << endl;
            #endif

        }
        
    }
    fclose(fwptr); //fayl@ resurs e ete bacel enq uremn bdi bari exninq pakenq
}
void utf8_utf16be()
{
    #ifdef debug
        cout << "Function utf8_utf16be()" << endl;
    #endif
    uint8_t bom1 = 0xfe;
    uint8_t bom2 = 0xff;
    uint8_t zero = 0;
    uint8_t highByte;
    uint8_t lowByte;
    uint8_t temp;
    FILE* fwptr = fopen(argv4, "w"); //grelu permition
    //FILE - @ cuyc kuda fayleri katalogi mej fayli tex@ fopen-ov kbacenq fayl@ k@ndune 2 argument
    //1-fayli anun@ 2-te inc pemitionov kbacenq ed fayl@
    fwrite(&bom1, 1, 1, fwptr);
    fwrite(&bom2, 1, 1, fwptr);
    for (int i = 0; i < myVector.size(); ++i)
    {
        if (myVector[i] > 0 && myVector[i] < 127)
        {
            fwrite(&zero, 1, 1, fwptr);
            fwrite(&myVector[i], 1, 1, fwptr);
        }
        else if (myVector[i] >= 192 && myVector[i] <= 223) //2 byte
        {
            highByte = myVector[i] & 0b00011111; //kardacinq
            temp = myVector[i] << 6;
            highByte = highByte >> 2;
            ++i; //ancanq myus bitin
            lowByte = myVector[i] & 0b00111111; //kardacinq
            lowByte = lowByte | temp;
            fwrite(&highByte, 1, 1, fwptr);
            fwrite(&lowByte, 1, 1, fwptr);
            #ifdef debug
                bitset8 = highByte;
                cout << bitset8 << " ";
                bitset8 = lowByte;
                cout << bitset8 << endl;
            #endif
        }
    }
    fclose(fwptr); //fayl@ resurs e ete bacel enq uremn bdi bari exninq pakenq
}
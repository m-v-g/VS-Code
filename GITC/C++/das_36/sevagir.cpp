#include <iostream>
#include <regex>
#include <bitset>

using namespace std;
/*
int main(int argc, char** argv)
{
    string argv1 = argv[1];
    string argv2 = argv[2];
    string argv3 = argv[3];
    string argv4 = argv[4];
*/
int main()
{
    string argv1 = "utf8";
    string argv2 = "utf16be";
    string argv3 = "source";
    string argv4 = "destination";

    uint8_t pars = 0;
    bitset<8> bitset8;

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

    string temp;
    smatch matches; //klas vor@ kpahi sparich informacia
    regex txt("(\\.txt)$", regex_constants::icase); //anuni verjum .txt aranc registr@ hasvi arnelu
    regex utf8("^(utf8)$", regex_constants::icase); //kodirovken nsvac konkret utf8 1 angam aranc registr@ hasvi arnelu
    regex utf16be("utf16be", regex_constants::icase); //kodirovken nsvac konkret utf16be 1 angam aranc registr@ hasvi arnelu
    regex utf16le("utf16le", regex_constants::icase); //kodirovken nsvac konkret utf16le 1 angam aranc registr@ hasvi arnelu
    regex utf16("^(utf16)$", regex_constants::icase); //kodirovken nsvac konkret utf16 1 angam aranc registr@ hasvi arnelu

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
    
   
    
    
    /*
    cout << boolalpha;
    while(regex_search(argv3, matches, txt))
    {
        cout << "Est sovpadeniya " << matches.ready() << endl;
        cout << "Net sovpadeniy " << matches.empty() << endl;
        cout << "Kolichestvo sovpadeniy " << matches.size() << endl;
        cout << matches.str(1) << endl;

        //cout << vxojdenie[0] << endl;
        
        
        argv3 = matches.suffix().str();
    }
    */
   bitset8 = pars;
   cout << bitset8 << endl;
    return 0;
}
#include <iostream>
#include <regex>
#include <fstream> //poderjka failogogo vvoda vivoda
#include <cstdlib> //poderjka exit()
const int SIZE = 60;

using namespace std;

int main()
{
    char filename[SIZE];
    ifstream fin; //obekt dlya obrabotki fayla
    cout << "Enter name of parsing file name: "; //zapros imeni fayla dannix
    cin.getline(filename, SIZE);
    fin.open(filename); //asocaciya obekta s faylom
    if(!fin.is_open())  //esli ne udalos otkrit fayl
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating." << endl;
        exit(EXIT_FAILURE);
    }
    ofstream fout;            //sozdanie obekta dlya vivoda
    fout.open("ip_parsed.txt", ios::app); //asocaciya ego s faylom (append enenq)
    
    regex ipv4 ("\\b(([0-9]|([1-9][0-9])|((1[0-9]{2})|(2[0-4][0-9])|(25[0-5])))\\.){3}"
                "([0-9]|([1-9][0-9])|((1[0-9]{2})|(2[0-4][0-9])|(25[0-5])))\\b");
    smatch vxojdenie;
    int count = 0;  //pahenq gtats ipneri qanak@
    string text; //fayli meji texti amen tox@ pahelu hamar

    while(fin.good()) //poka vvod uspeshen i ne dostignut EOF
    {
        getline(fin, text); //funkcia vor@ kkarda vxodnoy potokic stringi mej
        while(regex_search(text, vxojdenie, ipv4))
        {
            fout << vxojdenie[0] << endl; //grenq fayli mej
            text = vxojdenie.suffix().str();
            ++ count;
        }
    }
    if(fin.eof()) //dostignut konec fayla
    {
        cout << "End of file reached." << endl;
    }
    else if (fin.fail()) //vvod prekraschen iz-za nesootvetstviya tipov
    {
        cout << "Input terminated by data mismatch." << endl;
    }
    else //vvod prekraschen po neizvestnoy prichine
    {
        cout << "Input terminated for uncnow reason" << endl;
    }
    
    if(count == 0) //dannie dlya obrabotki otsutstvuyut
    {
        cout << "No data processed" << endl;
        fout << endl << "No data processed" << endl << endl;
    }
    else
    {
        cout << "Item reed: " << count << endl;
        fout << endl << "Item reed: " << count << endl << endl;
    }
    
    fin.close(); //es faylic prdzanq
    fout.close();   //zavershenie roboti s failom

    return 0;

}
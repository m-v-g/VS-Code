#include <iostream>
#include <time.h>        //clock() ogtagortselu hamar
#include <cstdlib>       //rand() ogtagortselu hamar
#include <set>           //set ogtagortselu hamar
#include <unordered_set> //unordered_set ogtagortselu hamar

#define SIZE 1000000     //simvolicheskaya konstanta
using namespace std;

int main()
{
    set<int> s;            //sarqenq set
    unordered_set<int> us; //sarqenq unordered_set
    int randomNumber;      //patahakan tiv@ hishelu hamar
    long seDuration = 0;   //seti emplace-i jamanak@ hishelu hamar
    long useDuration = 0;  //unordered_seti emplace-i jamanak@ hishelu hamar
    long sfDuration = 0;   //seti find-i jamanak@ hishelu hamar
    long usfDuration = 0;  //unordered_seti find-i jamanak@ hishelu hamar

    //set emplace
    long seStart = clock(); //seti emplasi jamanaki hashvarki skizb
    for (int i = 0; i < SIZE; ++i) //minchev mer nshac tiv@
    {
        randomNumber = 0 + rand() % 100; //0-100 patahakan tver
        s.emplace(randomNumber); //grenq seti mej
    }
    long seEnd = clock(); //seti emplasi jamanaki hashvarki verj

    //set find
    long sfStart = clock(); //seti findi jamanaki hashvarki skizb
    for (int i = 0; i < SIZE; ++i) //minchev mer nshac tiv@
    {
        randomNumber = 0 + rand() % 100; //0-100 patahakan tver
        s.find(randomNumber); //pntrenq seti mej
    }
    long sfEnd = clock();//seti findi jamanaki hashvarki verj

    seDuration = seEnd - seStart; //seti emplaci jamanaki ardyunq
    sfDuration = sfEnd - sfStart; //seti findi jamanaki ardyunq
    cout << "SET EMPLACE TIME: " << seDuration << " seconds" << endl;
    cout << "SET FIND TIME: " << sfDuration << endl;

    //unordered_set emplace
    long useStart = clock(); //unordered_seti emplasi jamanaki hashvarki skizb
    for (int i = 0; i < SIZE; ++i) //minchev mer nshac tiv@
    {
        randomNumber = 0 + rand() % 100; //0-100 patahakan tver
        us.emplace(randomNumber); //grenq unordered_seti mej
    }
    long useEnd = clock(); //unordered_seti emplasi jamanaki hashvarki verj

    //unordered_set find
    long usfStart = clock(); //unordered_seti findi jamanaki hashvarki skizb
    for (int i = 0; i < SIZE; ++i) //minchev mer nshac tiv@
    {
        randomNumber = 0 + rand() % 100; //0-100 patahakan tver
        us.find(randomNumber); //pntrenq unordered_seti mej
    }
    long usfEnd = clock(); //unordered_seti findi jamanaki hashvarki verj
    useDuration = useEnd - useStart; //seti emplaci jamanaki ardyunq
    usfDuration = usfEnd - usfStart; //seti findi jamanaki ardyunq
    cout << "UNORDERED_SET EMPLACE TIME: " << useDuration << endl;
    cout << "UNORDERED_SET FIND TIME: " << usfDuration << endl;

    //aragutyan tarberutyunner@
    double eDuration = (double)seDuration / useDuration; //aragutyan tarberutyunner@ hishelu popoxakan
    double fDuration = (double)sfDuration / usfDuration; //ete naxoroq tipi chenq bere amboxj tver kstacvin

    cout << "DIFERANCE_EMPLACE: " << eDuration << endl;
    cout << "DIFERANCE_FIND: " << fDuration << endl;

    return 0;
}
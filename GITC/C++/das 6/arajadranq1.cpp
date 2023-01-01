/******************************************************************************

arajadranq 6/1

ankyunagic / verev / nerqev

*******************************************************************************/
#include <iostream>
#include <random>
using namespace std;

int main()
{
    int avtg = 0; //ankyunagcic verevi tveri gumar@
    int avtq = 0; //ankyunagcic verevi tveri qanak@
    int antg = 0; //ankyunagcic nerqevi tveri gumar@
    int antq = 0; //ankyunagcic nerqevi tveri qanak@
    int avztg = 0; //ankyunagcic verevi zuyg tveri gumar@
    int avktg = 0; //ankyunagcic verevi kent tveri gumar@
    int anztg = 0; //ankyunagcic nerqevi zuyg tveri gumar@
    int anktg = 0; //ankyunagcic nerqevi kent tveri gumar@
    
    int array[4][4];
    int a = 0;
    for(int i = 0; i < 4; ++i)
    {
        cout << "---------------------------------" << endl;
        cout << "| ";
        for(int j = 0; j < 4; ++j)
        {
            //array[i][j] = 20 + rand()%80;
            array[i][j] = a;
            ++ a;
            cout << array[i][j] << "\t| ";
        }
        cout << endl;
    }
    cout << "---------------------------------" << endl;
    
    
    
    // ankyunagic
    
    cout << endl << "ankyunagic" << endl;
    
    for(int i = 0; i < 4; ++i)
    {
        cout << "---------------------------------" << endl;
        cout << array[i][i] << endl;
    }
    cout << "---------------------------------" << endl;
    
    
    
    
    //ankyunagcic verev
    cout << endl << "ankyunagcic verev" << endl;
    
    int k = 1;
    
    for(int i = 0; i < 3; ++i)
    {
        for(int j = k; j < 4; ++j)
        {
            cout << array[i][j] << "\t";
            avtg = avtg + array[i][j];
            ++ avtq;
            int z = array[i][j] % 2;
            if(z == 0)
            {
                avztg = avztg + array[i][j];
            }
            else
            {
                avktg = avktg + array[i][j];
            }
        }
        ++ k;
        cout << endl;
    }
    
    cout << endl << "tvabanakn mijin = " << avtg/avtq << endl;
    cout << endl << "zuyg tveri gumar@ = " << avztg << endl;
    cout << endl << "kent tveri gumar@ = " << avktg << endl;
    
    
    
    //ankyunagcic nerqev
    cout << endl << "ankyunagcic nerqev" << endl;
    
    k = 1;
    
    for(int i = 1; i < 4; ++i)
    {
        for(int j = 0; j < k; ++j)
        {
            cout << array[i][j] << "\t";
            antg = antg + array[i][j];
            ++ antq;
            int z = array[i][j] % 2;
            if(z == 0)
            {
                anztg = anztg + array[i][j];
            }
            else
            {
                anktg = anktg + array[i][j];
            }
        }
        ++ k;
        cout << endl;
    }
    
    cout << endl << "tvabanakn mijin = " << antg/antq << endl;
    cout << endl << "zuyg tveri gumar@ = " << anztg << endl;
    cout << endl << "kent tveri gumar@ = " << anktg << endl;

    return 0;
}



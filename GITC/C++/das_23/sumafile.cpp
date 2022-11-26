//chtenie iz fayla
#include <iostream>
#include <fstream> //poderjka failogogo vvoda vivoda
#include <cstdlib> //poderjka exit()
const int SIZE = 60;

using namespace std;

int main()
{
    char filename[SIZE];
    ifstream fin; //obekt dlya obrabotki fayla
    cout << "Enter name of data file: "; //zapros imeni fayla dannix
    cin.getline(filename, SIZE);
    fin.open(filename); //asocaciya obekta s faylom
    if(!fin.is_open())  //esli ne udalos otkrit fayl
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating." << endl;
        exit(EXIT_FAILURE);
    }
    double value;
    double sum = 0.0;
    int count = 0;
    fin >> value; //vvod pervogo znacheniya
    while(fin.good()) //poka vvod uspeshen i ne dostignut EOF
    {
        ++ count;
        sum += value;
        fin >> value;
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
    }
    else
    {
        cout << "Item reed: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;
    }
    fin.close();

    return 0;
}
    
    
    
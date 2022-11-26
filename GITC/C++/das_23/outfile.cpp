//zapis v fayl
#include <iostream>
#include <fstream> //poderjka failogogo vvoda vivoda

using namespace std;

int main()
{
    char automobile[50];
    int year;
    double a_price;
    double d_price;
    ofstream fout;            //sozdanie obekta dlya vivoda
    fout.open("carinfo.txt", ios::app); //asocaciya ego s faylom
    cout << "Enter the make and model of automobile: ";
    cin.getline(automobile, 50);
    cout << "Enter the model year: ";
    cin >> year;
    cout << "Enter the original asking price: ";
    cin >> a_price;
    d_price = 0.913 * a_price;

    //otobrajenie informacii na ekrane
    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout << "Make and model: " << automobile << endl;
    cout << "Year: " << year << endl;
    cout << "Was asking $" << a_price << endl;
    cout << "Now asking $" << d_price << endl;

    //vivod informacii v fail
    fout << fixed;
    fout.precision(2);
    fout.setf(ios_base::showpoint);
    fout << "Make and model: " << automobile << endl;
    fout << "Year: " << year << endl;
    fout << "Was asking $" << a_price << endl;
    fout << "Now asking $" << d_price << endl << endl;
    fout.close();   //zavershenie roboti s failom

    return 0;
}
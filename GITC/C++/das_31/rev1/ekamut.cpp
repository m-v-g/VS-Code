#include <iostream>
#include <ctime>
#include "bst.h"
//#include "node.h"
//#include "income.h"
//#include "other_class.h"

using namespace std;



int main()
{
    SortByTotal sbt;
    SortByName sbn;
    BST<Income> gyumri(&sbt);

    char arrayN[] = {'g', 'c', 'b', 'a', 'i', 'e', 'd', 'f', 'h', '!'};
    double arrayA[] = {70, 30, 20, 10, 90, 50, 40, 60, 80, 65};
    double arrayI[] = {-0.7, -0.3, -0.2, -0.1, -0.9, -0.5, -0.4, -0.6, -0.8, -0.65};

    for (int i = 0; i < sizeof(arrayA) / sizeof(arrayA[0]); ++i)
    {
        gyumri.add(Income(arrayN[i], arrayA[i], arrayA[i]/i, arrayI[i], arrayI[i]/i, arrayA[i]/arrayI[i]));
    }
    //gyumri.print();

    std::cout << "+++++++++++++++++++ TEST +++++++++++++++++++" << std::endl;
    bool yn;
    Income a;
    a.name = 'a';
    a.fromStore = 1;
    a.fromTender = 2;
    a.fromInstalation = 3;
    a.fromCashBack = 4;
    a.fromService = 5;

    Income b;
    b = a;
    b.name = 'b';
    b.print();
    Income c = a;
    c.name = 'c';
    c.print();
    yn = (a >= b);
    //std::cout.setf(std::ios_base::boolalpha);
    yn ? cout << "YES" : cout << "NO" ;

    return 0;
}
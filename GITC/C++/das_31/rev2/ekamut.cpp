#include <iostream>
#include <ctime>
#include "income.h"


//using namespace std;

int main()
{
    Income a;
    a.fromStore = 1;
    a.fromTender = 2;
    a.fromInstalation = 3;
    a.fromCashBack = 4;
    a.fromService = 5;
    std::cout << a;
    //operator<<(std::cout, a); //spes el krnanq enenq
    Income b;
    b = a;

    Income c = a;
    ++c;
    //--c;
    ++b;
    //b.print();
    //c.print();
    std::cout.setf(std::ios_base::boolalpha); //vivodit true ili false vmesto 1 i 0
    
    std::cout << "Comparison Result: ";
    (a == b) ? std::cout << "POSITIVE" << std::endl : std::cout << "NEGATIVE" << std::endl;
    try
    {
        std::cout << "a[1] = " << a[1] << std::endl;
    }
    catch(IndexOutOfBounds k)
    {
           k.display(); 
    }

    char i = a;
    std::cout << "i = " << i << std::endl; //! chexav


    std::cout << "str = " << a.toString() << std::endl; //! exav
    //std::cin >> a;
    return 0;
}
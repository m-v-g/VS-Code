#include <iostream>
#include <vector>
#include <math.h>
#include <functional>
#define SIZE 100
using namespace std;



bool isPrime(int num)
{
    cout << "vizvona obichnaya funkciya" << endl;
    if (num > 1)
    {
        int max = sqrt(num);
        for (size_t i = 2; i <= max; i++)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

int main()
{
    vector<int> ollNum;
    vector<int> natNum;

    bool(*pIsPrime)(int) = [](int num)->bool
    {
        cout << "vizvona anonimnaya funkciya cherez ukozatel" << endl;
        if (num > 1)
        {
            int max = sqrt(num);
            for (size_t i = 2; i <= max; i++)
            {
                if (num % i == 0)
                {
                    return false;
                }
            }
            return true;
    }
    return false;
    }; //ukozatel na funkciyu
    function<bool(int)> fIsPrime = [](int num)->bool
    {
        cout << "vizvona anonimnaya funkciya cherez posrednika" << endl;
        if (num > 1)
        {
            int max = sqrt(num);
            for (size_t i = 2; i <= max; i++)
            {
                if (num % i == 0)
                {
                    return false;
                }
            }
            return true;
    }
    return false;
    }; //polimorfnaya obertka obekta function
    //inicalizaciya vsex chisel
    for (size_t i = 0; i < SIZE; i++)
    {
        ollNum.emplace_back(i);
    }
    //prostoy metod

    for(auto iterator : ollNum)
    {
        if(pIsPrime(iterator))
        {
            natNum.emplace_back(iterator);
        }
    }

    cout << "NATURAL[] = { ";
    for(auto iterator : natNum)
    {
        cout << iterator << ", ";
    }
    cout << "\b\b }" << endl;

    return 0;
}
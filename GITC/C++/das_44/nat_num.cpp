#include <iostream>
#include <vector>
#include <math.h>
#include <thread>
#include <functional>
//#include <chrono>
#define SIZE 100
using namespace std;

bool isPrime1(int num)
{
    cout << "ID potoka: " << this_thread::get_id() << "\tisPrime1\t" << endl;
    if (num > 1)
    {
        for (size_t i = 2; i <= num; i++)
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

bool isPrime2(int num)
{
    cout << "ID potoka: " << this_thread::get_id() << "\tisPrime2\t" << endl;
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
    function<void(int)> f;
    f = isPrime1;
    bool(*pIsPrime1)(int) = isPrime1;
    //thread th1(f);
    bool(*pIsPrime2)(int) = isPrime2;
    //thread th2(pIsPrime2);
    //inicalizaciya vsex chisel
    for (size_t i = 0; i < SIZE; i++)
    {
        ollNum.emplace_back(i);
    }
    //prostoy metod
    auto st1 = chrono::high_resolution_clock::now();
    for(auto iterator : ollNum)
    {
        if(pIsPrime1(iterator))
        {
            natNum.emplace_back(iterator);
        }
    }
    auto end1 = chrono::high_resolution_clock::now();

    natNum.clear(); //ochistka vektora
    //prostoy s prirostom
    auto st2 = chrono::high_resolution_clock::now();
    for(auto iterator : ollNum)
    {
        if(pIsPrime1(iterator))
        {
            natNum.emplace_back(iterator);
        }
    }
    auto end2 = chrono::high_resolution_clock::now();
    //th1.join();
    //th2.join();
/*
    cout << "NATURAL[] = { ";
    for(auto iterator : natNum)
    {
        cout << iterator << ", ";
    }
    cout << "\b\b }" << endl;
*/
    
    chrono::duration<float> time1 = end1 - st1;
    cout << "\tTIME 1: " << time1.count() << " sec" << endl;

    chrono::duration<float> time2 = end2 - st2;
    cout << "\tTIME 2: " << time2.count() << " sec" << endl;

    chrono::duration<float> total = end2 - st1;
    cout << "\tTOTAL : " << total.count() << " sec" << endl;
    return 0;
}
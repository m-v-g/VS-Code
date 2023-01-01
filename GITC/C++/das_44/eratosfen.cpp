#include <iostream>
#include <vector>
#include <math.h>
#include <array>
#include <chrono>
#define SIZE 100
using namespace std;

void isPrime(int num, array<bool, SIZE>& sivNum, vector<int>& natNum)
{
    if (num > 1)
    {
        for (size_t i = 2; i <= num; i++)
        {
            if(!sivNum[i])
            {
                natNum.emplace_back(i);
                for (size_t j = i * 2; j <= num; j += i)
                {
                    sivNum[j] = true;
                }
            }
        }
    }
}

int main()
{
    vector<int> ollNum;
    vector<int> natNum;
    array<bool, SIZE> sivNum;
    sivNum.fill(false);

    auto st3 = chrono::high_resolution_clock::now();
    for(auto iterator : ollNum)
    {
        isPrime(iterator, sivNum, natNum);
    }
    auto end3 = chrono::high_resolution_clock::now();

    cout << "NATURAL[] = { ";
    for(auto iterator : natNum)
    {
        cout << iterator << ", ";
    }
    cout << "\b\b }";


    return 0;
}
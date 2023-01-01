#include <iostream>
#include <functional>
#include <vector>
using namespace std;
void foo1(int a)
{
    if (a % 2 == 0)
    {
        cout << "foo1 a = " << a << endl;
    }
}

void foo2(int b)
{
    if (b % 2 != 0)
    {
        cout << "foo2 b = " << b << endl;
    }
}

void doWork(vector<int> &myVector, function<void(int)> func)
{
    for(auto element : myVector)
    {
        func(element);
    }
}

int main()
{
    vector<int> myVector = {3, 8, 6, 7, 9, 4, 2, 1, 5};
    function<void(int)> f;

    f = [](int a)
    {
        cout << "anonimnaya funkciya s parametrm a = " << a << endl;
    };

    doWork(myVector, f);
    cout << "--------------" << endl;
    doWork(myVector, [](int a)
    {
        cout << "anonimnaya funkciya s parametrm a = " << a << endl;
    });
    return 0;
}
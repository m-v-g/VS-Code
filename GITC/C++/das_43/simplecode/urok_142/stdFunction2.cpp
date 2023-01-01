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

void doWork(vector<int> &myVector, vector<function<void(int)> > f)
{
    for(auto element : myVector)
    {
        for(auto &funcEl : f)
        {
            funcEl(element);
        }
    }
}

int main()
{
    vector<int> myVector = {3, 8, 6, 7, 9, 4, 2, 1, 5};
    //doWork(myVector, foo2);
    vector<function<void(int)> > vecFoo; //masiv obektov function s signaturami void(int)
    vecFoo.emplace_back(foo1);
    vecFoo.emplace_back(foo2);
    doWork(myVector, vecFoo);

    return 0;
}
#include <iostream>
//#include <cmath>
#include <vector>
using namespace std;

int main()
{
    string str = "465456";
    vector<int> myVector;
    for(int i = str.size() - 1; i >= 0; --i)
    {
        myVector.emplace_back(str[i] - 48);
    }
    int sum = 0;
    for(int i = 0; i < myVector.size(); ++i)
    {
        //sum = sum + myVector.at(i) * pow(10, i);
        int pow = 1;
        for(int j = 1; j <= i; ++j)
        {
            pow *= 10;
        }
        sum += myVector.at(i) * pow;
    }
    cout << sum << endl;
    return 0;
}
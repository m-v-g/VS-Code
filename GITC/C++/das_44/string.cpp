#include <iostream>
#include <regex>
#include <vector>

using namespace std;

int main()
{
    vector<char> myVector;
    string str = "5+3-2+1";
    int sum = 0;
    int i = 0;
    while (str[i])
    {
        myVector.emplace_back(str[i]);
        ++ i;
    }
    cout << "skzbic sum = " << sum << endl;
    for(int i = 0; i < myVector.size(); ++i)
    {
        if(i == 0)//ete araji elementn e
        {
            if (myVector.at(i) >= 48 && myVector.at(i) <= 57) //ete tiv e
            {
                sum = sum + myVector.at(i) - 48;
            }
        }
        else//ete arajin@ che
        {
            if (myVector.at(i) >= 48 && myVector.at(i) <= 57) //ete tiv e
            {
                if(myVector.at(i - 1) == '-')//ete iranic araj - e
                {
                    int temp = myVector.at(i) - 48;
                    sum = sum - temp;
                }
                else
                {
                    sum = sum + myVector.at(i) - 48;
                }
                
            }
        }
    }
    cout << "verjum sum = " << sum << endl;
    
    return 0;
}
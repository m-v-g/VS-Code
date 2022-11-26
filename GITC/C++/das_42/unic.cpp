#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    vector<int> myVector = {22, 54, 11, 79, 33, 5, 48, 22, 17, 11, 33, 95, 41, 33, 22, 33};
    map<int, int> myMap;
    for(int i = 0; i < myVector.size(); ++i) //hertov erdanq mer arjeqnerov
    {
        auto iterator = myMap.find(myVector.at(i)); //es funkcian kveradadzne pointer ed key-ov elementin
        if (iterator != myMap.end()) 
        {
            ++iterator->second; //ete gtel enq ira schetchik@ mekov mecacnenq
        }
        else //ete chi gte kveradardzne hec me texim pointer
        {
            myMap.emplace(myVector.at(i), 1); //ete chenq gte insert enenq schetchik@ 1-ov
        }
    }

    for(auto iterator : myMap) //range based cicle
    {
        cout << iterator.first << " : " << iterator.second << endl;
    }
    return 0;
}
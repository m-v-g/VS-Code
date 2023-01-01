#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <vector>
#include <array>

using namespace std;

int main()
{
    map<string, int> myMap;
    multimap<int, string> myMultiap;

    myMap.emplace("a", 50);
    myMap.emplace("b", 40);
    myMap.emplace("d", 10);
    myMap.emplace("e", 60);
    myMap.emplace("c", 30);
    for(auto iterator : myMap) //range based cicle
    {
        myMultiap.emplace(iterator.second, iterator.first); //invers
    }

    for(auto iterator : myMultiap) //range based cicle
    {
        cout << iterator.first << " : " << iterator.second << endl;
    }
    
    return 0;
}
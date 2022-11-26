#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vec1(10, 77); //zapolnenie vsego vektora chislami

    fill(vec1.begin() + 2, vec1.end() - 2, 55); //zapolnenie opredelennogo uchastka vektora chislami

    for(auto iterator : vec1)
    {
        cout << iterator << endl;
    }
    vector<int> vec2 = {55, 96, 4, 72, 60, 48, 66, 10, 2};

    sort(vec2.begin(), vec2.end()); //algoritm sortirovki

    for(auto iterator : vec2)
    {
        cout << iterator << endl;
    }

    cout <<  binary_search(vec2.begin(), vec2.end(), 48) << endl; //binarny poisk



    return 0;
}
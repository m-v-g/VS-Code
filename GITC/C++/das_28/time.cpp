#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    time_t hmi = time(0);

    cout << hmi << endl;

    char* normalFormat = ctime(&hmi);

    cout << normalFormat << endl;

    return 0;
}

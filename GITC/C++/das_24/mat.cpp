#include <iostream>
#include <cmath>
using namespace std;

class Mathematic
{
public:
    static const float pi;
    static float triangle(int a, int h)
    {
        return a * h / 2;
    }
    static float circle(int r)
    {
        return pi * pow(r, 2);
    }
    static int square(int c)
    {
        return c * c;
    }
};

int const Mathematic::pi = 3.14;

int main()
{
    cout << "Erankyan makeres: " << Mathematic::triangle(2, 5) << endl;
    cout << "Shrjani makeres: " << Mathematic::circle(5) << endl;
    cout << "Qarakusu makeres: " << Mathematic::square(5) << endl;

    return 0;
}

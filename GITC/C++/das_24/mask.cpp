#include <iostream>
using namespace std;

int main()
{
    unsigned int ip = 0b10010101010101011100011110100101;
    /*unsigned int mask = 0b00000000000000000000111100000000;
    unsigned int mask = 1111;
    mask = mask << 28;
    mask = mask >> 20;
    unsigned int net = ip & mask;
    cout << net << endl;
    */
    ip = ip << 20;
    ip = ip >> 28;
    cout << ip << endl;





    return 0;
}
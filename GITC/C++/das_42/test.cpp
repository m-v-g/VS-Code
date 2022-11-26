#include <iostream>
#include <windows.h>
HANDLE hConsole;

using namespace std;

enum
{
    Black = 0,
    DarkBlue = 1,
    Green = 2,
    SkyBlue = 3,
    Red = 4,
    Purple = 5,
    Yellow = 6,
    White = 7
};

int main()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //poluchenie deskriptora konsoli
    for (size_t i = 0; i < 8; i++)
    {
        SetConsoleTextAttribute(hConsole, i);
        cout << "hello world" << endl;
    }
    return 0;
}
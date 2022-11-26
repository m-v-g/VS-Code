#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>

/*0 = Черный

1 = Синий

2 = Зеленый

3 = Голубой

4 = Красный

5 = Лиловый

6 = Желтый

7 = Белый

8 = Серый

9 = Светло-синий

A = Светло-зеленый

B = Светло-голубой

C = Светло-красный

D = Светло-лиловый

E = Светло-желтый

F = Ярко-белый
*/

using namespace std;

HANDLE hConsole;

int main()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 1);
    cout << "Hello World";

    cout << endl;

    SetConsoleTextAttribute(hConsole, 2);
    cout << "Hello World";

    cout << endl;

    SetConsoleTextAttribute(hConsole, 3);
    cout << "Hello World";



    _getch();
    return 0;
}
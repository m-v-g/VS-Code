#include <iostream>
using namespace std;

int main()
{
    char ch1 = 0b01001001;
    char ch2 = ch1;
    ch2 >> 7;
    if(ch2 == 0b00000000) //0
    {
        cout << "1 BIT" << endl;
    }
    else
    {
        ch2 = ch1;
        ch2 >> 5;
        if(ch2 == 0b00000110) //6
        {
            cout << "1 BIT" << endl;
        }
        else
        {
            ch2 = ch1;
            ch2 >> 4;
            if(ch2 == 0b00001110) //14
            {
                cout << "3 BIT" << endl;
            }
            else
            {
                ch2 = ch1;
                ch2 >> 3;
                if(ch2 == 0b00011110) //30
                {
                    cout << "4 BIT" << endl;
                }
                else
                {
                    cout << "???????" << endl;
                }
            }
        }
    }

char16_t b1 = 0b1101011110000011;
char16_t b2 = b1 & 0b0000000000111111;
char16_t b3 = b1 & 0b0001111100000000;
b3 >> 2;
b1 = b2 | b3;
cout << b1;
/*

    if(ch1 <= 247) //4
    else if(ch1 <= 239) //3
    else if(ch1 <= 223) //2
    else//1

    if(ch >= 0) //1
    else
    {
        if(ch <= 247 && ch >= 240) //4
        else if(ch <= 239 && ch >= 224)//3
        else//2
    }
    */

    return 0;
}
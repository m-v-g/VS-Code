#include <iostream>
#include <ctime>

using namespace std;

class MyExeption
{
    public:
        string patchar;
        string lutsum;
        int tiv;
        time_t erb;

        MyExeption(string patchar, string lutsum, int tiv, time_t erb)
        {
            this->patchar = patchar;
            this->lutsum = lutsum;
            this->tiv = tiv;
            this->erb = erb;
        }

        void display()
        {
            cout << "-------------------------------------------" << endl;
            cout << "cause: " << patchar << endl;
            cout << "solution: " << lutsum << endl;
            cout << "because of the number is: " << tiv << endl;
            cout << "when happened: " << ctime(&erb) << endl;
            cout << "-------------------------------------------" << endl;
        } 
};

int main()
{
    bool b = true;

    while (b)
    {
        cout << "start of while" << endl;
        b = false;
        try
        {
            int x = 200;
            int y;
            cout << "insert the Y " << endl;
            cin >> y;
            if(y == 0)
            {
                MyExeption ex("wrong nuber inserted", "inser the number differ from 0", 0, time(0));
                throw ex;
            }
            cout << x/y << endl;
            cout << "test" << endl;
        }
        catch(MyExeption k)
        {
            k.display();
            b = true;
        }
        
    }
    
    return 0;
}
#include <iostream>
using namespace std;

class Myclass
{
    private:
        int* arrPtr;  //stexcenq ukaxatel
        int index = 0;    
        int arrSize = 5;  //masivi chap@ naxnakan 

    public:
        Myclass() //klasi konstruktor
        {
            arrPtr = new int[arrSize]; //dinamik hishoxutyan mej stexcenq mer unecac parametrerov masiv
                                       //(gitenq ira araji elementi ukazateli anun@ u ira chap@)
            cout << "VIZVOLSYA KONSTRUKTOR KLASSA " << endl;
        }

        ~Myclass() //klasi destruktor
        {
            delete[] arrPtr;

            cout << "VIZVOLSYA DESTRUKTOR KLASSA " << endl;
        }
        
        void print(void)  //tpelu funkcia
        {
            cout << endl;
            for(int i = 0; i < arrSize; ++i)
            {
                cout << arrPtr[i] << "\t";
            }
            cout << endl;
        }
        
        bool isEmpty(void) //lriv datarki funkcia
        {
            if(index == 0)
            {
                cout << "Array is empty" << endl;
                return false;
            }
            else
            {
                return true;
            }
        }
        
        bool isFull(void) //ete liqn e
        {
            if(index < arrSize)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        
        void push(int value) //verjic 1 element avelacnelu funkcia
        {
            if(!isFull()) //ete hl@ masivi mej@ tex ka
            {
                arrPtr[index ++] = value; //prost@ kavelacnenq arjeq@
            }
            else //isk ete tex chka krknapatkenq masivi chap@ls
            {
                arrSize *= 2;                      //arrSize el krknapatkenq or myus funkcianer@ gitenan
                cout << "Array is resized & size = " << arrSize << endl;
                int* tempArray = new int[arrSize]; //sarqenq jamanakavor masiv krknaki chapi
                for(int i = 0; i < arrSize / 2; ++i)       //hertov kopya enenq hin masiv meji tver@ taza masivi mej
                {
                    tempArray[i] = arrPtr[i];
                }
                delete[] arrPtr;                //jamanakavor masiv@ anpetq e jnjenq iran
                arrPtr = tempArray;                //jamanakavor masivi hascen grenq hin masivi anvan tak
                arrPtr[index ++] = value;          //mexavor arjeq@ grenq mer taza masivi mej
            }
            
        }
        
        int pop() //geter
        {
            if(isEmpty())
            {
                return arrPtr[-- index];
            }
            else
            {
                return -9999;
            }
        }
        
};




int main()
{
    //setlocale(LC_ALL, "ru");

    Myclass asd;

    for(int i = 1; i <= 10; ++i)
    {
        cout << "pushed " << i * 10  << endl;
        asd.push(i * 10);
    }
    asd.print();
    return 0;
}
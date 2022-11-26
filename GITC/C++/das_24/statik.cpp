#include <iostream>
using namespace std;

class Person
{
private:
    /* data */
public:
    string name;
    string surname;
    int age;
    static int count;
    Person()
    {
        
    }
    Person(string n, string s, int a)
    {
        name = n;
        surname = s;
        age = a;
        ++count;
    }

    static void test(void)
    {
        cout << "ASD asd" << endl;
    }
};
int Person::count = 0;

int main()
{
    Person harevan("dfds", "ffghg", 5);
    Person hare("dfds", "ffghg", 4);
    cout << Person::count << endl;
    Person::test();
    return 0;
}
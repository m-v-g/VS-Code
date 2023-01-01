#include <iostream>
#include <algorithm>
using namespace std;

class Person
{
    public:
        string name;
        string surname;
        int age;
        Person(string name, string surname, int age)
        {
            this->name = name;
            this->surname = surname;
            this->age = age;
        }
};

void firstFoo(int x)
{
    cout << "1 foo : x2 degree= " << x * x << endl;
}

void secondFoo(int x)
{
    cout << "2 foo : x= " << x << endl;
}

void urishFoo(int array[], int size, void(*func)(int y))
{
    for(int i = 0; i < size; ++i)
    {
        func(array[i]);
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};

    urishFoo(arr, 5, firstFoo);

    cout << "-------------------" << endl; 

    urishFoo(arr, 5, secondFoo);

    urishFoo(arr, 5, [](int x) 
    {
        cout << "x3 = " << x * x * x << endl;
    }); //lyambda funkciya

    int arrXar[] {20, 10, 4, 50, 7, 38, 9, 36, 3, 11};
    cout << "=========================" << endl;
    sort(arrXar, arrXar+10, [](int a, int b)
    {
        return a > b;
    });
    for(int iterator : arrXar)
    {
        cout << iterator << endl;
    }
    Person p[] = 
    {
        Person("asdf", "fghfgj", 20),
        Person("sdfdg", "jkhuiyty", 55),
        Person("tyutye", "uiyyiuv", 44),
        Person("uhbhjg", "ueqkj", 77)
    };

    cout << "+++++++++++name <" << endl;
    sort(p, p+4, [](const Person& a, const Person& b)
    {
        return a.name < b.name;
    });
    for(int i = 0; i < 4; ++i)
    {
        cout << p[i].name << " : " << p[i].surname << " : " << p[i].age << endl;
    }

    cout << "+++++++++++name >" << endl;
    sort(p, p+4, [](const Person& a, const Person& b)
    {
        return a.name > b.name;
    });
    for(int i = 0; i < 4; ++i)
    {
        cout << p[i].name << " : " << p[i].surname << " : " << p[i].age << endl;
    }

    cout << "+++++++++++surname <" << endl;
    sort(p, p+4, [](const Person& a, const Person& b)
    {
        return a.surname < b.surname;
    });
    for(int i = 0; i < 4; ++i)
    {
        cout << p[i].name << " : " << p[i].surname << " : " << p[i].age << endl;
    }

    cout << "+++++++++++surname >" << endl;
    sort(p, p+4, [](const Person& a, const Person& b)
    {
        return a.surname > b.surname;
    });
    for(int i = 0; i < 4; ++i)
    {
        cout << p[i].name << " : " << p[i].surname << " : " << p[i].age << endl;
    }

    cout << "+++++++++++age <" << endl;
    sort(p, p+4, [](const Person& a, const Person& b)
    {
        return a.age < b.age;
    });
    for(int i = 0; i < 4; ++i)
    {
        cout << p[i].name << " : " << p[i].surname << " : " << p[i].age << endl;
    }

    cout << "+++++++++++age >" << endl;
    sort(p, p+4, [](const Person& a, const Person& b)
    {
        return a.age > b.age;
    });
    for(int i = 0; i < 4; ++i)
    {
        cout << p[i].name << " : " << p[i].surname << " : " << p[i].age << endl;
    }

    return 0;
}
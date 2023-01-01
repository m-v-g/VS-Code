#include <iostream>
using namespace std;

class Person
{
    private:
        string name;
        string surname;
        int age;
        static Person *ptr;
        static int count;

        Person()
        {
            
        }
        Person(string n, string s, int a)
        {
            name = n;
            surname = s;
            age = a;
            ++ count;
        }
    public:
        
        static Person* createPerson(string n, string s, int a)
        {
            if (count < 3)
            {
                ptr = new Person(n, s, a);
            }
            return ptr;
        }
        void print()
        {
                cout << "Name: " << name << endl;
                cout << "Surname: " << surname << endl;
                cout << "Age: " << age << endl; 
        }
};
Person* Person::ptr = nullptr;
int Person::count = 0;

int main()
{
    Person *a = Person::createPerson("ASD123", "321", 1);
    a->print();
    Person *b = Person::createPerson("321DSA", "000", 2);
    b->print();
    Person *c = Person::createPerson("FGH456", "555", 3);
    c->print();
    Person *d = Person::createPerson("456HGF", "999", 4);
    d->print();
    Person *e = Person::createPerson("987QWE", "777", 5);
    e->print();

    return 0;
}
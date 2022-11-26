#include <iostream>
using namespace std;

class Person
{
    public:
        string name;
        string surname;
        int age;

        Person()
        {
            cout << "---person 0 argument---" << endl;
        }

        Person(string n, string s, int a)
        {
            cout << "---person 3 argument---" << endl;
            this->name = n;
            this->surname = s;
            this->age = a;
        }

        virtual void print(void) //minchev virtual bar@ grel@ inq@ chider or urish memberner el kan
        {                        //ktper es 3 hat@ bayc hmi ktpe sax
                                 //arden gite or iranic baci urish printner kan
            cout << "===Person===" << endl;
            cout << "NAME:\t" << name << endl;
            cout << "SUR:\t" << surname << endl;
            cout << "AGE:\t" << age << endl;
        }
};
class Specialist : public Person
{
    public:
        int iq;
        int languiges;

        Specialist()
        {
            cout << "---specialist 0 argument---" << endl;
        }

        Specialist(string n, string s, int a, int i, int l) : Person(n, s, a)
        {
            cout << "---specialist 5 argument---" << endl;
            this->iq = i;
            this->languiges = l;
        }

        void print(void) //overloading
        {
            cout << "===Specialist===" << endl;
            /*
            cout << "NAME:\t" << name << endl;
            cout << "SUR:\t" << surname << endl;
            cout << "AGE:\t" << age << endl;
            */
            Person::print(); //polimorfizm
            cout << "IQ:\t" << iq << endl;
            cout << "LANG:\t" << languiges << endl;
        }
};
class Medic : public Specialist
{
    public:
    string sity;

    Medic()
    {
        cout << "---medic 0 argument---" << endl;
    }

    Medic(string n, string s, int a, int i, int l, string si) : Specialist(n, s, a, i, l)
    {
        cout << "---medic 6 argument---" << endl;
        this->sity = si;
    }

    void print(void) //overloading
    {
        cout << "===Medic===" << endl;
        /*
        cout << "NAME:\t" << name << endl;
        cout << "SUR:\t" << surname << endl;
        cout << "AGE:\t" << age << endl;
        cout << "IQ:\t" << iq << endl;
        cout << "LANG:\t" << languiges << endl;
        */
        Specialist::print(); //polimorfizm
        cout << "SITY:\t" << sity << endl;
    }
};
class Surgeon : public Medic
{
    public:
    int blabla;

    Surgeon()
    {
        cout << "---surgeon 0 argument---" << endl;
    }

    Surgeon(string n, string s, int a, int i, int l, string si, int b) : Medic(n, s, a, i, l, si)
    {
        cout << "---surgeon 7 argument---" << endl;
        this->blabla = b;
    }

    void print(void) //overloading
    {
        cout << "===Surgeon===" << endl;
        /*
        cout << "NAME:\t" << name << endl;
        cout << "SUR:\t" << surname << endl;
        cout << "AGE:\t" << age << endl;
        cout << "IQ:\t" << iq << endl;
        cout << "LANG:\t" << languiges << endl;
        cout << "SITY:\t" << sity << endl;
        */
        Medic::print(); //polimorfizm
        cout << "BLA:\t" << blabla << endl;
    }
};
class Cardio : public Surgeon
{
    public:
    string heart;

    Cardio()
    {
        cout << "---cardio 0 argument---" << endl;
    }

    Cardio(string n, string s, int a, int i, int l, string si, int b, string h) : Surgeon(n, s, a, i, l, si, b)
    {
        cout << "---cardio 8 argument---" << endl;
        this->heart = h;
    }

    void print(void) //overloading
    {
        cout << "===Cardio===" << endl;
        /*
        cout << "NAME:\t" << name << endl;
        cout << "SUR:\t" << surname << endl;
        cout << "AGE:\t" << age << endl;
        cout << "IQ:\t" << iq << endl;
        cout << "LANG:\t" << languiges << endl;
        cout << "SITY:\t" << sity << endl;
        cout << "BLA:\t" << blabla << endl;
        */
        Surgeon::print(); //polimorfizm
        cout << "HEA:\t" << heart << endl;
    }
};

int main()
{
    Cardio bjishk;
    bjishk.name = "ando";
    bjishk.surname = "andranikyan";
    bjishk.age = 55;
    bjishk.iq = 5;
    bjishk.languiges = 3;
    bjishk.sity = "xapan";
    bjishk.blabla = -10;
    bjishk.heart = 99;
    //bjishk.print();

    //Person mard("anun", "azganun", 20);
    //Specialist ellips("Vasil", "Mkrtchyan", 40, 0, 2);
    //Medic asd("asd", "dsa", 5, 0, 9, "qwerty");
    //Surgeon asd("asd", "dsa", 5, 0, 9, "qwerty", -12);
    //Cardio asd("asd", "dsa", 5, 0, 9, "qwerty", -12, "ewq");

    Specialist* sptr = &bjishk;
    sptr->print();

    Person* ptr = &bjishk;
    ptr->print();

    return 0;
}
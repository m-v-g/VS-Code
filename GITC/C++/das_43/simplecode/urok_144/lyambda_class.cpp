#include <iostream>

using namespace std;

class myClass
{
public:
    int a = 11;
    void msg()
    {
        cout << "MSG" << endl;
    }
    void lyambda()
    { //chtoby zaxvatit ves klass v kontekst nado napisat [this]
        auto f = [this]()
        {
            this->msg();
        };
        f();
    }   
};

int main()
{
    //realizaciya lyambd funkcii izolirovanna ot kontektsta lyambda funkcii
    //esli nado chtobi peremennay naxodyashayasya v kontekste nashoy lyambda funkcii
    //bila dostupna nado ee zaxvatit v kontektst
    //bila chteniya vnutri kontektsta peremennoy nado peredat ee po znacheniyu [b]
    //bila izmineniya vnutri kontektsta peremennoy nado peredat ee po ssilke [&b]
    //chtobi vidit vse peremennie [=]
    //chtobi izmenyat vse peremennie [&]
    //peremennie s mojno perechislit cherez ","
    //chtobi vnutrennem kontekste lyambdi sozdavalis loklnie kopii etix  peremennix 
    //i ix izminenie ne atrajalas vo vneshnem kontekste 
    //ix nado zaxvativat po znacheniyu s dobavleniem kluchevogo slova mutable "[=]()mutable"
    //chtobi lyambda vozvrashyala chtoto nado napisat "return "
    //mojno jostko ukozat tip vozvrashaemogo znacheniya sleduyushim obrazom "[]()->int"
    //nachinaya s C++14 dobavlena vozmojnost ssilatsya na lyambda funkciyu
    //ne tolko s pomoshyu "function<void(int)>" obertki a cerez klyuchevoe slovo "auto"

    myClass obj;
    obj.lyambda();

    cout << "++++++++++++++++" << endl;

    auto f = []()->int
    {
        return 111;
    };

    return 0;
}
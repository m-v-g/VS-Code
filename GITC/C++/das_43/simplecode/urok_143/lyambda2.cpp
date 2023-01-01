#include <iostream>
#include <functional>
#include <vector>
using namespace std;


int main()
{
    vector<int> myVector = {3, 8, 6, 7, 9, 4, 2, 1, 5};
    function<void(int)> f;
    int b = 55;
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
    auto au = [&b]()
    {
        cout << "anonimnaya funkciya s parametrm b = " << b << endl;
        b = 10;
        float c = b;
        return c;
    };
    auto a = au();
    cout << "posle vizova lyambda funkcii peremennaya b = " << b << endl;
    return 0;
}
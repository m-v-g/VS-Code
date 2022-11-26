#include <iostream>
#include <functional>

using namespace std;

//std::function
void foo()
{
    cout << "Vizvalas funkciya foo" << endl;
}
int sum(int a, int b)
{
    return a + b;
}
int main()
{
    function<void ()> f1; //sozdadim obekt function s signaturami sootvetvuyushimi nashey funkcii
    f1 = foo;
    f1();
    function<int (int, int)> f2;
    f2 = sum;
    cout << "Vizvalas funkciya sum = " << sum(5, 6) << endl;
    return 0;
}
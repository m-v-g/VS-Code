#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
typedef map<char, int> MAP_CHAR_INT;
string str_str(const MAP_CHAR_INT& str1, const MAP_CHAR_INT& str2);

int main()
{
    string s1 = "aasdfg";
    string s2 = "ggfdsa";


    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    cout << "Streeng S1 and S2 is equal? " << (s1 == s2 ? "\"YES\"" : "\"NO\"") << endl;

    MAP_CHAR_INT str1;
    MAP_CHAR_INT str2;
    
    for(auto iterator : s1)
    {
        auto res = str1.emplace(iterator, 1); //ete emplace vorpes ira second veradardzrec false
        if(!res.second)                       //uremn es mek@ arden kar u ira second@ 1ov avelacnenq
        {
            auto find = str1[iterator];//ete iterator keyov element gtninq findi mej kgrvi ira valuen
            str1[iterator] = ++find;//[] operatorov kstananq dostup value-in u mekov avelacnenq
        }
    }
 
    for(auto iterator : s2)
    {
        auto res = str2.emplace(iterator, 1); //ete emplace vorpes ira second veradardzrec false
        if(!res.second)                       //uremn es mek@ arden kar u ira second@ 1ov avelacnenq
        {
            auto find = str2[iterator];//ete iterator keyov element gtninq findi mej kgrvi ira valuen
            str2[iterator] = ++find;//[] operatorov kstananq dostup value-in u mekov avelacnenq
        }
    }
/*
    for(auto iterator : str1)
    {
        cout << iterator.first << " : " << iterator.second << endl;
    }
    cout << "++++++++++++++++++" << endl;
    for(auto iterator : str2)
    {
        cout << iterator.first << " : " << iterator.second << endl;
    }
*/

    cout << str_str(str1, str2) << endl;
    return 0;
}

string str_str(const MAP_CHAR_INT& str1, const MAP_CHAR_INT& str2)
{
    string str;
    if(str1.size() == str2.size())
    {
        str += "Lenght is equal ";
    }
    for(int i = 0; i < str1.size() ++i)
    {
        int ch1 = str1[i];
        int ch2 = str2[i];
        if(ch1 != ch2)
        {
            str += "chars count is not equal at index : ";
        }
    }
    return str;
}
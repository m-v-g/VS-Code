#include <iostream>
#include <regex>
using namespace std;



int main()
{
    regex ipv4("(([0-9]|([1-9][0-9])|((1[0-9]{2})|(2[0-4][0-9])|(25[0-5])))\\.){3}([0-9]|([1-9][0-9])|((1[0-9]{2})|(2[0-4][0-9])|(25[0-5])))\\b");
    regex ipv6("([1-9a-f][0-9a-f]{3}:){7}[1-9a-f][0-9a-f]{3}",regex_constants::icase);
    smatch vxojdenie;
    string text = "192.168.0.11 255.255.255.256    2001:6db8:11a3:19d7:1f34:8a2e:27a0:765d";

    while(regex_search(text, vxojdenie, ipv4))
    {
        cout << vxojdenie[0] << endl;
        text = vxojdenie.suffix().str();
    }

    while(regex_search(text, vxojdenie, ipv6))
    {
        cout << vxojdenie[0] << endl;
        text = vxojdenie.suffix().str();
    }

    return 0;
}

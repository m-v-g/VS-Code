#include <iostream>
#include <regex>
using namespace std;



int main()
{
    //regex pasport("[A-Z]{2}[0-9]{7}"); //gtnel sax pasporti hamarner@
    //regex pasport("^[A-Z]{2}[0-9]{7}"); //gtnel toxi skzbi pasporti hamarner@
    //regex pasport("[A-Z]{2}[0-9]{7}$"); //gtnel toxi verji pasporti hamarner@
    regex greedy("J.*n"); //jadny
    regex lazy("J.*?n");  //skupoy

    string jjjj = "John Jeferson is not armenian";

    //string text = "AF9876543 gfgfh 45AV111 jhjh 222AV45"
    " arm_news.am 467646457oiyiuuih News.am     securitysector.am"
    "+37477 05-70-66 HFHGFHFHFHJJJGJGJ 096 63 62 01 JGGGHGFHFJGJ 096 63-62-01 JJJKJKHJKHKJH +37477 057066"
    " Vasil Mkrtchyan    VAsil Mkrtchyan   vasil Mkrtchyan   Vasil mkrtchyan    Mkrtchyan Vasil"
    "02.07.2022 14:17     02/07/2022 14:17     02-07-2022 14:17:59   02 07 2022 14:45:59    32.17.2022 25:58 " 
    "AR1234567   ar7654321  ASD123456"
    "vasil_mkrtchyan@yahoo.com   m-v-g@mail.ru  info@securitysector.am AS1122334";

    smatch vxojdenie; //klas vor@ kpahi sparich informacia

    while(regex_search(jjjj, vxojdenie, lazy))
    {
        cout << vxojdenie[0] << endl;
        jjjj = vxojdenie.suffix().str();
    }


    return 0;
}
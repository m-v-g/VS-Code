#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main () {
        set <int> s;
        long st_s = clock();
        for(int i =0; i < 100000; ++i) {
                s.emplace(rand()%10000 +1);
        }
        long end_s = clock();
        //for (auto x :s ){
        //        cout << x << endl;
        //}

        //long st_s = clock();
        if(s.find(rand()%10000+1) == s.end()){
               cout <<"not found "<< endl;
        } else {
               cout <<"found "<< endl;
        }
        //long end_s = clock();
        long set_time = end_s-st_s;
        cout << "duration is equal : " << set_time  << endl;
        unordered_set <int> us;
        long st_us = clock();
        for(int i =0; i < 100000; ++i) {
                us.emplace(rand()%10000 +1);
        }
        long end_us = clock();
        //long st_us = clock();
        if(us.find(rand()%10000+1) == us.end()){
               cout <<"not found "<< endl;
        } else {
               cout <<"found "<< endl;
        }
        //long end_us = clock();
        long unordered_set = end_us-st_us;
        cout << "us duration is equal :" << unordered_set  << endl;
        cout << "us duration is equal :" << unordered_set-set_time  << endl;

        //for (auto x :us ){
        //        cout << x << endl;
        //}
        return 0;
}
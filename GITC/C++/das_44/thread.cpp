#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>
using namespace std;
double gumar = 1000;
//mutex mut;
double hanac = 0;
void f(double x)
{
    cout << "ID potoka: " << this_thread::get_id() << "\tWORK\t" << endl;
        //mut.lock();
        if(x<gumar){
                sleep(5);
                gumar = gumar - x;
                hanac = hanac + x;
        }else{
                cout<<"prcel e"<<endl;
        }
        //mut.unlock();
}
int main()
{
    std::thread t(&f, 990);   // t starts running
    std::thread t1(&f, 990);   // t starts running
    std::thread t2(&f, 990);   // t starts running
    std::thread t3(&f, 990);   // t starts running
    std::thread t4(&f, 990);   // t starts running
    std::cout << "main thread\n";
    cout << "ID potoka: " << this_thread::get_id() << "\tMAIN\t" << endl;
    //cout<<"hardware concurrency = "<<thread::hardware_concurrency()<<endl;
    t.join();   // main thread waits for the thread t to finish
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    cout<<"gumar=="<<gumar<<endl;
    cout<<"hanvel e "<<hanac<<endl;
    return 0;
}
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
void doWork()
{
    for (size_t i = 0; i < 10; ++i)
    {
        cout << "ID potoka: " << this_thread::get_id() << "\tWORK\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}
int main()
{
    //doWork();
    thread th(doWork);
    for (size_t i = 0; i < 10; ++i)
    {
        cout << "ID potoka: " << this_thread::get_id() << "\tMAIN\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    th.join();
    return 0;
}
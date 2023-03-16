#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

using namespace std;

mutex mtx; //mutual exclusion

int main()
{
    auto work_func = [](const string& name)
    {
        for (int i = 0; i < 5; i++)
        {
            std::this_thread::sleep_for(chrono::milliseconds(100));

            //출력할때는 하나의 쓰레드 접근하게 설정
            mtx.lock(); 
            cout << name << " " << std::this_thread::get_id();
            cout << " is working " << i << endl;
            mtx.unlock();
        }
    };
    
    //work_func("Jack Jack");
    //work_func("Dash");
    
    std::thread t1 = std::thread(work_func, "Jack Jack");
    std::thread t2 = std::thread(work_func, "Dash");

    t1.join();
    t2.join();

    return 0;
}
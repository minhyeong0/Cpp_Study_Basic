#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>


using namespace std;

mutex mtx;

int main()
{
    //공유 메모리
    //int shared_memory(0);

    //공유메모리에 동시 여러 쓰레드가 접근 불가능
    atomic<int> shared_memory(0);

    auto count_func = [&]()
    {
        for (int i = 0; i < 1000; i++)
        {
            //sleep_for 안적어주면 2000이 나오는데 이유는
            //컴퓨터의 속도는 매우 빠르므로 t1쓰레드가 생성되고 1000을 한번에 다 더하고 
            //t2 쓰레드가 1000을 더하기 때문에 2000이 나옴
            this_thread::sleep_for(chrono::microseconds(1));
            
            //공유메모리에 동시에 여러 쓰레드가 접근 불가능
            //mtx.lock();
            
            //mtx.lock()과 비슷, 스코프를 벗어나면 자동으로 락 해제해줌
            //std::lock_guard lock(mtx); //C++ 17

            //std::lock_guard() 보다 진보된 락(권장)
            std::scoped_lock lock(mtx);

            //shared_memory.fetch_add(1);
            shared_memory++;
            
            //mtx.unlock();
        }
    };

    thread t1 = thread(count_func);
    thread t2 = thread(count_func);
    t1.join();
    t2.join();

    cout << "After" << endl;
    cout << shared_memory << endl;


    return 0;
}
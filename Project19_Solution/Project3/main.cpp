#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

using namespace std;


int main()
{
    //논리 프로세서 개수
    const int num_pro = std::thread::hardware_concurrency();

    //메인 쓰레드의 쓰레드 id
    cout << std::this_thread::get_id() << endl;

    vector<std::thread> my_threads;
    my_threads.resize(num_pro);

    //논리 프로세서 개수 만큼 쓰레드 생성
    for (auto& e : my_threads)
        e = std::thread([]() {
            cout << std::this_thread::get_id() << endl;
            while (true)
            {
            }
        });

    for (auto& e : my_threads)
        e.join();

    //std::thread t1 = std::thread([]() {
    //    cout << std::this_thread::get_id() << endl;
    //    while (true)
    //    {
    //    }
    //});

    //std::thread t2 = std::thread([]() {
    //    cout << std::this_thread::get_id() << endl;
    //    while (true)
    //    {
    //    }
    //});

    //std::thread t3 = std::thread([]() {
    //    cout << std::this_thread::get_id() << endl;
    //    while (true)
    //    {
    //    }
    //});

    //std::thread t4 = std::thread([]() {
    //    cout << std::this_thread::get_id() << endl;
    //    while (true)
    //    {
    //    }
    //});

    //메인쓰레드에서 t1 쓰레드가 끝날때까지 대기
    //t1.join();
    //t2.join();
    //t3.join();
    //t4.join();

    return 0;
}
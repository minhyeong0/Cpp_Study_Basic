#include <iostream>
#include <future>
#include <thread>

using namespace std;


int main()
{
    //multi-threading
    //{
    //    int result;
    //    std::thread t([&]() {result = 1 + 2; });
    //    t.join();
    //    cout << result << endl;
    //}

    //task-based parallelism
    //{
    //    //std::future<int> fut = ...
    //    //메인 쓰레드와 별개로 작업이 이루어짐
    //    //비동기 함수 async
    //    auto fut = std::async([] {return 1 + 2; });

    //    //비동기 함수의 작업이 끝나지 않았다면 대기
    //    cout << fut.get() << endl;
    //}

    //future and promise
    //{
    //    //thread에서 future 사용하기 위해서 promise 선언해아함
    //    std::promise<int> prom;

    //    auto fut = prom.get_future();
    //    //promise를 파라미터로 전달해야 함
    //    auto t = std::thread([](std::promise<int>&& prom)
    //    {
    //        //promise에 값을 넣어 future에 전달함
    //        prom.set_value(1 + 2);
    //    }, std::move(prom));

    //    //promise의 작업이 끝나지 않았다면 대기
    //    cout << fut.get() << endl;
    //    t.join();
    //}


    {
        auto f1 = std::async([] {
            cout << "async 1 start" << endl;
            this_thread::sleep_for(chrono::seconds(2));
            cout << "async 1 end" << endl;
        });

        auto f2 = std::async([] {
            cout << "async 2 start" << endl;
            this_thread::sleep_for(chrono::seconds(1));
            cout << "async 2 end" << endl;
        });


        //future로 안 받아주면 순차적으로 실행됨
        //std::async([] {
        //    cout << "async 1 start" << endl;
        //    this_thread::sleep_for(chrono::seconds(2));
        //    cout << "async 1 end" << endl;
        //});

        //std::async([] {
        //    cout << "async 2 start" << endl;
        //    this_thread::sleep_for(chrono::seconds(1));
        //    cout << "async 2 end" << endl;
        //});


        //auto t1 = std::thread([] {
        //    cout << "async 1 start" << endl;
        //    this_thread::sleep_for(chrono::seconds(2));
        //    cout << "async 1 end" << endl;
        //});

        //auto t2 = std::thread([] {
        //    cout << "async 2 start" << endl;
        //    this_thread::sleep_for(chrono::seconds(1));
        //    cout << "async 2 end" << endl;
        //});

        //t1.join();
        //t2.join();
        
        cout << "Main function" << endl;
    }

    return 0;
}
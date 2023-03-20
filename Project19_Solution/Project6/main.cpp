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
    //    //���� ������� ������ �۾��� �̷����
    //    //�񵿱� �Լ� async
    //    auto fut = std::async([] {return 1 + 2; });

    //    //�񵿱� �Լ��� �۾��� ������ �ʾҴٸ� ���
    //    cout << fut.get() << endl;
    //}

    //future and promise
    //{
    //    //thread���� future ����ϱ� ���ؼ� promise �����ؾ���
    //    std::promise<int> prom;

    //    auto fut = prom.get_future();
    //    //promise�� �Ķ���ͷ� �����ؾ� ��
    //    auto t = std::thread([](std::promise<int>&& prom)
    //    {
    //        //promise�� ���� �־� future�� ������
    //        prom.set_value(1 + 2);
    //    }, std::move(prom));

    //    //promise�� �۾��� ������ �ʾҴٸ� ���
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


        //future�� �� �޾��ָ� ���������� �����
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
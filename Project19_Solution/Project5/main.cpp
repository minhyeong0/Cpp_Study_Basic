#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>


using namespace std;

mutex mtx;

int main()
{
    //���� �޸�
    //int shared_memory(0);

    //�����޸𸮿� ���� ���� �����尡 ���� �Ұ���
    atomic<int> shared_memory(0);

    auto count_func = [&]()
    {
        for (int i = 0; i < 1000; i++)
        {
            //sleep_for �������ָ� 2000�� �����µ� ������
            //��ǻ���� �ӵ��� �ſ� �����Ƿ� t1�����尡 �����ǰ� 1000�� �ѹ��� �� ���ϰ� 
            //t2 �����尡 1000�� ���ϱ� ������ 2000�� ����
            this_thread::sleep_for(chrono::microseconds(1));
            
            //�����޸𸮿� ���ÿ� ���� �����尡 ���� �Ұ���
            //mtx.lock();
            
            //mtx.lock()�� ���, �������� ����� �ڵ����� �� ��������
            //std::lock_guard lock(mtx); //C++ 17

            //std::lock_guard() ���� ������ ��(����)
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
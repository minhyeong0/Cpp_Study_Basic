#include <iostream>

using namespace std;


int main()
{
    //int* ptr = new (std::nothrow) int(7);
    //int* ptr2 = ptr;

    //delete ptr;
    //ptr = nullptr;
    //ptr2 = nullptr; //ptr2도 nullptr로 초기화 해야 함
    

    //memory leak
    while (true)
    {
        //메모리를 반납안하면 메모리 누수 발생
        int* ptr = new int;
        cout << ptr << endl;
        
        //delete ptr;
    }

    return 0;
}
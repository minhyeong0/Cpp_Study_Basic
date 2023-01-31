#include <iostream>

using namespace std;


int main()
{
    //아래와 같음
    //int var;
    //var = 7;

    //int 사이즈(4byte) 크기의 메모리를 OS에게 받아 온 다음
    //그 메모리 주소를 반환함
    //int* ptr = new int;
    //*ptr = 7;
    

    //할당과 초기화 동시에 하는 법1
    //int* ptr = new int(7);

    //할당과 초기화 동시에 하는 법2
    //int* ptr = new int{ 7 };

    //OS에게 메모리를 할당 받지 못한 경우 에러 무시하기
    int* ptr = new (std::nothrow) int{ 7 };

    if (ptr)
    {
        cout << ptr << endl;
        cout << *ptr << endl;
    }
    else
    {
        cout << "Could not allcate memory" << endl;
    }
    //OS에게 할당받은 메모리 반환
    delete ptr;
    
    //c style
    //ptr = 0; 
    //ptr = NULL;

    ptr = nullptr;
    cout << "After Delete" << endl;
    if (ptr != nullptr)
    {
        cout << ptr << endl;
        cout << *ptr << endl;
    }

    return 0;
}
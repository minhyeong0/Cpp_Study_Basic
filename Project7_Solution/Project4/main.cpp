#include <iostream>

using namespace std;

//& 안쓰면 함수 파라미터 자체의 주소가 인자로 전달 받은 포인터 자체의 주소와 일치하지 않게 됨
void foo(int*& ptr)
{
    cout << ptr << " " << &ptr << endl;
}

int main()
{
    int x = 5;
    int* ptr = &x;
    
    cout << ptr << " " << &ptr << endl;
    foo(ptr);

    return 0;
}
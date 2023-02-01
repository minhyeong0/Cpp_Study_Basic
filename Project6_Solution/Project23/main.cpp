#include <iostream>

using namespace std;

enum Type
{
    INT,
    FLOAT,
    CHAR,
};


//void pointer, generic pointer

int main()
{
    int i = 5;
    char c = 'a';
    float f = 3.0;

    void* ptr = nullptr; //여러 자료형 포인터를 담을 수 있음

    ptr = &i;
    ptr = &c;
    ptr = &f;

    //cout << ptr + 1 << endl; //자료형의 크기를 알 수 없어서 포인터 연산 불가능
    cout << &f << " " << ptr << endl;

    //int* ptr_i = &i; //일반 포인터는 포인터 연산 사용가능
    //cout << ptr_i << endl;
    //cout << ptr_i + 1 << endl;

    //cout << *ptr << endl; //void 포인터는 역참조할때 형변환 해야함
    cout << *static_cast<float*>(ptr) << endl;
    
    Type type = FLOAT;

    if(type == FLOAT)
        cout << *static_cast<float*>(ptr) << endl;
    else if(type == INT)
        cout << *static_cast<int*>(ptr) << endl;
    else if(type == CHAR)
        cout << *static_cast<char*>(ptr) << endl;

    return 0;
}
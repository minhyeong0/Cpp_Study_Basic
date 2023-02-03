#include <iostream>

using namespace std;

int func(int x)
{
    return 5;
}

int goo(int y)
{
    return 10;
}

int main()
{
    //함수도 주소를 가지고 있음
    cout << func << endl;

    
    //함수 포인터 선언 하는 방법 : 리턴타입(*함수포인터이름)(매개변수)
    int(*fcnptr)(int) = func;
    
    //함수 포인터 역참조하는 방법
    cout << fcnptr(1) << endl;
    
    fcnptr = goo;

    cout << fcnptr(1) << endl;
    

    return 0;
}
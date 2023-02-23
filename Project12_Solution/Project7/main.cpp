#include <iostream>

using namespace std;


class Base
{
    //Base VTable
    //fun1() //pointer
    //fun2() //pointer
    
    //vptr가 Base VTable을 찾는다.
    //FunctionPointer *_vptr;
    virtual void fun1() {}
    virtual void fun2() {}
};

class Der : public Base
{
    //Der VTable
    //fun1() //pointer
    //부모 클래스의 함수를 가리킴
    //fun2() //pointer

    //FunctionPointer *_vptr;
    virtual void fun1() {}
    //void fun3() {}
};

int main()
{
    cout << sizeof(Base) << endl;
    cout << sizeof(Der) << endl;

    return 0;
}
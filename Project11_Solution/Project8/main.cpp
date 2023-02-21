#include <iostream>

using namespace std;


class Base
{
protected:
    int m_i;

public:
    Base(int value)
        :m_i(value)
    {}

    void print()
    {
        cout << "I'm base" << endl;
    }
};

class Derived : public Base
{
public:
    Derived(int value)
        :Base(value)
    {}

    //외부에서 Base 클래스에 있는 m_i 접근 허용
    using Base::m_i;

private:
    //외부에서 Base 클래스에 있는 print() 접근 불허용 방법 2가지
    using Base::print; //do not add ()
    void print() = delete;  //부모에게 상속받은 print() 함수 삭제
};

int main()
{
    Base base(5);
    //base.m_i = 1024;
    base.print();

    Derived derived(7);
    derived.m_i = 1024;
    //derived.print();

    return 0;
}
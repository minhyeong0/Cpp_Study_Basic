#include <iostream>

using namespace std;


class Base
{
public:
    int m_public;

protected:
    int m_protected;

private:
    int m_private;
};

//클래스 상속 접근 지정자
class Derived : private Base
{
public:
    Derived()
    {
        //클래스 안에서는 상속 접근 지정자보다 범위가 큰 접근 지정자에 접근 가능
        Base::m_public;    //가능
        Base::m_protected; //가능
        //Base::m_private; //불가능
    }
};

class GrandChild : public Derived
{
public:
    GrandChild()
    {
        //부모 클래스의 접근 지정자가 private면 접근 불가능
        //Derived::Base::m_public;
        //Derived::Base::m_protected;
        //Derived::Base::m_private;
    }
};


int main()
{
    //Base base;

    //base.m_public = 123; //가능
    ////base.m_protected = 123; //불가능
    ////base.m_private = 123; //불가능


    Derived derived;

    //클래스 상속 접근 지정자보다 범위가 큰 접근 지정자에서는 접근 불가능
    //derived.m_public = 1024;

    return 0;
}
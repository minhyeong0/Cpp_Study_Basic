#include <iostream>

using namespace std;

class A;

class B
{
private:
    int m_value = 2;
public:
    void doSomething(A& a);
};

class A
{
private:
    int m_value = 1;
    
    //frined 해당 클래스의 private 맴버에 접근 가능
    //friend class B;
    
    //특정 private 맴버에만 접근 허용하는 방법
    friend void B::doSomething(A& a);
};

void B::doSomething(A& a)
{
    cout << a.m_value << endl;
}


int main()
{
    A a;
    B b;
    
    b.doSomething(a);

    return 0;
}
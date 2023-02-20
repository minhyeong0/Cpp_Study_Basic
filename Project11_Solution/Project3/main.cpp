#include <iostream>

using namespace std;

class Mother
{
//private:
public:
    int m_i;

    Mother(const int& i_in = 0)
        :m_i(i_in)
    {
        cout << "Mother Construction" << endl;
    }
};

class Child : public Mother
{
public:
    double m_d;
public:
    Child()
        //부모 생성자 순서 상관없이 부모 생성자에서 먼저 초기화 하고
        //이후 자식 생성자가 초기화 됨
        :m_d(1.0), Mother(1024)
    {
        //this->m_i = 10; //부모 클래스 public, protected 일때 가능
        //this->Mother::m_i = 1024;
        cout << "Child Construction" << endl;
    }
};

class A
{
public:
    A()
    {
        cout << "A constructor" << endl;
    }
};

class B : public A
{
public:
    B()
    {
        cout << "B constructor" << endl;
    }
};

class C : public B
{
public:
    C()
    {
        cout << "C constructor" << endl;
    }
};
int main()
{
    //부모 생성자가 호출되서 초기화 한 이후 자식 생성자가 초기화함
    //Child c1; 

    //상속이 여러번 될 때는 최상위 부모 생성자부터 호출 됨
    C c;
    return 0;
}
#include <iostream>

using namespace std;

class Mother
{
private:
    int m_i;

public:
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
    //int m_temp; //패딩 발생
public:
    Child()
        :m_d(1.0), Mother(1024)
    {
        cout << "Child Construction" << endl;
    }
};

class A
{
public:
    A(int a)
    {
        cout << "A: " << a << endl;
    }

    ~A()
    {
        cout << "Destructor A" << endl;
    }
};

class B : public A
{
public:
    B(int a, double d)
        :A(a)
    {
        cout << "B: " << d << endl;
    }

    ~B()
    {
        cout << "Destructor B" << endl;
    }
};

class C : public B
{
public:
    C(int a, double d, char c)
        :B(a, d)
    {
        cout << "C: " << c << endl;
    }

    ~C()
    {
        cout << "Destructor C" << endl;
    }
};

int main()
{
    //cout << sizeof(Mother) << endl;
    ////상속 받은 클래스의 메모리 크기만큼 추가로 할당 함
    //cout << sizeof(Child) << endl;

    //소멸자는 자식부터 사라짐
    C c(1024, 3.14, 'a');

    return 0;
}
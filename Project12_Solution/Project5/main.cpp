#include <iostream>

using namespace std;

class Base
{
public:
    virtual ~Base()
    {
        cout << "~Base()" << endl;
    }
};

class Derived : public Base
{
private:
    int* m_array;

public:
    Derived(int length)
    {
        m_array = new int[length];
    }

    //부모 클래스 소멸자에서 virtual 제거하면 override 안됨
    ~Derived() override
    {
        cout << "~Derived()" << endl;
        delete[] m_array;
    }

};

int main()
{
    //Derived derived(5);

    Derived* derived = new Derived(5);
    Base* base = derived;
    //부모 소멸자에 virtual을 안 붙였을 때는 부모 소멸자만 호출함
    //부모 소멸자에 virtual을 붙이면 부모 소멸자와 자식 소멸자도 둘다 호출 됨
    delete base; 

    return 0;
}
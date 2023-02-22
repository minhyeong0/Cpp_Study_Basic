#include <iostream>

using namespace std;

class A
{
public:
    void print() { cout << "A" << endl; }
    //일반적으로는 리턴타입이 다르면 오버라이딩이 안되지만
    //자신의 클래스 타입 포인터를 리턴하면 오버라이딩 가능
    virtual A* getThis() 
    { 
        cout << "A::getThis()" << endl;
        return this; 
    }
};

class B : public A
{
public:
    void print() { cout << "B" << endl; }
    virtual B* getThis() 
    { 
        cout << "B::getThis()" << endl;
        return this; 
    }
};


int main()
{
    A a;
    B b;

    A& ref = b;


    //b의 getThis()가 실행됨
    b.getThis()->print();   //B

    //b의 getThis()가 실행됨 (A의 virtual getThis()를 B가 상속)
    //B의 포인터 리턴해도 ref의 타입이 A이기 때문에 A 포인터를 리턴함
    ref.getThis()->print(); //A

    cout << typeid(b.getThis()).name() << endl; 
    cout << typeid(ref.getThis()).name() << endl; 


    return 0;
}
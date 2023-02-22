#include <iostream>

using namespace std;

class A
{
public:
    //함수는 파라미터가 다르면 오버라이딩 불가능
    virtual void print() const { cout << "A" << endl; }
};

class B : public A
{
public:
   //부모 클래스 함수 오버라이딩 할때 override 키워드 사용하기
    void print() const override final { cout << "B" << endl; }
};

class C : public B
{
public:
    //부모 클래스에서 final 키워드 사용하면 자식 클래스에서 오버라이딩 불가능
    //virtual void print() const { cout << "C" << endl; }
};

int main()
{
    A a;
    B b;
    C c;

    A& ref = b;
    ref.print();

    return 0;
}
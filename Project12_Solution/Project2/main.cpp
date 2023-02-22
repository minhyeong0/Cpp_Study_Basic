#include <iostream>

using namespace std;

class A
{
public:
    //virtual : 가상함수
    virtual void print() { cout << "A" << endl; }
};

class B : public A
{
public:
    /*virtual*/ void print() { cout << "B" << endl; }
};

class C : public B
{
public:
    /*virtual*/ void print() { cout << "C" << endl; }
};

class D : public C
{
public:
    /*virtual*/ void print() { cout << "D" << endl; }
};

int main()
{
    A a;
    B b;
    C c;
    D d;

    //부모 클래스가 virtual 안 썼을 때 : 모두 부모 클래스 함수 호출
    //A& ref = b; //a를 상속 
    //A& ref = c; //b를 통해 a를 상속
    //A& ref = d;   //c를 통해 a를 상속

    //부모 클래스가 virtual 일 때 : 자식 클래스 함수 호출
    //A& ref = b;
    //ref.print(); //B

    //부부모 클래스는 virtual, 부모 클래스 virtual 안썼을 때 :
    //부모 클래스가 virtual이 아니여도 자식 클래스 함수 호출
    //A& ref = c;
    //ref.print(); //C


    //가장 상위 부모가 virtual이면 그 아래 부모들도 전부 virtual 붙은 것처럼 작동함
    //부부모 클래스는 virtual, 부모 클래스 virtual 안썼을 때 :
    //부모 클래스가 virtual이 아니여도 자식 클래스 함수 호출
    B& ref = c;
    ref.print(); //C

    return 0;
}
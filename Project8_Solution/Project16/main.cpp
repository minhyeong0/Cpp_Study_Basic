#include <iostream>

using namespace std;

//클래스 전방 선언
class B;

class A
{
private:
    int m_value = 1;

    //friend로 함수나 클래스를 선언하면 private 맴버에 접근 가능
    //클래스 B가 아래 있어서 B의 존재를 알지 못해 에러 발생할 경우 클래스 전방 선언하기
    friend void doSomething(A& a, B& b);
};

class B
{
private:
    int m_value = 2;
    friend void doSomething(A& a, B& b);
};

void doSomething(A& a, B& b)
{
    cout << a.m_value << " " << b.m_value << endl;
}

int main()
{
    A a;
    doSomething(a);

    return 0;
}
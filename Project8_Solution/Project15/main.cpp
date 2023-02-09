#include <iostream>

using namespace std;

class Something
{
public:
    //간접적으로 생성자에서 static 변수 초기화 방법
    class _init
    {
    public:
        _init()
        {
            s_value = 9876;
        }
    };

private:
    static int s_value;
    int m_value;
    static _init s_initalizer;

public:
    Something()
        //클래스 변수는 인스턴스 생성전 에도 존재해야하므로 오류
        :m_value(123) //,s_value(1024)
    {
        //생성자에서 클래스 변수 초기화 불가능
    }
    static int getValue()
    {
        //클래스 변수, 클래스 함수는 this 불가능
        return /*this->*/s_value;
       
        //클래스 함수에서 인스턴스 변수 사용 불가능
        ///return m_value;
    }

    int temp()
    {
        return this->s_value;
    }
};

int Something::s_value = 1024;
//클래스 
Something::_init Something::s_initalizer;
int main()
{
    //cout << Something::s_value << endl;
    cout << Something::getValue() << endl;

    Something s1, s2;
    cout << s1.getValue() << endl;
    //cout << s1.s_value << endl;

    //함수포인터 인스턴스 함수 저장 방법
    //인스턴스 함수는 인스턴스가 생성될 때마다 만드는 것이 아니라 함수를 공유함
    int (Something:: * fptr1)() = &Something::temp;    
    cout << (s2.*fptr1)() << endl;

    //함수포인터 클래스 함수 저장 방법
    int (*fptr2)() = &Something::getValue;
    cout << fptr2() << endl;

    return 0;
}
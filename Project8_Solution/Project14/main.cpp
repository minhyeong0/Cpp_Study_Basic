#include <iostream>

using namespace std;

class Something
{
public:
    static int s_value1 /*= 1*/; //클래스 내에서 정적 변수 초기화 불가능
    
    //constexpr : 컴파일 타임에 값이 결정되는 경우 사용
    static constexpr int s_value2 = 3; //상수인 경우 클래스 안에서 초기화 가능
};

//definded in cpp
int Something::s_value1 = 1; //클래스 밖에서 정적 변수 초기화 가능

//int Something::s_value2 = 1; //상수인 경우 클래스 밖에서 초기화 불가능 


int generateID()
{
    static int s_id;
    return ++s_id;
}

int main()
{
    cout << &Something::s_value1 << " " << Something::s_value1 << endl;

    Something st1;
    Something st2;

    st1.s_value1 = 2;

    cout << &st1.s_value1 << " " << st1.s_value1 << endl;
    cout << &st2.s_value1 << " " << st2.s_value1 << endl;

    Something::s_value1 = 1024;
    cout << &Something::s_value1 << " " << Something::s_value1 << endl;


    //클래스 변수이므로 불가능
    //Something::s_value2 = 3;

    return 0;
}
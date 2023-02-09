#include <iostream>

using namespace std;

class Something
{
public:

    int m_value = 0;
    
    //함수 파라미터의 인스턴스 변수가 참조변수(&) 타입이 아닌 경우에는 
    //인스턴스로 전달 받은 값을 복사해서 함수에게 전달함 (주소가 달라짐)
    //default copy contructor (원래는 컴파일러가 자동으로 추가해줌, 생략가능)
    Something(const Something& st_in)
    {
        cout << "Copy Constructor" << endl;
        m_value = st_in.m_value;
    }

    Something()
    {
        cout << "Constructor" << endl;
    }

    void setValue(int value)
    {
        m_value = value;
    }
    
    //맴버 함수 const로 만들기, 맴버변수의 값을 안바꾼다는 의미
    int getValue() const
    {
        return m_value; 
    }

};

//함수 파라미터의 인스턴스 변수가 참조변수 타입인 경우
//기존 인스턴스의 주소값을 복사해서 함수에게 전달함 (주소가 같음)
void print(const Something& st)
{
    cout << &st << endl;
    cout << st.getValue() << endl;
}

int main()
{
    //클래스로 부터 만들어진 인스턴스의 값을 상수로 만듦
    //const Something something;

    //값 변경 X
    //something.setValue(3);

    //인스턴스를 상수로 만들었을때는 const member function()만 사용가능
    //cout << something.getValue() << endl;

    Something something;
    
    //cout << &something << endl;
    //print(something);


    return 0;
}
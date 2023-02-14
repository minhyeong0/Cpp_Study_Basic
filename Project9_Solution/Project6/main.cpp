#include <iostream>

using namespace std;

class Digit
{
private:
    int m_digit;

public:
    Digit(int digit = 0) : m_digit(digit) {}

    //전위 증감 연산자 오버로딩
    Digit& operator ++ ()
    {
        ++m_digit;
        return *this;
    }
     
    //후위 증감 연산자 오버로딩
    //파라미터에 더미 아무거나 추가하면 후위 연산자
    Digit operator ++ (int) 
    {
        Digit temp(m_digit);
        ++(*this); //전위연산자 오버로딩 사용
        return temp;
    }

    //출력 연산자 오버로딩
    friend ostream& operator << (ostream& out, const Digit d)
    {
        out << d.m_digit;
        return out;
    }
};

int main()
{
    Digit d(5);

    cout << ++d << endl;
    cout << d << endl;

    cout << d++ << endl;
    cout << d << endl;


    return 0;
}
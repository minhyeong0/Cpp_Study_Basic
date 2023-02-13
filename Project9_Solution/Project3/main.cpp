#include <iostream>

using namespace std;

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents = 0) { m_cents = cents; }
    int getCent() const { return m_cents; }
    int& getCent() { return m_cents; }

    //단항 연산자 오버로딩
    Cents operator - () const
    {
        return Cents(-m_cents);
    }

    bool operator ! () const
    {
        //: m_cents가 0이면 true, 아니면 false 리턴하게 설정
        return (m_cents == 0) ? true : false;
    }

    friend std::ostream& operator << (std::ostream& out, const Cents& cents)
    {
        out << cents.m_cents;
        return out;
    }
};

int main()
{
    Cents cents1(6);
    Cents cents2(0);

    //cout << cents1 << endl;
    //cout << -cents1 << endl;
    //cout << -Cents(-10) << endl;
    
    //0 : false, 0이 아닌값 : true
    cout << !cents1 << " " << !cents2 << endl;
    return 0;
}
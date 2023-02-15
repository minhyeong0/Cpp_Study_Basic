#include <iostream>
#include <cassert>

using namespace std;

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(int num = 0, int den = 1)
        :m_numerator(num), m_denominator(den)
    {
        assert(den != 0);
    }

    //복사 생성자 : 자기와 타입이 같은 인스턴스를 복사함
    //복사 사용자를 외부에서 접근하지 못하게 하고 싶을 때 접근지정자를 private로 설정
    Fraction(const Fraction& fraction)
        :m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
    {
        cout << "copy constructor called" << endl;
    }

    //출력 연산자 오버로딩
    friend std::ostream& operator << (std::ostream& out, const Fraction& f)
    {
        out << f.m_numerator << " / " << f.m_denominator << endl;
        return out;
    }
};

Fraction doSomething()
{
    Fraction temp(1, 2);
    cout << &temp << endl;
    return temp;
}

int main()
{
    //Fraction frac(3, 5);

    ////Fraction fr_copy(frac);
    //Fraction fr_copy = frac;

    //cout << frac << " " << fr_copy << endl;
    
    Fraction result = doSomething();
    //디버그 모드에서는  복사 생성자를 사용해서 주소값이 다르지만
    //릴리즈 모드에서는 컴파일러가 최적화해서 주소가 같음
    cout << &result << endl;
    cout << result << endl;
    return 0;
}
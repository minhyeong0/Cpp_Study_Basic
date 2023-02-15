#include <iostream>
#include <cassert>

using namespace std;

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    //delte 키워드 : 생성자에 들어갈 타입 제한 가능
    //생성자 char 타입 허용 안함
    Fraction(char) = delete;

    explicit Fraction(int num = 0, int den = 1)
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

//변환 생성자 : 함수파라미터가 클래스 타입 밖에 없을 때 파라미터로 받은 값이
// 인스턴스가 아닌 경우 자동으로 생성자를 이용해서 인스턴스로 바꿔줌
//생성자에 explicit 키워드를 사용하면 변환 생성자 사용 불가
void doSomething(Fraction frac)
{
    cout << frac << endl;
}

int main()
{
    //Fraction frac(7);

    ////doSomething(7);
    //doSomething(frac);
    

    Fraction frac2('c');


    return 0;
}
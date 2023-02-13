#include <iostream>

using namespace std;


class Cents
{
private:
    int m_cnets;

public:
    Cents(int cents = 0) { m_cnets = cents; }
    int getCents() const { return m_cnets; }
    int& getCents() { return m_cnets; }
    
    //firend : private 맴버를 외부에서 접근허용
    //산술 연산자는 오버로딩해도 연산자 우선순위는 변하지 않음
    //friend Cents operator + (const Cents& c1, const Cents& c2);
    //{
    //    return Cents(c1.m_cnets + c2.m_cnets);
    //}

    //friend 키워드 지우면 맴버 함수로 만들어야 함 (this 사용)
    //맴버 함수에서만 산술 연산자 오버로딩이 가능한 연산자 : =, [], (), ->
    Cents operator + (const Cents& c1)
    {
        return Cents(this->m_cnets + c1.m_cnets);
    }
};

//산술 연산자 오버로딩(firend로 함수 선언해서 m_cent에 직접 접근 가능)
//Cents operator + (const Cents& c1, const Cents& c2)
//{
//    return Cents(c1.m_cnets + c2.m_cnets);
//}

void add(const Cents& c1, const Cents& c2, Cents &c_out)
{
    c_out.getCents() = c1.getCents() + c2.getCents();
}

Cents add(const Cents& c1, const Cents& c2)
{
    return Cents(c1.getCents() + c2.getCents());
}


int main()
{
    Cents cents1(6);
    Cents cents2(8);

    Cents sum;
    //add(cents1, cents2, sum);
    //cout << sum.getCents() << endl;

    //cout << add(cents1, cents2).getCents() << endl;

    cout << (cents1 + cents2 + Cents(6) + Cents(10) + Cents(100)).getCents() << endl;
    
    //산술 연산자 오버로딩 불가능
    // ?:연산자, ::연산자, sizeof연산자, .연산자, .* 연산자
    // ^ 연산자는 연산자 우선순위가 낮기 때문에 오버로딩 권장 X

    return 0;
}
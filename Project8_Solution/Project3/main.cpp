#include <iostream>

using namespace std;


class Fraction 
{
private:
    int m_numerator;
    int m_denominator;

public:
    //생성자가 하나도 없을 때 default 생성자가 자동으로 추가됨
    //생성자가 있으면 default 생성자는 생성되지 않음
    //Fraction(){} 
    
    Fraction(const int& num_in = 1, const int& den_in = 1)
    {
        m_numerator = num_in;
        m_denominator = den_in;

        cout << "Fraction() constructor" << endl;
    }
    void print()
    {
        cout << m_numerator << " / " << m_denominator << endl;
    }
};

int main()
{
    //생성자의 파라미터가 한개도 없을때는 ()를 빼줘야함
    Fraction frac;
    frac.print();

    //생성자없이 인스턴스 생성하는 방법1
    //Fraction one_thirds;
    
    //생성자없이 인스턴스 생성하는 방법2
    //Fraction one_thirds = Fraction{ 1, 3 };
    
    //생성자없이 인스턴스 생성하는 방법3
    //클래스 맴버가 public인 경우 생성자 없이 초기화 가능
    //private인 경우 생성자 없이 초기화 불가능, 타입변환 허용안함
    //Fraction one_thirds{ 1.0, 3 };
    
    //생성자없이 인스턴스 생성하는 방법4
    //클래스 맴버가 public, private인 경우 생성자 없이 초기화 가능
    //타입변환 허용
    Fraction one_thirds(1.0, 3);
    one_thirds.print();

    return 0;
}
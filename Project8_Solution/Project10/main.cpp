#include <iostream>

using namespace std;

class Calc
{
private:
    int m_value;

public:
    Calc(int init_value)
        :m_value(init_value)
    {}

    //인스턴스를 클래스 타입의 참조변수로 리턴하면
    //함수의 리턴값이 같은 인스턴스를 가리키므로 함수를 연속적으로 호출 가능
    Calc& add(int value) 
    {
        m_value += value;
        return *this;
    }
    Calc& sub(int value) 
    {
        m_value -= value;
        return *this;

    }
    Calc& mult(int value) 
    {
        m_value *= value;
        return *this;
    }

    void print()
    {
        cout << m_value << endl;
    }
};

int main()
{
    Calc cal(10);
    //cal.add(10);
    //cal.sub(1);
    //cal.mult(2);
    //cal.print();


    //Calc& temp1 = cal.add(10);
    //Calc& temp2 = temp1.sub(1);
    //Calc& temp3 = temp2.mult(2);
    //temp3.print();
    

    //member function chaining 기법 : 위의 코드를 아래처럼 생략 가능
    cal.add(10).sub(1).mult(2).print();


    return 0;
}
#include <iostream>

using namespace std;


class Base
{
public:
    Base() {}
    
    //출력 연산자는 오버라이딩이 불가능하므로 리턴값을
    //다른 함수에게 전달하고 그함수를 virtual 시키면 오버라이딩 가능
    friend std::ostream& operator << (std::ostream& out, const Base& b)
    {
        return b.print(out);
    }

    virtual std::ostream& print(std::ostream& out) const
    {
        out << "Base";
        return out;
    }
};

class Derived : public Base
{
public:
    Derived() {}

    virtual std::ostream& print(std::ostream& out) const override
    {
        out << "Derived";
        return out;
    }
};

int main()
{
    Base b;
    cout << b << endl;

    Derived d;
    cout << d << endl;

    Base& bref = d;
    cout << bref << endl;

    return 0;
}
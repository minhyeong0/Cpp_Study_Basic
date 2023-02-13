#include <iostream>

using namespace std;

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents = 0) { m_cents = cents; }
    int getCents() const { return m_cents; }
    int& getCents() { return m_cents; }

    //비교연산자 오버로딩
    friend bool operator == (const Cents& c1, const Cents& c2)
    {
        return (c1.m_cents == c2.m_cents) ? true : false;
    }

    friend std::ostream& operator << (std::ostream& out, const Cents &cents)
    {
        out << cents.m_cents;
        return out;
    }
};

int main()
{
    Cents cents1(6);
    Cents cents2(6);

    if (cents1 == cents2)
        cout << "Equal" << endl;

    return 0;
}
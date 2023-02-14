#include <iostream>

using namespace std;

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents = 0)
    {
        m_cents = cents;
    }

    int getCents() { return m_cents; }
    void setCents(int cents) { m_cents = cents; }

    //형변환 오버로딩
    //반환 타입이 없는 이유는 int로 형변환 하는 것은 결국 int를 리턴한다는 의미이므로 
    //리턴값 안 적음
    operator int()
    {
        cout << "cast here" << endl;
        return m_cents;
    }
};

void printInt(const int& value)
{
    cout << value << endl;
}

class Dollar
{
private:
    int m_dollars = 0;

public:
    Dollar(const int& input) : m_dollars(input) {}
    
    //형변환 오버로딩
    operator Cents()
    {
        return Cents(m_dollars * 100);
    }
};

int main()
{
    //Cents cents(7);
    //
    //int value = (int)cents;
    //value = int(cents);
    //value = static_cast<int>(cents);
    //printInt(cents);


    Dollar dol(2);
    Cents cents = dol;
    printInt(cents);

    return 0;
}
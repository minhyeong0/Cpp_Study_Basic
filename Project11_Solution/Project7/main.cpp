#include <iostream>

using namespace std;

class Base
{
protected:
    int m_i;

public:
    Base(int value)
        :m_i(value)
    {}

    void print()
    {
        cout << "I'm base" << endl;
    }

    friend std::ostream& operator << (std::ostream& out, const Base& b)
    {
        out << "This is base output";
        return out;
    }
};

class Derived : public Base
{
private:
    double m_d;

public:
    Derived(int value)
        :Base(value)
    {}

    void print()
    {
        Base::print(); //부모 클래스의 print()
        cout << "I'm derived" << endl;
    }

    friend std::ostream& operator << (std::ostream& out, const Derived& d)
    {
        cout << static_cast<Base>(d) << endl;
        out << "This is derived output";
        return out;
    }

    
};

int main()
{
    Base base(5);
    base.print();

    Derived derived(7);
    derived.print();

    cout << base << endl;
    cout << derived << endl;

    return 0;
}
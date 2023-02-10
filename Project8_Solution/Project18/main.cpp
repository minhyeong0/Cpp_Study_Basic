#include <iostream>

using namespace std;

class A
{
public:
    int m_value;
    A(const int& input)
        :m_value(input)
    {
        cout << "Constractor" << endl;
    }

    ~A()
    {
        cout << "Destractor" << endl;
    }
    void printDouble()
    {
        cout << m_value * 2 << endl;
    }
};

int main()
{
    A a(1);
    a.printDouble();
    a.printDouble();
    
    //A(1).printDouble();
    //A(1).printDouble();

    return 0;
}
#include <iostream>

using namespace std;

template <class T>
class A
{
private:
    T m_value;

public:
    A(const T& input)
        :m_value(input)
    {}

    template <typename TT>
    void doSomething(const TT& input)
    {
        cout << typeid(T).name() << " " << typeid(TT).name() << endl;
        cout << (TT)m_value << endl;
    }

    void print()
    {
        cout << m_value << endl;
    }
};

int main()
{
    A<char> a_char('A');
    a_char.print();
    //a_char.doSomething<int>(int());
    
    //파라미터로 구분할 수 있는 경우에는 지네릭 필요없음
    a_char.doSomething(int());

    return 0;
}
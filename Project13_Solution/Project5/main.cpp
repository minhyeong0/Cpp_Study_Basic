#include <iostream>
#include <array>
#include "Storage8.h"

using namespace std;

template <typename T>
class A
{
public:
    A(const T& input)
    {}

    void doSomething()
    {
        cout << typeid(T).name() << endl;
    }

    void test()
    {}
};

//클래스 템플릿 특수화
template <>
class A<char>
{
public:
    A(const char& input)
    {}

    void doSomething()
    {
        cout << "Char type specialization" << endl;
    }
};

int main()
{
    //A<int> a_int(1);
    //A<double> a_double(3.14);
    //A<char> a_char('a');

    //a_int.doSomething();
    //a_double.doSomething();
    //a_char.doSomething();

    //a_int.test();
    //a_double.test();
    ////char 타입으로 템플릿 특수화 된 클래스에는 test() 함수가 없으므로 에러
    ////a_char.test(); 


    Storage8<int> intStorage;

    for (int count = 0; count < 8; ++count)
        intStorage.set(count, count);

    for (int count = 0; count < 8; ++count)
        cout << intStorage.get(count) << endl;

    cout << "Sizeof Storage8<int> " << sizeof(Storage8<int>) << endl;

    Storage8<bool> boolStorage;
    for (int count = 0; count < 8; ++count)
        boolStorage.set(count, (count % 4 == 0) ? 0 : 1);

    for (int count = 0; count < 8; ++count)
        cout << boolalpha << boolStorage.get(count) << endl;

    cout << "Sizeof Storage8<bool> " << sizeof(Storage8<bool>) << endl;

    return 0;
}
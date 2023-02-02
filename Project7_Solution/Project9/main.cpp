#include <iostream>
#include <tuple>

using namespace std;

struct S
{
    int a, b, c, d;
};

S getStruct()
{
    S my_s{ 1, 2, 3, 4 };

    return my_s;
}

std::tuple<int, double> getTuple()
{
    int a = 10;
    double d = 3.14;
    return std::make_tuple(a, d);
}

int main()
{
    //S my_s = getStruct();
    
    //C++ 14 standard
    //std::tuple<int, double> my_tp = getTuple();
    //cout << std::get<0>(my_tp) << endl; //a
    //cout << std::get<1>(my_tp) << endl; //d

    //C++ 17 standard
    auto [a, d] = getTuple();
    cout << a << endl;
    cout << d << endl;

    return 0;
}
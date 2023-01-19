#include <iostream>

auto add(int x, int y) -> int //auto의 리턴타입을 -> 타입명으로 명시할 수 있음
{
    return x + y;
}

auto add(double x, double y) -> double //auto의 리턴타입을 -> 타입명으로 명시할 수 있음
{
    return x + y;
}

int main()
{
    using namespace std;

    //auto : 컴파일러가 타입을 자동으로 할당함

    auto a = 123;
    auto d = 123.0;
    auto c = 1 + 2.0;
    auto res = add(1, 2);

    return 0;
}
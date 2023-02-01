#include <iostream>

using namespace std;

//프로토 타입
int foo(int x, int y);

int foo(int x, int y)
{
    return x + y;
}

int main()
{
    int x = 1, y = 2;
    foo(6, 7);
    foo(x, y + 1);

    return 0;
}
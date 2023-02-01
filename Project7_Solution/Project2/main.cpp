#include <iostream>

using namespace std;

void doSomething(int y)
{
    cout << "In func " << y << " " << &y << endl;
}

int main()
{
    doSomething(5);

    int x = 6;

    cout << "In main " << x << " " << &x << endl;

    //값의 의한 전달 : x에 들어있는 6이 전달 됨
    doSomething(x);
    doSomething(x + 1);

    return 0;
}
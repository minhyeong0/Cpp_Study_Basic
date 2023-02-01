#include <iostream>

using namespace std;


void doSomething(const int& x)
{
    cout << x << endl;
    cout << &x << endl;
}

int main()
{
    //int& ref_x = 3 + 4;
    const int& ref_x = 3 + 4; //const로 선언된 참조변수타입은 리터럴 사용가능

    int a = 1;
    doSomething(a);
    doSomething(123);

    return 0;
}
#include <iostream>

using namespace std;

int value = 123;

int main()
{
    cout << value << endl;

    int value = 1;
    
    //전역스코프 연산자 : ::붙이면 전역변수에 접근 할 수 있음
    cout << ::value << endl;
    cout << value << endl;


    return 0;
}
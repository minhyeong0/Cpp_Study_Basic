#include <iostream>

using namespace std;

//참조변수(&)를 사용하면 변수의 주소 그대로 넘기고
//사용하지 않으면 값만 복사해서 저장한다
void doSomething(int& n)
{
    n = 10;
    cout << "In doSomething() " << n << " " << (intptr_t)&n << endl;
}

int main()
{
    int n = 5;

    cout << "In main() " << n << " " << (intptr_t)&n << endl;
    
    doSomething(n);

    cout << "In main() " << n << " " << (intptr_t)&n << endl;
    return 0;
}
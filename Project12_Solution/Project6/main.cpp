#include <iostream>

using namespace std;


int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int main()
{
    int x, y;
    cin >> x >> y;

    int op;
    cout << "0 : add, 1 : subtract, 2 : multiply" << endl;
    cin >> op;

    //static binding : 모든 변수명, 함수명이 컴파일 타임에 정의 되어 있는 것
    //int result;
    //switch (op)
    //{
    //case 0:
    //    result = add(x, y);
    //    break;
    //case 1:
    //    result = subtract(x, y);
    //    break;
    //case 2:
    //    result = multiply(x, y);
    //    break;
    //}

    //cout << result << endl;


    //dynamic binding : 변수명, 함수명이 런타임에 정의 되어 있는 것
    int (*func_ptr)(int, int) = nullptr;
    switch (op)
    {
    case 0:
        func_ptr = add;
        break;
    case 1:
        func_ptr = subtract;
        break;
    case 2:
        func_ptr = multiply;
        break;
    }

    cout << func_ptr(x, y) << endl;

    return 0;
}
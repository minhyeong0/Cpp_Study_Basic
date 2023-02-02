#include <iostream>

using namespace std;

typedef int* pint;

void foo(int* ptr)
{
    cout << &ptr << " " << ptr << " " << *ptr << endl;
}

void foo(double degrees, double *sin_out, double *cos_out)
{
    *sin_out = 1.0;
    *cos_out = 2.0;
}

void foo(const int* ptr, int* arr, int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << arr[i] << endl;
    }

    //포인터에서 대괄호[]는 de-reference(역참조)를 의미
    arr[0] = 1.0;

}

int main()
{
    //int value = 5;
    //cout << value << " " << &value << endl;
    //
    //int* ptr = &value;
    //cout << &ptr << endl;
    //
    //foo(ptr);
    //foo(&value);
    ////foo(5); //리터럴은 주소가 없으므로 불가능

    double degrees = 30;
    double sin, cos;
    
    foo(degrees, &sin, &cos);
    cout << sin << " " << cos << endl; 

    return 0;
}
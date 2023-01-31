#include <iostream>
#include <cstddef>

using namespace std;


void doSomething(double *ptr)
{
    cout << "address of pointer variable in doSomething() " << &ptr << endl;
    if (ptr != nullptr)
    {
        //do something useful
        cout << *ptr << endl;
    }
    else
    {
        //do nothing with ptr
        cout << "Null ptr, do nothing" << endl;
    }
}

int main()
{
    //c style
    //double* ptr{ 0 };
    //double* ptr{ NULL };

    double* ptr{ nullptr };

    doSomething(ptr);
    doSomething(nullptr);

    double d = 123.4;
    doSomething(&d);

    ptr = &d;
    doSomething(ptr);


    //널포인터만 사용가능
    //std::nullptr_t nptr; 

    cout << "address of pointer variable in main() " << &ptr << endl;

    return 0;
}
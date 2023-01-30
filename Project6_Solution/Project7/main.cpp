#include <iostream>
#include <typeinfo>

using namespace std;


struct Someting
{
    int a, b, c, d; //4 x 4 = 16
};

int main()
{
    //int x = 5;
    
    //cout << x << endl;
    //cout << &x << endl; //& : address-of operator
    //cout << (long long)&x << endl;

    ////* : de-reference operater
    //cout << *(&x) << endl;

    int x = 5;
    double d = 1.0;

    //typedef int* pint;
    //pint ptr_x, ptr_y; // 둘다 포인터 변수
    //int* ptr_x, ptr_y; // ptr_x만 포인터 변수

    //int* ptr_x = &x;
    //double *ptr_d = &d;

    //cout << ptr_x << endl;
    //cout << *ptr_x << endl;

    //cout << ptr_d << endl;
    //cout << *ptr_d << endl;

    //cout << typeid(ptr_x).name() << endl;
    //cout << typeid(ptr_d).name() << endl;

    //cout << sizeof(x) << endl;
    //cout << sizeof(d) << endl;
    //cout << sizeof(&x) << " " << sizeof(ptr_x) << endl;
    //cout << sizeof(&d) << " " << sizeof(ptr_d) << endl;

    //Someting ss;
    //Someting* ptr_s = &ss;

    //cout << sizeof(Someting) << endl;
    //cout << sizeof(ptr_s) << endl;


    return 0;
}
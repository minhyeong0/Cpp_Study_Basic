#include <iostream>

using namespace std;


int main()
{
    int* ptr = nullptr;
    int** ptrptr = nullptr;

    int value = 5;
    ptr = &value;
    ptrptr = &ptr;
    //&ptr : 포인터 자체 주소, ptr : value의 주소, *ptr : value의 값
    cout << &ptr << " " << ptr << " " << *ptr << endl;
    
    //&ptrptr : 이중 포인터 자체 주소, ptrptr : 포인터의 자체 주소
    //*ptrptr : value의 주소, **ptrptr : value의 값
    cout << &ptrptr << " " << ptrptr << " " << *ptrptr << " " << **ptrptr << endl;

    return 0;
}
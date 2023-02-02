#include <iostream>

using namespace std;


int* getValue(int x)
{
    int value = x * 2;
    return &value;
}

int* allocateMemory(int size)
{
    return new int[size];
}

int main()
{
    ////함수가 호출되고 스택에서 사리지는 것을 역참조하는 것은 위험함 (권장 안함)
    ////int value = *getValue(3);
    ////함수가 스택에서 사라지면 의미없는 주소가 저장되기 때문에 더 위험함 (권장 안함)
    //int* value = getValue(3);

    //cout << *value << endl;


    int* array = allocateMemory(100);


    delete[] array;

    return 0;
}
#include <iostream>


using namespace std;


struct MyStruct
{
    int array[5] = { 9, 7, 5, 3, 1 };
};

void doSomething(MyStruct *ms)
{
    cout << sizeof((*ms).array) << endl;
}

//void printArray(int *array)
void printArray(int array[])
{
    //함수 파라미터에서 배열은 포인터이므로 포인터 크기인 8이 출력됨
    //파라미터로 선언된 배열에 저장된 값은 배열의 첫번째 주소값이고
    //파라미터로 선언된 배열 변수 자체의 주소값은 배열과 관계 없는 주소값이다 
    cout << sizeof(array) << endl;
    cout << *array << endl;
    *array = 100;
}

int main()
{
    //int array[5] = { 9, 7, 5, 3, 1 };
    //
    ////cout << array[0] << " " << array[1] << endl;
    ////cout << array << endl;
    ////cout << &(array[0]) << endl;
    ////cout << *array << endl;
    ////
    ////int* ptr = array;
    ////cout << ptr << endl;
    ////cout << *ptr << endl;

    ////char name[] = "jackjack";
    ////cout << *name << endl;

    //cout << sizeof(array) << endl; //20

    //int* ptr = array;
    ////cout << sizeof(ptr) << endl; //8

    ////printArray(array);
    ////cout << array[0] << " " << *array << endl;

    ////cout << *ptr << " " << * (ptr + 1) << endl;

    MyStruct ms;
    cout << ms.array[0] << endl;
    cout << sizeof(ms.array) << endl;
    
    //배열이 구조체나 클래스에 들어 있는 경우는 포인터로 강제 변환되지 않음
    doSomething(&ms);

    return 0;
}
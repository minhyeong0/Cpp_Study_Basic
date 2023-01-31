#include <iostream>

using namespace std;


int main()
{
    ////int value = 5;
    ////
    ////int* ptr = nullptr;
    ////ptr = &value;

    //////내부적으로 참조변수(ref)가 value와 같은 변수(메모리를)사용하는 것 처럼 작동
    //////참조변수(별명) : 한 변수의 또 다른 이름
    ////int& ref = value;

    ////cout << ref << endl;

    ////ref = 10;

    ////cout << value << " " << ref << endl;
    ////cout << &value << endl;
    //////참조변수는 자기 자신이 별도의 주소를 가지고 있는 것이 아닌
    //////가리키고 있는 값의 주소를 가지고 있음
    ////cout << &ref << endl; 
    ////cout << ptr << endl;
    ////cout << &ptr << endl;


    //int x = 5;
    //// 참조변수는 반드시 초기화 되어야 함, 리터럴 사용 불가
    ////int& ref;
    ////int& ref = 10;

    //const int y = 8;
    ////참조변수에서 값을 마음대로 바꿀 수 있기 때문에 
    ////const로 선언된 변수는 참조변수 타입 앞에 const를 붙이면 사용 가능
    ////int& ref = y;
    //const int& ref = y;

    int value1 = 5;
    int value2 = 10;

    //참조변수에 재할당 가능 (앞에 const 안 붙었을 때)
    int& ref1 = value1;
    cout << ref1 << endl;

    ref1 = value2;
    cout << ref1 << endl;

    return 0;
}
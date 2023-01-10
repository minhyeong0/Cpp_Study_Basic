#include <iostream>

using namespace std;


void my_function(void)
{

}

int main()
{
    //void는 메모리를 차지하지 않기때문에 타입 선언 불가능
    //void my_void;

    int i = 123;
    float f = 123.456f;

    //데이터 타입이 다르더라도 주소를 표현하는 데이터크기는 동일함
    void* my_void;

    my_void = (void*)&i;
    my_void = (void*)&f;

    return 0;
}
#include <iostream>



int main()
{
    using namespace std;

    bool bValue = false;
    char chValue = 65;
    float fValue = 3.141952f;
    double dValue = 3.141952;
    
    //대입되는 rValue에 맞춰서 컴파일할때 타입이 자동으로 정해지 자료형
    auto aValue = 3.141592;
    auto aValue2 = 3.141592f;

    cout << sizeof(bool) << endl;
    cout << sizeof(bValue) << endl;


    //cpp 변수 초기화 방법 3가지
    int a1 = 123;  //copy initalization
    int a2(123);   //direct initalization
    int a3{ 123 }; //uniform initalization


    return 0;
}
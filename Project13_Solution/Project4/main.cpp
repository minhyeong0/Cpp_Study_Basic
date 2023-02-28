#include <iostream>
#include "Storage.h"
//#include "Storage.cpp" //컴파일러 차이로 인한 에러

using namespace std;

template <typename T>
T getMax(T x, T y)
{
    return (x > y) ? x : y;
}

//함수 템플릿 특수화
//char 타입으로 들어오면 이 함수 실행
template <>
char getMax(char x, char y)
{
    cout << "Warning : comparing chars" << endl;
    return (x > y) ? x : y;

}

int main()
{
    //typename 타입을 double로 설정
    //cout << getMax<double>(1, 2) << endl;

    //cout << getMax<int>(1, 2) << endl;
    //cout << getMax('a', 'b') << endl;

    Storage<int> nValue(5);
    Storage<double> dValue(6.7);

    nValue.print();
    dValue.print();

    return 0;
}
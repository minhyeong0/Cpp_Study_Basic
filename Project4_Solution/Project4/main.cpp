#include <iostream>
#include "MyConstants.h"

using namespace std;

//extern으로 선언된 변수는 한 곳에서만 초기화 해야 함
extern int a = 456;

//정적 전역변수 : 다른 cpp파일에서 접근 불가능
//static int g_a = 1;

//forward declaration (전방 선언)
/*extern*/ void doSomething(); //extern이 생략 되어 있음

int main()
{
    doSomething();
    cout << "In main.cpp file " << Constants::pi << " " << &Constants::pi << endl;
    return 0;
}
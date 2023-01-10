#include <iostream>


void doSomething()
{
using namespace std;

#ifdef LIKE_APPLE
    //LIKE_APPLE 메그로가 정의 되어 있으면 실행
    cout << "Apple" << endl;
#else
    //LIKE_APPLE 메그로가 정의 되어 있지 않으면 실행
    cout << "Orange" << endl;
#endif
}
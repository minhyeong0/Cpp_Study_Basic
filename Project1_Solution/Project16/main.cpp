#include <iostream>

using namespace std;

#define LIKE_APPLE //메크로의 효과 범위는 정의가 되어있는 파일 안이므로 Orange가 출력됨

void doSomething();

int main()
{
    doSomething();

    return 0;
}
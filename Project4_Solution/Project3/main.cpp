#include <iostream>

using namespace std;

//전역변수
//int a = 1;

void dosomething()
{
    //지역변수
    //매번 스택프레임에 올라가서 호출될때마다 초기화함
    //int a = 1; 
     
    //초기화(메모리 할당)가 한번되고 이 영역 안에서 변수가 쓰일 때 같은 메모리를 사용한다
    //정적 지역변수임
    static int a = 1;
    
    ++a;
    cout << a << endl;
}

int main()
{
    int a = 10;

    dosomething();
    dosomething();
    dosomething();
    dosomething();

    return 0;
}
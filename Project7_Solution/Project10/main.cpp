#include <iostream>

using namespace std;

//inline : 인라인 함수는 호출될 때 일반적인 함수의 호출 과정을 거치지 않고,
//함수의 모든 코드를 호출된 자리에 바로 삽입하는 방식의 함수
inline int min(int x, int y)
{
    return x < y ? x : y;
}

int main()
{
    cout << min(6, 5) << endl;
    cout << min(3, 2) << endl;
    

    return 0;
}
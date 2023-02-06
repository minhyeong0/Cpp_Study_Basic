#include <iostream>
#include <cassert>
#include <array>

using namespace std;

void printValue(const std::array<int, 5>& my_array, const int& ix)
{
    assert(0 <= ix);
    assert(ix <= my_array.size() - 1);

    cout << my_array[ix] << endl;
}

int main()
{
    //int number = 5;

    ////assert() : 런타임에 에러검출해줌, 디버깅 모드에서 작동, 릴리즈모드에서는 작동 안함
    //assert(number == 5);


    std::array<int, 5> my_array{ 1, 2, 3, 4, 5 };
    
    //printValue(my_array, 100);


    const int x = 10;
    
    //static_assert() : 컴파일 타임에 결정된 값에 대해 에러검출 해줌
    //두번째 인자에 문구를 남길 수 있음
    //static_assert(x == 5, "should be 5");

    return 0;
}
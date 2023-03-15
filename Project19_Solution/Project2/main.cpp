#include <iostream>
#include <tuple>

using namespace std;

//함수 리턴값 여러개 받기
//tuple<int, int> my_func()
//{
//    return tuple<int, int, int>(123, 456, 789);
//}


//C++ 17
auto my_func()
{
    return tuple(123, 456, 789);
}

int main()
{
    //auto result = my_func();
    //cout << get<0>(result) << " " << get<1>(result) << " " << get<2>(result) << endl;
        
    auto [a, b, c] = my_func();
    cout << a << " " << b << " " << c << endl;


    return 0;
}
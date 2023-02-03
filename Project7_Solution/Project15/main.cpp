#include <iostream>
#include <array>
#include <functional>

using namespace std;

bool isEven(const int& number)
{
    if (number % 2 == 0) return true;
    else return false;
}

bool isOdd(const int& number)
{
    if (number % 2 != 0) return true;
    else return false;
}

//함수포인터 별칭1 : 리턴타입(*별칭)(파라미터)
typedef bool (*check_fcn_t)(const int&);

//함수포인터 별칭2 : 리턴타입(*)(파라미터)
using check_fcn_t = bool (*)(const int&);

//void printNumbers(const array<int, 10>& my_array, check_fcn_t check_fcn = isEven)
void printNumbers(const array<int, 10>& my_array, function<bool(const int&)> check_fcn = isEven)
//void printNumbers(const array<int, 10>& my_array, bool (*check_fcn)(const int&) = isEven)
{
    for (auto element : my_array)
    {
        if (check_fcn(element) == true) cout << element;
    }
    cout << endl;
}

int main()
{
    std::array<int, 10> my_array = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    //함수도 배열처럼 & 안붙여도 주소값을 리턴함
    printNumbers(my_array);
    printNumbers(my_array, isEven);
    printNumbers(my_array, isOdd);

    //C11 
    std::function<bool(const int&)> fncptr = isEven;
    printNumbers(my_array, fncptr);

    fncptr = isOdd;
    printNumbers(my_array, fncptr);

    return 0;
}
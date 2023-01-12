#include <iostream>
#include "MY_CONSTANTS.h"

using namespace std;

void printNumber(const int my_number)
{
    int n = my_number;
    cout << n << endl;
}

int main()
{
    //printNumber(123);
    //const double gravity{ 9.8 };

    ////gravity = 1.2; //상수는 재할당 불가능

    
    //constexpr int my_const(123); //컴파일 상수

    //int number;
    //cin >> number;
    //const int special_number(number); //런타임 상수
    

    //int num_item = 123;
    //const int price_per_item = 30;
    //int price = num_item * price_per_item;

    double radis;
    cin >> radis;
    double circumference = 2 * radis * constants::pi;
    cout << circumference << endl;

    return 0;
}
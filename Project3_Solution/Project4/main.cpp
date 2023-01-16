#include <iostream>

int getPrice(bool onSale)
{
    if (onSale) return 10;
    else return 100;
}

int main()
{
    using namespace std;

    //float a;
    //cout << sizeof(float) << endl;
    //cout << sizeof a << endl; //변수는 괄호 생략가능 


    //int x = 3;
    //int y = 10;
    //
    ////콤마 연산자 : 앞의 값과 뒤의값을 계산한뒤 뒤에값을 대입
    //int z = (++x, ++y);
    ////++x;
    ////++y;
    ////z = y; 

    //cout << x << " " << y << " " << z << endl;


    //int a = 1, b = 10;
    //int z;

    ////콤마 연산자는 대입연산자보다 우선순위가 낮기때문에 괄호로 묶어줘야 함
    //z = (++a, a + b++);
    //cout << z << endl;


    ////조건부 연산자
    //bool onSale = true;
    //
    ////상수에서 조건에 따라 값을 초기화 할때 유용함
    //const int price = (onSale == true) ? 10 : 100;
    ////const int price = getPrice(true);

    ////if (onSale) price = 10;
    ////else price = 100;

    //cout << price << endl;
    

    int x = 5;
    cout << ((x % 2 == 0) ? "even" : "odd") << endl;
    return 0;
}
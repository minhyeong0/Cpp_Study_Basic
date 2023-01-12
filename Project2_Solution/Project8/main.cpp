#include <iostream>



int main()
{
    using namespace std;

    int b = 0b1010'1111'0001; //2진수, 컴파일러가 '를 무시함
    int o = 015; //8진수
    int x = 0xF; //16진수
    
    cout << b << endl;
    cout << o << endl;
    cout << x << endl;

    return 0;
}
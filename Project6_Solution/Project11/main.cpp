#include <iostream>

using namespace std;

const char* getName()
{
    return "Jackjack";
}

int main()
{
    //char name[] = "Jack Jack";
    
    //const char* name = "Jack Jack";
    //const char* name2 = "Jack Jack2";
    //cout << (uintptr_t)name << endl;
    //cout << (uintptr_t)name2 << endl;

    //int int_arr[5] = { 1, 2, 3, 4, 5 };
    //char char_arr[] = "Hello World";
    //const char* name = "Jack Jack";

    //cout << int_arr << endl;
    //cout << char_arr << endl; //컴파일러가 문자열은 주소가 아니라 문자열을 출력하도록 설정함
    //cout << name << endl;

    char c = 'Q';
    cout << &c << endl; //문자열로 인식해서 쓰레기 값 출력

    return 0;
}
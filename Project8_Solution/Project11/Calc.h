#pragma once
#include <iostream>

//헤더파일에서 using namespace std 사용권장 안함
class Calc
{
private:
    int m_value;

public:
    Calc(int init_value);
    //인스턴스를 클래스 타입의 참조변수로 리턴하면
    //함수의 리턴값이 같은 인스턴스를 가리키므로 함수를 연속적으로 호출 가능
    Calc& add(int value);
    Calc& sub(int value);
    Calc& mult(int value);
    void print();
};


#include <iostream>

using namespace std;

class Second
{
public:
    Second()
    {
        cout << "Class Second constructor()" << endl;
    }
};

class First
{
    Second sec;
public:
    First()
    {
        cout << "Class First constructor()" << endl;
    }
};


int main()
{
    //클래스안에 다른 클래스 인스턴스를 정의하면
    //정의한 인스턴스 생성자가 먼저 생성되고 난 다음 자신의 인스턴스가 생성된다.
    First fir;


    return 0;
}
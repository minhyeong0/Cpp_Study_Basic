#include <iostream>
#include <cmath> //sin(), cos()

using namespace std;

//참조에 의한 전달
void addOne(int& y)
{
    cout << y << " " << &y << endl;
    y = y + 1;
}

//값 두개 리턴하고 싶을 때 참조변수를 이용함
void getCinCos(const double& degrees, double& sin_out, double& cos_out)
{
    static const double pi = 3.141952 / 180.0;
    const double radians = degrees * pi;
    sin_out = std::sin(radians);
    cos_out = std::cos(radians);
}

//const 쓰면 리터럴 사용가능
void foo(int& x)
{
    cout << x << endl;
}

int main()
{
    //int x = 5;
    //cout << x << " " << &x << endl;
    //
    //addOne(x); //변수 자체를 넘기기 때문에 값이 변경됨
    //cout << x << " " << &x << endl;
    

    //double sin(0.0);
    //double cos(0.0);

    //getCinCos(30.0, sin, cos);
    //cout << sin << " " << cos << endl;


    //foo(6); //리터럴은 주소가 없어서 에러


    return 0;
}
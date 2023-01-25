#include <iostream>
#include <typeinfo>
#include <iomanip>


int main()
{
    using namespace std;

    //numberic conversion
    float f = 3.14;
    int i = f;

    //소수점 자리수 12자리 출력
    cout << std::setprecision(12) << i << endl;
    
    cout << 5u - 10u << endl;

    //명시적 형변환 방법 3가지
    //1. int i = int(4.0);
    //2. int i = (int)4.0;
    //3. int i = static_cast<int>(4.0);

    //자료형 타입 알려줌
    //cout << typeid(a).name() << endl;


    return 0;
}
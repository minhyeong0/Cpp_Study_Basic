#include <iostream>
//#include <cstdint> //iostream include 할때는 안적어도 됨


int main()
{
    using namespace std;

    //여러 컴파일러에 호환되는 int 타입
    std::int16_t i(5); //2byte
    std::int8_t myint = 65; //1byte, char

    cout << myint << endl;

    std::int_fast8_t fi(5); //1byte 중에 가장 빠른 int
    std::int_least64_t fl(5); //8byte를 갖는 int




    return 0;
}
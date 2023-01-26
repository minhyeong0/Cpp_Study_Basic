#include <iostream>

using namespace std;

struct Employee // 2 + (2) + 4 + 8 = 16 bytes (패딩)
{
    short id;    //2bytes
    int age;     //4bytes
    double wage; //8bytes

};

int main()
{
    Employee emp1;
    cout << sizeof(Employee) << endl; //16byte, 패딩이 일어남(short 2byte를 추가해서)

    return 0;
}
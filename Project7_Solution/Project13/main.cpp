#include <iostream>
#include <string>

using namespace std;

void print(int x) {}
void print(int x, int y = 20) {}

int main()
{
    //defualt parameter 때문에 함수를 못찾아서 에러 발생
    //print(10); 

    return 0;
}
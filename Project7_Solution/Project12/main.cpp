#include <iostream>

using namespace std;

//프로토타입 사용시 default parameter는 둘 중 한곳에만 명시해야 함
void print(int x = 10, int y = 20, int z = 30);

//default parameter : 파라미터 기본값
//default parameter를 쓸 때 맨 뒤 파라미터는 꼭 default parameter여야 한다
void print(int x, int y, int z)
{
    cout << x << " " << y << " " << z << endl;
}

int main()
{
    print();
    print(100);
    print(100, 200);
    print(100, 200, 300);

    return 0;
}
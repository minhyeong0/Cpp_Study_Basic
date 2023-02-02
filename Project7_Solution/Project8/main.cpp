#include <iostream>
#include <array>


using namespace std;

int& getValue(int x)
{
    int value = x * 2;
    return value;
}

//my_array 처럼 메모리가 사라지지 않는 경우에는 사용해도 됨
int& get(std::array<int, 100>& my_array, int ix) 
{
    return my_array[ix];
}

int main()
{
    //함수가 호출나고 난뒤 주소의 값을 가지고 있으므로 위험함
    //int& value = getValue(5);

    //cout << value << endl;
    //cout << value << endl;

    
    std::array<int, 100> my_array; 
    my_array[30] = 10;

    //my_array[30]와 같다
    get(my_array, 30) *= 10;
    cout << my_array[30] << endl;

    return 0;
}
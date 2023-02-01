#include <iostream>
#include <array>
#include <algorithm>


using namespace std;

//배열의 크기가 큰 경우 복사할 때 오래걸림 -> & 참조변수 타입 쓰면 해결 가능
void printLength(const array<int, 5>& my_arr)
{
    cout << my_arr.size() << endl;

}

int main()
{
    array<int, 5> my_arr = { 1, 21, 3, 40, 5 };
    //my_arr = { 0, 1, 2, 3, 4 };
    //my_arr = { 0, 1, 2, };

    //cout << my_arr[0] << endl;
    //cout << my_arr.at(0) << endl;
    
    //cout << my_arr.size() << endl;
    //printLength(my_arr);

    //for-each 가능
    for (auto& element : my_arr)
        cout << element << " ";
    cout << endl;

    //오름차순 정렬
    //std::sort(my_arr.begin(), my_arr.end());
    
    //내림차순정렬
    std::sort(my_arr.rbegin(), my_arr.rend());
    
    for (auto& element : my_arr)
        cout << element << " ";
    cout << endl;

    return 0;
}
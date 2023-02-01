#include <iostream>
//#include <array>
#include <vector>


using namespace std;


int main()
{
    //크기 지정 안해도 됨  
    //std::vector<int> array;
    //
    //std::vector<int> array2 = { 1, 2, 3, 4, 5 };
    //cout << array2.size() << endl;
    
    int* my_arr = new int[5];

    vector<int> arr = { 1, 2, 3, 4, 5 };

    //배열 크기 재지정
    arr.resize(10);

    for (auto& itr : arr)
        cout << itr << " ";
    cout << endl;

    cout << arr[0] << endl;
    cout << arr.at(0) << endl;

    //vector는 delete 안써도 됨
    //delete[] my_arr;
    return 0;
}
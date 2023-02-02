#include <iostream>
#include <vector>

using namespace std;

//참조변수로 배열 받는 방법 타입 : (&배열이름)[배열크기]
void printElement(int(&arr)[4])
{

}

void printElement(vector<int>& arr)
{

}

int main()
{
    //int arr[]{ 1, 2, 3, 4 };
    //printElement(arr);
    
    vector<int> arr{ 1, 2, 3, 4 };

    return 0;
}
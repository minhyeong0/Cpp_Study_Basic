#include <iostream>

using namespace std;

//배열 함수에 그대로 넘기는 방법 : 배열타입 (&배열)[배열크기]
void printElements(const int (&arr)[5])
{
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

struct Something
{
    int v1;
    float v2;
};

struct Other
{
    Something st;
};

int main()
{
    //const int length = 5;
    //int arr[length] = { 1, 2, 3, 4, 5 };
    //printElements(arr);

    //Other ot;
    //int& v1 = ot.st.v1;
    //v1 = 1;

    int value = 5;
    int* const ptr = &value;

    int& ref = value;
             
    *ptr = 10; //동일
    ref = 10; //동일

    return 0;
}
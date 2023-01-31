#include <iostream>

using namespace std;


int main()
{
    int fixedArray[] = { 1, 2, 3, 4, 5 };

    //동적할당 배열은 배열크기를 넣어야 함
    int* array = new int[3] { 1, 2, 3 };
    
    delete[] array;
    return 0;
}
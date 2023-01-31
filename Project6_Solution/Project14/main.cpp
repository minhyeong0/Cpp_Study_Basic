#include <iostream>

using namespace std;


int main()
{
    int length;
    cin >> length;

    //int array[length];

    //동적할당 배열 생성
    //int *array = new int[length];

    //동적할당 배열 0으로 초기화
    //int *array = new int[length]();
    //int *array = new int[length]{};
    
    //동적 할당 배열 초기화
    //초기화 한 인덱스 길이가 동적으로 할당 받은 배열 길이보다 길면 메모리 침범 에러 발생
    int *array = new int[length]{11, 22, 33, 44, 55, 66};

    array[0] = 1;
    array[1] = 2;
    
    for (int i = 0; i < length; ++i)
    {
        cout << (uintptr_t) & array[i] << endl;
        cout << array[i] << endl;
    }
    
    delete[] array; //동적 할당 배열 메모리 반납
    
    return 0;
}
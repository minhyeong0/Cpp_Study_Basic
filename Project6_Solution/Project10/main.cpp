#include <iostream>

using namespace std;


int main()
{
    //short value = 7;
    //short* ptr = &value;

    //cout << uintptr_t(ptr - 1) << endl;
    //cout << uintptr_t(ptr) << endl;
    //cout << uintptr_t(ptr + 1) << endl;
    //cout << uintptr_t(ptr + 2) << endl;

    //long long array[] = {9, 7, 5, 3, 1};
    //long long* ptr = array;

    //for (int i = 0; i < 5; ++i)
    //{
    //    //cout << array[i] << " " << (uintptr_t) & array[i] << endl;
    //    cout << *(ptr + i) << " " << (uintptr_t)(ptr + i) << endl;
    //}

    char name[] = "Jack jack";
    const int n_name = sizeof(name) / sizeof(name[0]);

    char* ptr = name;

    for (int i = 0; i < n_name; i++)
    {
        //cout << *(name + i); //배열도 포인터이므로 포인터 연산 가능
        cout << *(ptr + i);
    }

    return 0;
}
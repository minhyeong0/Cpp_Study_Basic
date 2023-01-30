#include <iostream>

using namespace std;

void printArray(const int array[], const int length)
{
    for (int index = 0; index < length; index++)
        cout << array[index] << " ";
    cout << endl;
}

int main()
{
    const int length = 5;

    int array[length] = { 3, 5, 2, 1, 4 };
    printArray(array, length);

    for (int i = 0; i < length - 1; i++)
    {
        int idx = i;
        for (int j = i + 1; j < length; j++)
            if (array[j] < array[idx]) idx = j;
        
        std::swap(array[i], array[idx]);
        //int temp = array[i];
        //array[i] = array[idx];
        //array[idx] = temp;
    }
    printArray(array, length);

    return 0;
}
#include <iostream>

int pow(int base, int exponent)
{
    int result = 1;
    for (int count = 0; count < exponent; ++count) result *= base;
    return result;
}

int main()
{
    using namespace std;
    
    //int count = 0;
    ////for (; count < 10; ++count)
    //for (;;++count)
    //{
    //    cout << count << endl;
    //}
    //cout << count << endl;

    //cout << pow(2, 4) << endl;

    //for (int count = 9; count >= 0; count -= 2)
    //{
    //    cout << count << endl;
    //}
    
    //int i = 0, j = 0;
    //for (; (i + j) < 10; ++i, j += 2)
    //{
    //    cout << i << " " << j << endl;
    //}
    //cout << i << " " << j << endl;

    //for (int j = 0; j < 9; ++j)
    //{
    //    for (int i = 0; i < 9; i++)
    //    {
    //        cout << i << " " << j << endl;
    //    }
    //}
    

    for (unsigned int i = 9; i >= 0; i--)
        cout << i << endl; //언더플로우 발생해서 무한루프

    return 0;
}
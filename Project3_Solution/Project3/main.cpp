#include <iostream>

using namespace std;

int add(int a, int b)
{
    return a + b;
}

int main()
{
    //int x = 1;
    //int v = add(x, ++x); //do not use
    //cout << v << endl;


    int x = 1;
    x = x++;
    cout << x << endl; //do not use

    return 0;
}
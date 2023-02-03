#include <iostream>

using namespace std;

void countDown(int count)
{
    cout << count << endl;
    if(count > 0)
        return countDown(count - 1);
}

int sumTo(int sumto)
{
    if (sumto <= 0)
        return 0;
    else if (sumto <= 1)
        return 1;
    else
    {
        const int sum_minus_one = sumTo(sumto - 1);
        return sumto + sum_minus_one;
    }
}

int fibonacci(int n)
{
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else if (n == 2) return 2;
    else return fibonacci(n - 2) + fibonacci(n - 1);
}


int main()
{
    //countDown(2);
    //cout << sumTo(5) << endl;
    
    //0 1 2 3 5 8 13 21 34 55 89
    for(int i=0; i<=10; i++)
        cout << fibonacci(i) << " ";
    cout << endl;


    return 0;
}
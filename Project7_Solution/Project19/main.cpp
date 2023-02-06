#include <iostream>
#include <string>


using namespace std;


int main()
{
    //semantic errors
    //int x;
    //cin >> x;
    //if (x >= 5)
    //    cout << "x is greater than 5" << endl;


    //violated assumption
    string hello = "Hello, my name is Jack jack";

    cout << "input from 0 to " << hello.size() - 1 << endl;

    while(true)
    {
        int ix;
        cin >> ix;

        if (0 <= ix && ix <= hello.size() - 1)
        {
            cout << hello[ix] << endl;
            break;
        }
        else
            cout << "Please try again" << endl;
    }
    return 0;
}
#include <iostream>
#include <cmath>



int main()
{
    using namespace std;
    
    //오차발생
    double d1(100 - 99.99); //0.001 
    double d2(10 - 9.99);   //0.001

    cout << d1 << endl;
    cout << d2 << endl;

    const double epsilon = 1e-10;
    if (std::abs(d1 - d2) < epsilon)
        cout << "Approximately equal" << endl;
    else
        cout << "Not equal" << endl;

    cout << std::abs(d1 - d2) << endl;


    //if (d1 == d2)
    //    cout << "equal" << endl;
    //else
    //{
    //    cout << "Not equal" << endl;
    //    if (d1 > d2)
    //        cout << "d1 > d2" << endl;
    //    else
    //        cout << "d1 < d2" << endl;
    //}

    return 0;
}
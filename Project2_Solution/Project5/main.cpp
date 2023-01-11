#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

int main()
{
    using namespace std;

    
    //double d(0.1);
    //cout << d << endl;
    //cout << std::setprecision(17);
    //cout << d << endl;

    //double d1(1.0);
    //double d2(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);

    //cout << std::setprecision(17);
    //cout << d1 << endl;
    //cout << d2 << endl;


    double zero = 0.0;
    double posinf = 5.0 / zero;
    double neginf = -5.0 / zero;
    double nan = zero / zero;

    cout << posinf << " " << std::isinf(posinf) << endl;
    cout << neginf << " " << std::isnan(neginf) << endl;
    cout << nan << " " << std::isnan(nan) << endl;
    cout << 1.0 << " " << std::isnan(1.0) << endl;


    //cout << 3.14 << endl;
    //cout << 31.4e-1 << endl; //31.4 * 0.1
    //cout << 31.4e-2 << endl; //31.4 * 0.01
    //cout << 31.4e1 << endl; //31.4 * 10
    //cout << 31.4e2 << endl; //31.4 * 100
    
    




    return 0;
}
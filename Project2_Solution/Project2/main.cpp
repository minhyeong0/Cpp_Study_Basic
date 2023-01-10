#include <iostream>
#include <cmath>
#include <limits>

int main()
{
    using namespace std;

    short s = 1; //2byte = 2 * 8bits = 16bits
    

    //cout << std::pow(2, sizeof(short) * 8 - 1) - 1 << endl;
    //cout << std::numeric_limits <short>::max() << endl;
    //cout << std::numeric_limits <short>::min() << endl;
    //cout << std::numeric_limits <short>::lowest() << endl;

    s = std::numeric_limits <short>::min();
    cout << "min() " << s << endl;

    s--;
    cout << s << endl;


    unsigned int i = -1;
    cout << i << endl;

    //정수끼리의 연산은 정수로 저장함
    cout << 22 / 4 << endl;


    return 0;
}
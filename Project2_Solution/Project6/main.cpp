#include <iostream>

using namespace std;


bool isEqual(int a, int b)
{
    bool result = (a == b); //a랑 b랑 같으면 true를 반환, 아니면 false 반환
    return result;
}

int main()
{
    //bool b1 = true;
    //bool b2(false);
    //bool b3{ true };
    //b3 = false;

    //cout << std::noboolalpha;
    //cout << (true || true) << endl;
    //cout << (true || false) << endl;
    //cout << (false || true) << endl;
    //cout << (false || false) << endl;

    //if (3 > 1)
    //{
    //    cout << "this is true" << endl;
    //    cout << "true second line" << endl;
    //}
    //else
    //{
    //    cout << "this is false" << endl;
    //}
    //
    //cout << std::boolalpha;
    //cout << isEqual(1, 1) << endl;
    //cout << isEqual(1, 2) << endl;


    if (0)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    bool b;
    cin >> b;
    cout << std::boolalpha;
    cout << "Your Input : " << b << endl;

    return 0;
}
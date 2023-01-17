#include <iostream>



int main()
{
    using namespace std;

    //bool x = true;
    //bool y = false;
    //
    //cout << (!x) << endl;     //NOT
    //cout << (x && y) << endl; //AND
    //cout << (x || y) << endl; //OR

    //bool hit = true;
    //int health = 10;

    //if (hit == true && health < 20)
    //{
    //    cout << "die " << endl;
    //}
    //else
    //    health -= 20;

    //int x = 5;
    //int y = 7;
    //
    //if (x != y)
    //    cout << "x does not equal y" << endl;
    //else
    //    cout << "x equal y" << endl;


    //int v = 1;
    //if (v == 0 || v == 1)
    //    cout << "v is 0 or 1" << endl;


    ////short circuit evaluation
    //int x = 2;
    //int y = 2;

    //if (x == 1 && y++ == 2)
    //{
    //    //do something
    //}
    //cout << y << endl;


    //bool x = true;
    //bool y = false;

    ////드모르간 법칙
    ////!(x && y)와 !x || !y는 같다
    ////!(x || y)와 !x && !y는 같다


    //XOR : cpp에는 xor이 없음
    //false false => false
    //true false => true
    //false true => true
    //true true => false
    
    //bool x = true;
    //bool y = true;

    ////xor 대신 사용
    //cout << (x != y) << endl;
    

    bool v1 = true;
    bool v2 = false;
    bool v3 = false;
    
    //&&가 ||보다 우선순위가 높음
    bool r1 = v1 || v2 && v3;
    bool r2 = (v1 || v2) && v3;

    cout << r1 << endl;
    cout << r2 << endl;

    return 0;
}
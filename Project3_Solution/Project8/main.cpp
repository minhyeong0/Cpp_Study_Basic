#include <iostream>
#include <bitset>

using namespace std;


int main()
{
    //bool item1_flag = false;
    //bool item2_flag = false;
    //bool item3_flag = false;
    //bool item4_flag = false;

    const unsigned char opt0 = 1 << 0;
    const unsigned char opt1 = 1 << 1;
    const unsigned char opt2 = 1 << 2;
    const unsigned char opt3 = 1 << 3;

    cout << bitset<8>(opt0) << endl;
    cout << bitset<8>(opt1) << endl;
    cout << bitset<8>(opt2) << endl;
    cout << bitset<8>(opt3) << endl;


    unsigned char items_flag = 0;
    cout << "NO item  : " << bitset<8>(items_flag) << endl;
    
    //item0 on
    items_flag |= opt0;
    cout << "item0 obtained : " << bitset<8>(items_flag) << endl;

    //item3 on
    items_flag |= opt3;
    cout << "item3 obtained : " << bitset<8>(items_flag) << endl;

    //item3 lost
    items_flag &= ~opt3;
    cout << "item3 lost : " << bitset<8>(items_flag) << endl;
    
    //has item1
    if (items_flag & opt1) cout << "has item1" << endl;
    else cout << "Not has item1" << endl;

    //has item0
    if (items_flag & opt0) cout << "has item0" << endl;
    else cout << "Not has item0" << endl;

    // obtain item 2, 3
    items_flag |= (opt2 | opt3);
    cout << bitset<8>(opt2 | opt3) << endl;
    cout << "item2, 3 obtained : " << bitset<8>(items_flag) << endl;

    if ((items_flag & opt2) && !(items_flag & opt1))
    {
        items_flag ^= opt2;
        items_flag ^= opt1;
    }
    cout << bitset<8>(items_flag) << endl;


    return 0;
}
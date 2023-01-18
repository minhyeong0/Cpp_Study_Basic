#include <iostream>
#include <bitset>


int main()
{
    using namespace std;

    // << left shift
    // >> right shift
    // ~ not
    // & and
    // | or
    // ^ xor

    //unsigned int a = 3;
    //cout << std::bitset<8>(a) << endl;
    //cout << std::bitset<8>(a << 1) << " " << (a << 1) << endl;
    //cout << std::bitset<8>(a << 2) << " " << (a << 2) << endl;
    //cout << std::bitset<8>(a << 3) << " " << (a << 3) << endl;
    //cout << std::bitset<8>(a << 4) << " " << (a << 4) << endl;

    //unsigned int a = 1024;
    //cout << std::bitset<16>(a) << endl;
    //cout << std::bitset<16>(a >> 1) << " " << (a >> 1) << endl;
    //cout << std::bitset<16>(a >> 2) << " " << (a >> 2) << endl;
    //cout << std::bitset<16>(a >> 3) << " " << (a >> 3) << endl;
    //cout << std::bitset<16>(a >> 4) << " " << (a >> 4) << endl;

    
    unsigned int a = 0b1100;
    unsigned int b = 0b0110;

    cout << std::bitset<4>(a & b) << " " << (a & b) << endl;
    cout << std::bitset<4>(a | b) << " " << (a | b) << endl;
    cout << std::bitset<4>(a ^ b) << " " << (a ^ b) << endl;

    //cout << std::bitset<16>(a) << endl;
    //cout << std::bitset<16>(~a) << " " << (~a) << endl;
    

    //축약해서 사용가능
    //a = a & b;
    //a &= b;

    return 0;
}
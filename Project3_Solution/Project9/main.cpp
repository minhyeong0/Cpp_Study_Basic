#include <iostream>
#include <bitset>

using namespace std;


int main()
{
    const unsigned red_mask   = 0xFF0000;
    const unsigned green_mask = 0x00FF00;
    const unsigned blue_mask  = 0x0000FF;

    cout << std::bitset<32>(red_mask) << endl;
    cout << std::bitset<32>(green_mask) << endl;
    cout << std::bitset<32>(blue_mask) << endl;


    unsigned int pixcel_color = 0xDAA520;
    cout << std::bitset<32>(pixcel_color) << endl;
    
    unsigned char red, green, blue;
    
    red = (pixcel_color & red_mask) >> 16;
    green = (pixcel_color & green_mask) >> 8;
    blue = pixcel_color & blue_mask;
    
    cout << "red " << std::bitset<8>(red) << " " << int(red) << endl;
    cout << "green " << std::bitset<8>(green) << " " << int(green) << endl;
    cout << "blue " << std::bitset<8>(blue) << " " << int(blue) << endl;
    return 0;
}
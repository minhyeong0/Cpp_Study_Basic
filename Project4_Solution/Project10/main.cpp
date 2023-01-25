#include <iostream>



int main()
{
    using namespace std;

	enum class Color
	{
		RED,
		BLUE,
	};	
	
	enum class Fruit
	{
		BANANA,
		APPLE,
	};

	Color color1 = Color::BLUE;
	Color color2 = Color::BLUE;
	
	if (color1 == color2)
		cout << "Same color" << endl;
    return 0;
}
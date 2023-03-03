#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    //예외처리
	try
	{
		//예외를 던질때 타입을 엄격하게 구별함
		//throw - 1.0f;
		//throw - 1.0;
		//throw std::string("My Error Message");
		throw "My Error Message";
	}
	catch (int x)
	{
		cout << "Catch Integer " << x << endl;
	}
	catch (double x)
	{
		cout << "Catch Double " << x << endl;
	}
	catch (const char* error_message)
	{
		cout <<"Char * " << error_message << endl;
	}
	catch (std::string error_message)
	{
		cout << error_message << endl;
	}

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


template <typename T>
string ToString(T x)
{
	std::ostringstream osstream;
	osstream << x;
	return  osstream.str();
}

template <typename T>
bool FromString(const string& str, T& x)
{
	std::istringstream isstream(str);
	return (isstream >> x) ? true : false;
}

int main()
{
	////string my_string("my string");
	//const char* my_string = "my string";

	////string second_string(my_string, 3, 2); //my
	////string second_string(my_string, 2); //my
	//string second_string(10, 'A'); //AAAAAAAAAA

	//cout << second_string << endl;


	//vector<char> vec;
	//for (auto e : "Today is good day")
	//    vec.push_back(e);
	////string second_string(vec.begin(), vec.end());

	////처음부터 y의 까지 출력
	//string second_string(vec.begin(), find(vec.begin(), vec.end(), 'y'));
	//
	//cout << second_string << endl;


	//string my_str(std::to_string(1004)); 
	//
	//my_str += std::to_string(128); //integer to string
	//int i = std::stoi(my_str); //string to integer
	//float f = std::stof(my_str); //string to float

	//cout << my_str << endl;
	//cout << i << endl;
	//cout << f << endl;


	//ostringstream
	string my_str(ToString(3.141592));
	cout << my_str << endl;

	double d;

	//istringstream
	if (FromString(my_str, d))
		cout << d << endl;
	else
		cout << "Cannot convert string to double" << endl;

	return 0;
}
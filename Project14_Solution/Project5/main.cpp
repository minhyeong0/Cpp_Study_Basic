#include <iostream>
#include <exception>
#include <string>

using namespace std;

//std::exception 클래스 상속 받기
class CostomException : public std::exception
{
public:
	const char* what() const noexcept override
	{
		return "Costom Exception";
	}
};

int main()
{
	try
	{
		//std::string s;
		//s.resize(-1);

		//std::exception 라이브러리를 이용한 에러 날리기
		//throw std::runtime_error("Bad thing happened");
		
		throw CostomException();
	}
	catch (const std::length_error& exception)
	{
		cout << "Length_Error" << endl;
		cerr << exception.what() << endl;
	}
	catch (const std::exception& exception)
	{
		//던진 에러가 정확히 무슨 타입인지 확인
		cout << typeid(exception).name() << endl;
		cerr << exception.what() << endl;
	}
	
	return 0;
}
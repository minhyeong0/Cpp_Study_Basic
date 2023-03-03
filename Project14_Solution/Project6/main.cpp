#include <iostream>

using namespace std;


class A
{
private:
	int m_x;

public:
	A(int x) 
		: m_x(x)
	{
		if (x <= 0)
			throw 1;
	}
};

class B : public A
{
public:
	//B(int x)
	//	:A(x)
	//{}

	//생성자에서 에러처리하고 싶을 때
	B(int x)
	try :A(x)
	{
		//do initalization
	}
	catch (...)
	{
		cout << "Catch in B constructor" << endl;
		
		//생성자에서 에러를 안던져주더라도 에러를 호출한 곳에 에러를 던져줌
		//throw;
	}
};


//함수 자체 괄호 생략한뒤 try-catch문 적기 가능
//void doSomething()
//try
//{
//	throw - 1;
//}
//catch (...)
//{
//	cout << "Catch in doSometing()" << endl;
//}


int main()
{
	try
	{
		//doSomething();
		B b(0);
	}
	catch (...)
	{
		cout << "Catch in main()" << endl;
	}

    return 0;
}
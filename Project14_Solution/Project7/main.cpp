#include <iostream>
#include <memory>

using namespace std;


class A
{
public:
	~A()
	{
		//소멸자에서는 예외를 던질 수 없다
		//throw "error";
	}
};

int main()
{
	try
	{
		//A a;

		int* i = new int[1000000];
		
		//delete로 메모리 반납할 필요 없음, 자동으로 해줌
		//unique_ptr<int> up_i(i); 

		//do someting with i

		//예외처리 때문에 메모리 반납 처리가 안 될 수 있음
		throw "error";

		delete[]i;

	}
	catch (...)
	{
		cout << "Catch" << endl;
	}

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

//오버로딩 : 기능이 비슷한 함수를 매개변수 타입, 개수만 다른 함수

int add(int x, int y)
{
	return x + y;
}

double add(double x, double y)
{
	return x + y;
}

typedef int my_int;

//typedef로 선언해도 매개변수개수와 타입이 같으면 안됨
//void print(my_int x) {} 
//void print(int x) {}

//타입이 모호한 경우 에러발생
//void print(/*const*/ char* value) {}
//void print(int value){}

void print(unsigned int value){}
void print(float value){}

int main()
{
	//add(1, 2);
	//add(3.0, 4.0);

	//print(0);
	//print("a");

	//print('a'); //타입이 모호해서 에러 발생 
	print(0u); 
	print(3.14f);

	return 0;
}
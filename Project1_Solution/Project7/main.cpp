#include <iostream>

using namespace std;

void print()
{
	cout << "Hello" << endl;
}

int addTwoNumbers(int a, int b)
{
	print();
	return a + b;
}

void printHelloWorld()
{
	cout << "Hello World" << endl;
	return;
}

int main()
{
	int sum = addTwoNumbers(1, 2);
	printHelloWorld();

	return 0;
}

#include <iostream>
#include "MyConstants.h"

/*extern*/ void doSomething();
extern int a;

void doSomething()
{
	using namespace std;
	cout << "In test.cpp " << Constants::pi << " " << &Constants::pi << endl;
}
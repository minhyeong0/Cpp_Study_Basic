#include <iostream>
#include "Resource.h"
#include "AutoPtr.h"

using namespace std;


//RAII : resource acquisiton is initialization
void doSomething()
{
    try
    {
        //Resource* res = new Resource; //dull pointer
        AutoPtr<Resource> res(new Resource); //smart pointer

        //이 경우에 메모리 반납를 못하고 함수가 종료됨
        if (true)
        {
            return;
            throw - 1;
        }

        //delete res;
    }
    catch (...)
    {

    }

    return;
}

int main()
{
    //doSomething();

    {
        //int i
        AutoPtr<Resource> res1(new Resource); //int* res1(&i)
        AutoPtr<Resource> res2; //int* res2 = nullptr

        //auto_ptr 한계
        //doSomething(res1) 함수를 호출한다고 가정할 때
        //함수가 종료될 때 메모리를 반납함

        cout << std::boolalpha;
        cout << res1.m_ptr << endl;
        cout << res2.m_ptr << endl;

        //move semantics
        res2 = res1; //res1값을 res2에 복사
        
        cout << res1.m_ptr << endl;
        cout << res2.m_ptr << endl;
        
        //소멸자 2번 호출해서 런타임 에러 발생
    }

    return 0;
}
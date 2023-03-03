#include <iostream>

using namespace std;

//해당 타입 예외를 던질 수 있는 가능성이 있다는 throw (타입명)
void last() throw (int)
{
    cout << "last" << endl;
    cout << "Throws exception" << endl;

    //int 에러 발생 : catch문 찾음
    throw - 1;

    //에러 발생한 이후 코드 실행 안되고 함수 종료
    cout << "End last" << endl;
}

void third()
{
    cout << "Third" << endl;

    last();
    //함수가 종료되도 에러 발생한 이후 코드 실행 안됨
    cout << "End Third" << endl;
}

void second()
{
    cout << "Second" << endl;
    try
    {
        third();
        //함수가 종료되고 catch문을 찾았지만 double 타입에 대한 에러 처리
        //catch문이여서 아래에 있는 코드 실행 안되고 함수 종료
    }
    catch (double)
    {
        cerr << "Second caught int exception" << endl;
    }

    cout << "End second" << endl;
}

void first()
{
    cout << "first" << endl;
    try
    {
        second();
        //함수가 종료되고 예외처리하기 위해 catch문을 찾음
        //int 타입의 에러처리 하는 catch문을 발견하면 해당 catch문을 실행하고
        //이후의 코드를 실행한 뒤 함수 종료
    }
    catch (int)
    {
        cerr << "first caught int exception" << endl;
    }

    cout << "End first" << endl;
}

int main()
{
    cout << "Start" << endl;

    try
    {
        first();
    }
    catch (int)
    {
        cerr << "main caught int exception" << endl;
    }
    catch (...) //모든 에러 다 받기
    {
        cerr << "main caught ellipses exception" << endl;
    }

    cout << "End main" << endl;

    return 0;
}
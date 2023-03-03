#include <iostream>

using namespace std;

//예외 클래스
class Exception
{
public:
    void report()
    {
        cerr << "Exception report" << endl;
    }
};

class ArrayException : public Exception
{
public:
    void report()
    {
        cerr << "Array report" << endl;
    }
};

class MyArray
{
private:
    int m_data[5];

public:
    int& operator [] (const int& index)
    {
        //if (index < 0 || index >= index) throw - 1;
        //if (index < 0 || index >= index) throw Exception();
        if (index < 0 || index >= index) throw ArrayException();
        return m_data[index];
    }
};

void doSomething()
{
    MyArray my_array;

    try
    {
        my_array[100];
    }
    catch (const int& x)
    {
        cerr << "Exception " << x << endl;
    }
    //catch (ArrayException& e)
    //{
    //    cout << "doSomething() ";
    //    e.report();

    //    //에러 다시 던지기
    //    throw e;
    //}
    catch (Exception& e)
    {
        cout << "doSomething() ";
        e.report();

        //Exception타입으로 에러를 던지면 Exception 타입에서 예외처리함
        //throw e; 

        //에러를 그냥 던지면 원래의 예외타입으로 예외처리 함
        throw;
    }
}

int main()
{
    try
    {
        doSomething();
    }
    catch (ArrayException& e)
    {
        cout << "main() ";
        e.report();
    }
    catch (Exception& e)
    {
        cout << "main() ";
        e.report();
    }

    return 0;
}
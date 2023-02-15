#include <iostream>
#include <cassert>

using namespace std;

class MyString
{
//private:
public:
    char* m_data = nullptr;
    int m_length = 0;

public:
    MyString(const char* source = "")
    {
        assert(source);
        m_length = std::strlen(source) + 1; // +1 : 널포인터 추가
        m_data = new char[m_length];

        for (int i = 0; i < m_length; ++i)
            m_data[i] = source[i];
        
        m_data[m_length - 1] = '\0';
    }

    ~MyString()
    {
        delete[] m_data;
    }

    char* getString() { return m_data; }
    int getLength() { return m_length; }


};

int main()
{
    MyString hello("Hello");
    cout << (int*)hello.m_data << endl;
    cout << hello.getString() << endl;

    {
        //hello의 인스턴스를 얕은 복사
        MyString copy = hello;
        cout << (int*)copy.m_data << endl;
        cout << copy.getString() << endl;
    }

    //hello 인스턴스와 copy 인스턴스가 같은 메모리 주소를 사용하고 있었는데
    //copy 인스턴스가 사라지면서 소멸자를 호출해 delete를 수행해서 런타임 에러 발생
    cout << hello.getString() << endl;

    return 0;
}
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
    
    //복사 생성자 만들기 귀찮을 때 복사생성자 허용안함 처리하기
    //MyString(const MyString& source) = delete;

    //복사 생성자
    MyString(const MyString& source)
    {
        cout << "Copy constructor" << endl;

        m_length = source.m_length;

        if (source.m_data != nullptr)
        {
            m_data = new char[m_length];

            for (int i = 0; i < m_length; i++)
                m_data[i] = source.m_data[i];
        }
        else
            m_data = nullptr;
    }

    //대입 연산자 오버로딩
    MyString& operator = (const MyString& source)
    {
        //얕은 복사
        //this->m_data = source.m_data;
        //this->m_length = source.m_length;

        cout << "Assignment operator" << endl;
        
        //자기 인스턴스를 자신에게 대입할때는 자신을 리턴하게 설정
        if (this == &source)
            return *this;
        
        //동적할당 된 메모리가 된 메모리가 있을 수 있으므로 반납
        delete[] m_data;

        //깊은 복사
        m_length = source.m_length;

        if (source.m_data != nullptr)
        {
            m_data = new char[m_length];

            for (int i = 0; i < m_length; i++)
                m_data[i] = source.m_data[i];
        }
        else
            m_data = nullptr;

        return *this;
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
    //MyString hello("Hello");
    //cout << (int*)hello.m_data << endl;
    //cout << hello.getString() << endl;

    //{
    //    //hello의 인스턴스를 깊은 복사
    //    MyString copy = hello;
    //    cout << (int*)copy.m_data << endl;
    //    cout << copy.getString() << endl;
    //}

    //cout << (int*)hello.m_data << endl;
    //cout << hello.getString() << endl;


    MyString hello("Hello");
    
    //Copy constructor
    //MyString str1 = hello; 
    MyString str1(hello); 
    
    MyString str2; 
    //Assignment operator
    str2 = hello;

    return 0;
}
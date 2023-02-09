#include <iostream>
#include <string>

using namespace std;

class Something
{
public:
    string m_value = "default";

    //const reference 리턴
    const string& getValue() const 
    { 
        cout << "const version" << endl;
        return m_value; 
    }

    //non-const reference 리턴
    string& getValue() 
    {
        cout << "non-const version" << endl;
        return m_value;
    }
};


int main()
{
    Something something;
    something.getValue() = 10; //함수의 리턴값이 non-const referece 값변경 가능

    const Something something2;
    something2.getValue() /*= 10*/; //함수의 리턴값이 const referece 이므로  값변경 불가능

    return 0;
}
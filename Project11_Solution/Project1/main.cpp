#include <iostream>

using namespace std;

class Mother
{

private: //모든 접근 허용 안함
//public: //모든 접근 허용
//protected: //자식 접근 허용
    int m_i;

public:
    Mother()
        :m_i(0)
    {}

    Mother(const int& i_in)
        :m_i(i_in)
    {
        cout << "Mother constructor" << endl;
    }

    void setValue(const int& i_in)
    {
        m_i = i_in;
    }

    int getValue()
    {
        return m_i;
    }
};
//부모 클래스 상속받는 법
//클래스 클래스 이름 : 접근 지정자 부모 클래스이름
class Child : public Mother //derived class
{
private:
    double m_d;

public:
    Child(const int& i_in, const double& d_in)
        //부모 생성자를 이용해서 상속받은 값 초기화하기
        :Mother(i_in), m_d(d_in)
    {
        //Mother::setValue(i_in);
        //m_d = d_in;
    }

    void setValue(const int& i_in, const double& d_in)
    {
        //m_i = i_in;
        Mother::setValue(i_in); 
        m_d = d_in;
    }

    void setValue(const double& d_in)
    {
        m_d = d_in;
    }

    double getValue()
    {
        return m_d;
    }
};


int main()
{
    //Mother mother;
    //mother.setValue(1024);
    //cout << mother.getValue() << endl;

    
    Child child(1024, 128);
    //child.Mother::setValue(1024);
    //child.setValue(128);
    cout << child.Mother::getValue() << endl;
    cout << child.getValue() << endl;

    return 0;
}
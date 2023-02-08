#include <iostream>

using namespace std;

class Simple
{
private:
    int m_id;

public:
    Simple(int id)
    {
        //모든 클래스 맴버에 접근할 때 this-> 가 생략되어 있다
        /*this->*/setID(id);
        /*this->*/m_id = 1; 

        //this : 각각의 인스턴스는 주소를 가지고 있고 각각의 인스턴스의
        //주소를 알고 싶을 때 사용를 함
        cout << this << endl;
    }

    void setID(int id) { m_id = id; }
    int getID() { return m_id; }
};

int main()
{
    Simple s1(1), s2(2);
    s1.setID(2);
    s2.setID(4);

    cout << &s1 << " " << &s2 << endl;

    //인스턴스 생성될때마다 메모리에 함수를 만드는 것이 아니라
    //함수에 인자에 인스턴스를 넘겨줘서 함수를 사용한다. (개념적으로)
    //Simple::setID(&s1, 1);  == s1.setID(1) //작동은 안함

    return 0;
}
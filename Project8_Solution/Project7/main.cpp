#include <iostream>

using namespace std;

class Simple
{
private:
    int m_id;

public:
    //생성자
    Simple(const int& id_in)
        :m_id(id_in)
    {
        cout << "Contructor " << m_id << endl;
    }

    //소멸자 : 인스턴스가 메모리에서 사라질때 자동으로 호출됨
    //소멸자는 파라미터가 없음
    ~Simple()
    {
        cout << "Destructor " << m_id << endl;
    }
};

int main()
{
    //Simple s1(0);
    
    //클래스 동적생성, 동적할당으로 만들어진 경우에는 영역을 벗어나도 메모리에서 자동으로
    //없어지지 않기 때문에 delete를 안쓰면 소멸자 호출 안됨 (권장 안함)
    Simple* s1 = new Simple(0);
    Simple s2(1);


    delete s1;
    return 0;
}
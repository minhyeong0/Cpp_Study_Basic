#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Base
{
public:
    int m_i = 0;

    virtual void print()
    {
        cout << "I'm Base" << endl;
    }
};

class Derived : public Base
{
public:
    int m_j = 1;

    virtual void print() override
    {
        cout << "I'm Derived" << endl;
    }
};

//void doSomething(Base& b)
//{
//    b.print();
//}

void doSomething(Base b)
{
    b.print();
}

int main()
{
    Derived d;
    
    //참조나 포인터를 사용하면 다형성 구현가능
    //b1이 d의 주소를 참조하므로 Base로부터 상속 받은 값에 대해 접근 가능 
    Base& b1 = d;
    b1.print();

    //b2가 d의 주소를 참조하지 않으므로 (값이 복사됨)
    //Base로부터 상속 받기 불가능, 객체 잘림 발생
    Base b2 = d;
    b2.print();

    //doSomething(d);

    //std::vector<Base> my_vec;
    //my_vec.push_back(b);
    //my_vec.push_back(d); //객체 잘림 발생

    //for (auto& ele : my_vec)
    //    ele.print();


    //std::vector<Base*> my_vec;
    //my_vec.push_back(&b1);
    //my_vec.push_back(&d);

    //for (auto& ele : my_vec)
    //    ele->print();


    //vector<클래스&>가 불가능하기 때문에 Base의 참조변수를 담고 싶을 때 사용
    std::vector<std::reference_wrapper<Base>> my_vec;
    my_vec.push_back(b1);
    my_vec.push_back(d);

    for (auto& ele : my_vec)
        ele.get().print();

    return 0;
}
#include <iostream>
#include <memory>
#include <string>

using namespace std;


class Person
{
    std::string m_name;
    //소유권이 순환되서 종료가 안됨, 메모리 반납 안해줌
    //std::shared_ptr<Person> m_partner;
    
    std::weak_ptr<Person> m_partner;

public:
    Person(const std::string &name)
        :m_name(name)
    {
        cout << m_name << " created" << endl;
    }

    ~Person()
    {
        cout << m_name << " destoryed" << endl;
    }

    friend bool partnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2)
    {
        if (!p1 || !p2) return false;

        p1->m_partner = p2;
        p2->m_partner = p1;

        cout << p1->m_name << "is partnered with " << p2->m_name << endl;
        return true;
    }

    //weak_ptr<>()를 사용할때 lock() 해줘야 함
    const std::shared_ptr<Person> getPartner() const
    {
        //lock()를 호출하면 shared pointer로 리턴해줌
        return m_partner.lock();
    }

    const std::string& getName() const
    {
        return m_name;
    }
};

int main()
{
    auto lucy = std::make_shared<Person>("Lucy");
    auto ricky = std::make_shared<Person>("Ricky");

    partnerUp(lucy, ricky);

    cout << lucy->getPartner()->getName() << endl;

    return 0;
}
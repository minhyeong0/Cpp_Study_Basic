#include <iostream>
#include <string>

using namespace std;

//추상 기본 클래스 : 순수 가상 함수를 맴버로 가지고 있는 클래스
class Animal
{
protected:
    string m_name;

public:
    Animal(std::string name)
        :m_name(name)
    {}

    string getName() { return m_name; }

    //순수 가상 함수 : 순수가상함수는 자식 클래스에서 반드시 함수를 구현해야한다.
    //함수 body가 없고, virtual 함수명() = 0 형식임
    virtual void speak() const = 0;
};

//순수 가상 함수도 별도로 body를 정의 할 수 있음, 함수 호출 불가능 (쓸모 없음)
//void Animal::speak() const
//{
//    cout << m_name << " ??? " << endl;
//}

class Cat : public Animal
{
public:
    Cat(string name)
        :Animal(name)
    {}

    void speak() const override
    {
        cout << m_name << " Meow " << endl;
    }
};

class Dog : public Animal
{
public:
    Dog(string name)
        :Animal(name)
    {}

    void speak() const override
    {
        cout << m_name << " Woof " << endl;
    }
};

class Cow : public Animal
{
public:
    Cow(string name)
        :Animal(name)
    {}

    //추상 클래스를 상속 받았으면 순수 가상 함수 반드시 구현 해야함
    void speak() const override
    {
        cout << m_name << " Moooo " << endl;
    }
};


int main()
{
    //추상 클래스 : 순수 가상 함수가 하나라도 들어 있는 함수는
    //인스턴스 생성 불가
    //Animal ani("Hi");
    //ani.speak();

    //추상 클래스가 들어있는 클래스를 상속 받았으면 반드시
    //순수 가상 함수를 구현해야함
    Cow cow("Hello");
    cow.speak();

    return 0;
}
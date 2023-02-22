#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
    string m_name;

public:
    Animal(std::string name)
        :m_name(name)
    {}

public:
    string getName() { return m_name; }
    
    //virtual 키워드 붙이면 : 자식 클래스를 부모 클래스 타입으로 제한했을 때 
    //부모 클래스 함수가 호출되는 것이 아닌 자식 클래스 함수가 호출됨
    virtual void speak() const 
    {
        cout << m_name << " ??? " << endl;
    }
};

class Cat : public Animal
{
public:
    Cat(string name)
        :Animal(name)
    {}

    void speak() const
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

    void speak() const
    {
        cout << m_name << " Woof " << endl;
    }
};

int main()
{
    //Animal animal("my animal");
    //Cat cat("my cat");
    //Dog dog("my dog");
    //
    //animal.speak();
    //cat.speak();
    //dog.speak();
    //
    //Animal* ptr_animal1 = &cat;
    //Animal* ptr_animal2 = &dog;

    ////다형성 : 자식 클래스를 부모 클래스로 타입 제한하면 부모 클래스 함수를 사용함
    //ptr_animal1->speak();
    //ptr_animal2->speak();


    Cat cats[] = { Cat("cat1"), Cat("cat2"), Cat("cat3"), Cat("cat4"),  Cat("cat5") };
    Dog dogs[] = { Dog("dog1"), Dog("dog2") };

    for (int i = 0; i < 5; ++i)
        cats[i].speak();
    for (int i = 0; i < 2; ++i)
        dogs[i].speak();

    Animal* my_animals[] = { &cats[0], &cats[1], &cats[2], &cats[3], &cats[4],
                             &dogs[0], &dogs[1] };

    for (int i = 0; i < 7; ++i)
        my_animals[i]->speak();

    return 0;
}
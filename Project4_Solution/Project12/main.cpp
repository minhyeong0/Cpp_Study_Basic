#include <iostream>
#include <string>

using namespace std;

struct Person
{
    double height = 3.0; //기본값
    float weight = 200;
    int age = 100;
    string name = "Mr. Incredible";

    void print()
    {
        cout << height << " " << weight << " " << age << " " << name << endl;
    }
};

struct Family
{
    //구조체 안에 구조체 사용 가능
    Person me, mom, dad;
};

Person getMe()
{
    Person me{ 2.0, 100.0, 20, "Jack Jack" };
    return me;
}


int main()
{
    Person me{ 2.0, 100.0, 20, "Jack Jack" }; //구조체 초기화 방법1
    me.print();

    Person me2(me); //구조체 초기화 방법2
    me2.print();

    Person me3; //구조체 초기화 방법3
    me3 = me; //대입연산자는 구조체를 구조체로, 클래스를 클래스로 복사한다는 보장 없음
    me3.print();

    Person me_from_func = getMe();
    me_from_func.print();

    Person me4; //구조체에 값을 할당해두면 기본값이 할당됨
    me4.print();

    //구조체에 값을 할당하면 기본값을 덮어 씀
    Person me5{ 2.0, 100.0, 20, "Jack Jack" };
    me5.print();

    return 0;
}
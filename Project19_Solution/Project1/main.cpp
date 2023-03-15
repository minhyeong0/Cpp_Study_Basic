#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Object
{
public:
    void hello(const string& s)
    {
        cout << "Hello " << s << endl;
    }
};

void goodbye(const string& s)
{
    cout << "Goodbye " << s << endl;
}

int main()
{
    //람다 함수: 소개  파라미터      리턴타입         바디
    auto func = [](const int& i) -> void {cout << "Hello" << endl; };
    func(123);

    [](const int& i) -> void {cout << "Hello" << endl; }(1234);


    {
        string name = "Jackjack";
        
        //대괄호 안에 =를 사용하면 값을 복사해서 함수에서 사용함
        [=]() {cout << name << endl; }();
        //대괄호 안에 &를 사용하면 밖에 있는 것들을 주소로 가져옴
        [&]() {cout << name << endl; }();
        //[&name]() {cout << name << endl; }();
        //[this]() {cout << name << endl; }(); //클래스 맴버에 접근하고 싶을 때
    }

    vector<int> v;
    v.push_back(1);
    v.push_back(2);

    //auto func2 = [](int val) -> void {cout << val << endl; };
    //리턴 타입이 void인 경우 -> void 생략가능
    auto func2 = [](int val) {cout << val << endl; };
    for_each(v.begin(), v.end(), func2);
    for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });

    cout << []() -> int {return 1; }() << endl;
    
    //         리턴타입/파라미터 타입
    std::function<void(int)> func3 = func2;
    func3(123);

    //func3의 파라미터를 456으로 묶음
    std::function<void()> func4 = std::bind(func3, 456);
    func4();

    {
        Object instance;
        //               클래스 함수 포인터, 인스턴스 포인터, 파라미터 개수
        auto f = std::bind(&Object::hello, &instance, std::placeholders::_1);

        f(string("World"));

        //                 함수 포인터,    파라미터 개수
        auto f2 = std::bind(&goodbye, std::placeholders::_1);
        f2(string("World"));
    }

    return 0;
}
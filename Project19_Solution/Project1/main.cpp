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
    //���� �Լ�: �Ұ�  �Ķ����      ����Ÿ��         �ٵ�
    auto func = [](const int& i) -> void {cout << "Hello" << endl; };
    func(123);

    [](const int& i) -> void {cout << "Hello" << endl; }(1234);


    {
        string name = "Jackjack";
        
        //���ȣ �ȿ� =�� ����ϸ� ���� �����ؼ� �Լ����� �����
        [=]() {cout << name << endl; }();
        //���ȣ �ȿ� &�� ����ϸ� �ۿ� �ִ� �͵��� �ּҷ� ������
        [&]() {cout << name << endl; }();
        //[&name]() {cout << name << endl; }();
        //[this]() {cout << name << endl; }(); //Ŭ���� �ɹ��� �����ϰ� ���� ��
    }

    vector<int> v;
    v.push_back(1);
    v.push_back(2);

    //auto func2 = [](int val) -> void {cout << val << endl; };
    //���� Ÿ���� void�� ��� -> void ��������
    auto func2 = [](int val) {cout << val << endl; };
    for_each(v.begin(), v.end(), func2);
    for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });

    cout << []() -> int {return 1; }() << endl;
    
    //         ����Ÿ��/�Ķ���� Ÿ��
    std::function<void(int)> func3 = func2;
    func3(123);

    //func3�� �Ķ���͸� 456���� ����
    std::function<void()> func4 = std::bind(func3, 456);
    func4();

    {
        Object instance;
        //               Ŭ���� �Լ� ������, �ν��Ͻ� ������, �Ķ���� ����
        auto f = std::bind(&Object::hello, &instance, std::placeholders::_1);

        f(string("World"));

        //                 �Լ� ������,    �Ķ���� ����
        auto f2 = std::bind(&goodbye, std::placeholders::_1);
        f2(string("World"));
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <utility> //std::forword

using namespace std;


struct MyStruct
{};

void func(MyStruct& s)
{
    cout << "Pass by L-ref" << endl;
}

void func(MyStruct&& s)
{
    cout << "Pass by R-ref" << endl;
}

//template <typename T>
//void func_wrapper(T t) //L-value���� R-value���� ��������
//{
//    func(t);
//}

template <typename T>
void func_wrapper(T&& t) //L-value���� R-value���� ��������
{
    //std::forward�� L-value�� ���� L-value�� �����ϰ�
    //R-value�� ���� R-value�� ������
    func(std::forward<T>(t));
}


int main()
{
    MyStruct s;
    
    //func(s); //L-value
    //func(MyStruct()); //R-value

    func_wrapper(s); //L-value
    func_wrapper(MyStruct()); //R-value

    return 0;
}
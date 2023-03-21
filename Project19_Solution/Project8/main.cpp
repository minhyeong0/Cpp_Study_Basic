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
//void func_wrapper(T t) //L-value인지 R-value인지 구별못함
//{
//    func(t);
//}

template <typename T>
void func_wrapper(T&& t) //L-value인지 R-value인지 구별못함
{
    //std::forward는 L-value로 오면 L-value를 리턴하고
    //R-value로 오면 R-value로 리턴함
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
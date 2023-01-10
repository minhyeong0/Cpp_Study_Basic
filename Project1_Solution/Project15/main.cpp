#include <iostream>

namespace MySpace1
{
    //namespace 안에 namespace 정의 가능
    namespace InnerSpace
    {
        int my_function()
        {
            return 0;
        }
    }

    int doSomething(int a, int b)
    {
        return a + b;
    }
}
namespace MySpace2
{
    int doSomething(int a, int b)
    {
        return a * b;
    }
}

using namespace std;


int main()
{
    //앞에 namespace이름 생략하고 싶을때 사용
    using namespace MySpace1;
    doSomething(3, 4);

    MySpace1::InnerSpace::my_function();
    
    using namespace MySpace1::InnerSpace;
    my_function();

    //함수 이름 중복 정의하고 싶을때 namespace 사용
    //cout << MySpace1::doSomething(3, 4) << endl;
    //cout << MySpace2::doSomething(3, 4) << endl;

    return 0;
}
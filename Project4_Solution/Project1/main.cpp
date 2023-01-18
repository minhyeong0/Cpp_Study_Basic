#include <iostream>

namespace work1::work11::work111
{
    int a = 1;
    void dosomething()
    {
        a += 3;
    }
}

namespace work2
{
    int a = 1;
    void dosomething()
    {
        a += 5;
    }
}

int main()
{
    using namespace std;
    
    //범위결정 연산자 ::
    work1::work11::work111::a;
    work1::work11::work111::dosomething();
    
    work2::a;
    work2::dosomething();

    return 0;
}
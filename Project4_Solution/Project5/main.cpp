#include <iostream>


namespace a
{
    int my_var(10);
    int my_a(123);
    int count(123123);
}

namespace b
{
    int my_var(20);
}

int main()
{
    using namespace std;
    //using std::cout;
    //using std::endl;

    {
        using namespace a;
        cout << my_var << endl;
        //cout << count << endl; //std에 count가 있어서 에러 발생
    }
    {
        using namespace b;
        cout << my_var << endl;
    }

    return 0;
}
#include "Timer.h"
#include "AutoPtr.h"
#include "Resource.h"


AutoPtr<Resource> generateResource()
{
    AutoPtr<Resource> res(new Resource(10000000));
    return res;
}


int main()
{
    using namespace std;

    streambuf* orig_buf = cout.rdbuf();
    //cout.rdbuf(NULL); //disconnect cout from buffer
    
    Timer timer;

    {
        AutoPtr<Resource> main_res;

        //함수 리턴값 R-value는 받고 사라지기 때문에 굳이 값을 복사하지 않고
        //shallow copy하여 소유권을 다른곳으로 넘겨줌
        main_res = generateResource();
    }

    cout.rdbuf(orig_buf);
    timer.elapsed();

    return 0;
}
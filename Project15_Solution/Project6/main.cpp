#include "Resource.h"

using namespace std;


void doSomething(std::unique_ptr<Resource> res)
{

}

int main()
{

    //권장안함, 함수 인자에 객체 생성이 끼어 있어 오류 발생 가능성 있음
    //doSomething(std::unique_ptr<Resource>(new Resource(10000000)));
    
    //함수 파라미터로 전달할때 make_unique<>() 사용 권장
    //doSomething(std::make_unique<Resource>(10000000));

    Resource* res = new Resource(3);
    res->setAll(1);
    {
        //소유권을 여러군데에서 공유가능, 몇군데에서 공유하고 있는지 저장함
        //std::shared_ptr<Resource> ptr1(res);

        //shared_ptr 만들 때 make_shared<>() 사용 권장
        auto ptr1 = make_shared<Resource>(3);
        
        ptr1->setAll(1);
        ptr1->print();
        {
            
            //ptr1과 ptr2가 따로 따로 직접 포인터에 접근했기 때문에
            //ptr1이 ptr2가 소유권을 가지고 있는지 알 수 없음,
            //std::shared_ptr<Resource> ptr2(res); //X

            //std::shared_ptr<Resource> ptr2(ptr1);
            auto ptr2 = ptr1;

            ptr2->setAll(3);
            ptr2->print();

            cout << "Going out of the block" << endl;
        }

        ptr1->print();
        cout << "Going out of the outer block" << endl;
    }
    return 0;
}
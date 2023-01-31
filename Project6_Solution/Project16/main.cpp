#include <iostream>



int main()
{
    using namespace std;

    {
        //정리
        int value = 5;
        const int* ptr1 = &value;       //역참조 X, 재할당 O
        int* const ptr2 = &value;       //역참조 O, 재할당 X
        const int* const ptr2 = &value; //역참조 X, 재할당 X
    }
    

    {
        //읽기 (value 값 수정 불가능, value 값 주소 접근 가능)
        const int value = 5;
        const int* ptr = &value;
    
        //역참조 불가능
        //*ptr = 6; //불가능
        //value = 6; //불가능

        cout << ptr << endl;
        cout << *ptr << endl;
    }

    {
        //읽기 (value 값 수정 불가능, value 값 주소 접근 가능)
        int value = 5;
        const int* ptr = &value;

        //역참조 불가능
        //*ptr = 6; //불가능
        value = 6; //가능

        cout << ptr << endl;
        cout << *ptr << endl;
    }

    {
        int value1 = 5;
        const int* ptr = &value1;

        //const를 포인터타입 앞에 붙이면 역참조는 불가능하고
        //포인터 변수에 새로운 주소값 재할당 가능
        //*ptr = 6; //불가능
        int value2 = 6; //가능
        ptr = &value2; //가능

        cout << ptr << endl;
        cout << *ptr << endl;
    }

    {
        int value = 5;
        int* const ptr = &value;

        //const를 포인터 타입 뒤에 붙이면 역참조는 가능하고
        //포인터 변수에 새로운 주소값 재할당 불가능
        
        *ptr = 10; //가능
        
        int value2 = 8;
        //ptr = &value2; //불가능
        
        cout << ptr << endl;
        cout << *ptr << endl;
    }

    {
        int value = 5;
        const int* const ptr = &value;

        //const를 포인터 타입 앞 뒤에 둘다 붙이면 역참조도 불가능하고
        //포인터 변수에 새로운 주소값 재할당 불가능
        int value2 = 6;
        //ptr = &value2;
        //*ptr = 10;

        cout << ptr << endl;
        cout << *ptr << endl;
    }
    return 0;
}
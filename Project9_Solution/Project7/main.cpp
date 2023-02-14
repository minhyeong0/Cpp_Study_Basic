#include <iostream>
#include <cassert>

using namespace std;

class IntList
{
private:
    int m_list[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

public:
    //첨자 연산자 오버로딩 (리턴값 참조변수)
    int& operator [] (const int index)
    {
        assert(index >= 0);
        assert(index < 10);
        return m_list[index];
    }

    const int& operator [] (const int index) const
    {
        assert(index >= 0);
        assert(index < 10);
        return m_list[index];
    }

    void setItem(int index, int value)
    {
        m_list[index] = value;
    }

    int getItem(int index)
    {
        return m_list[index];
    }

    int* getList()
    {
        return m_list;
    }
};

int main()
{
    //IntList my_list;
    //my_list.setItem(3, 1);
    //cout << my_list.getItem(3) << endl;
    
    //my_list.getList()[3] = 10;
    //cout << my_list.getList()[3] << endl;

    //IntList my_list;
    //my_list[3] = 10;
    //cout << my_list[3] << endl;

    //const IntList my_list;
    ////my_list[3] = 10;
    //cout << my_list[3] << endl;

    //IntList 객체를 담는 배열
    IntList* list = new IntList;
    
    //IntList의 배열 3번째 인덱스에 접근하겠다는 의미
    //list[3] = IntList; 
    
    //첨자 연산자 오버로딩 해서 m_list에 접근한다는 의미
    //(list[0])[3] = 10;
    (*list)[3] = 10;


    return 0;
}
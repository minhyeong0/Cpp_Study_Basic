#include <vector>
#include <algorithm>
#include "AutoPtr.h"
#include "Resource.h"

using namespace std;

template <class T>
void MySwap(T& a, T& b)
{
    //T tmp = a;
    //a = b;
    //b = tmp;

    T tmp = { std::move(a) };
    a = std::move(b);
    b = std::move(tmp);
}

int main()
{
    //{
    //    AutoPtr<Resource> res1(new Resource(10000000));
    //    cout << res1.m_ptr << endl;
    //    
    //    //AutoPtr<Resource> res2 = res1;
    //    
    //    //std::move() : L-value�� R-Value�� �νĵǰ� �ٲ���
    //    AutoPtr<Resource> res2 = std::move(res1);
    //    cout << res1.m_ptr << endl;
    //    cout << res2.m_ptr << endl;
    //}

    //{
    //    AutoPtr<Resource> res1 = (new Resource(3));
    //    res1->setAll(3);

    //    AutoPtr<Resource> res2 = (new Resource(5));
    //    res2->setAll(5);

    //    res1->print();
    //    res2->print();

    //    MySwap(res1, res2);

    //    res1->print();
    //    res2->print();
    //}

    //{
    //    vector<string> v;
    //    string str = "Hello";

    //    v.push_back(str);
    //    cout << str << endl;
    //    cout << v[0] << endl;

    //    v.push_back(std::move(str));

    //    //move�� �������༭ ���ڿ��� �����
    //    cout << str << endl;
    //    cout << v[0] << " " << v[1] << endl;
    //}

    {
        std::string x{ "abc" };
        std::string y{ "de" };

        cout << "x: " << x << endl;
        cout << "y: " << y << endl;

        MySwap(x, y);

        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
    }

    return 0;
}
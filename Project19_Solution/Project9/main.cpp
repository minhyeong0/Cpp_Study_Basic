#include <iostream>
#include <vector>
#include <cstdio>
#include <utility> //std::forward

using namespace std;

class CustomVector
{
public:
    unsigned n_data = 0;
    int* ptr = nullptr;

    CustomVector(const unsigned& _n_data, const int& _init = 0)
    {
        cout << "Constructor" << endl;
        init(_n_data, _init);
    }

    CustomVector(CustomVector& l_input)
    {
        cout << "Copy constructor" << endl;
        init(l_input.n_data);

        for (unsigned i = 0; i < n_data; i++)
            ptr[i] = l_input.ptr[i];
    }

    CustomVector(CustomVector&& r_input)
    {
        cout << "Move constructor" << endl;

        n_data = r_input.n_data;
        ptr = r_input.ptr;

        r_input.n_data = 0;
        r_input.ptr = nullptr;
    }

    ~CustomVector()
    {
        delete[] ptr;
    }

    void init(const unsigned& _n_data, const int& _init = 0)
    {
        n_data = _n_data;
        ptr = new int[n_data];
        for (unsigned i = 0; i < n_data; i++)
            ptr[i] = _init;
    }
};

void doSomething(CustomVector& vec)
{
    cout << "Pass by L-reference" << endl;
    CustomVector new_vec(vec);
}

void doSomething(CustomVector&& vec)
{
    cout << "Pass by R-reference" << endl;
    CustomVector new_vec(std::move(vec));
    
    //std::move 안해주면 vec 자체가 변수이기 때문에 L-value 취급 당함
    //CustomVector new_vec(vec);
}

//template <typename T>
//void doSomethingTemplate(T vec) //L-value인지 R-value인지 구별 못함
//{
//    doSomething(vec);
//}

template <typename T>
void doSomethingTemplate(T&& vec)
{
    //L-value로 값이 들어오면 L-value로 전달하고
    //R-value로 값이 들어오면 R-value로 전달함
    doSomething(std::forward<T>(vec));
}

int main()
{
    CustomVector my_vec(10, 1024);
    
    //CustomVector temp(my_vec); //Copy constructor
    //CustomVector temp(std::move(my_vec)); //Move constructor
    //cout << my_vec.n_data << endl;

    //doSomething(my_vec);
    //doSomething(CustomVector(10, 8));
    
    doSomethingTemplate(my_vec);
    doSomethingTemplate(CustomVector(10, 8));

    return 0;
}
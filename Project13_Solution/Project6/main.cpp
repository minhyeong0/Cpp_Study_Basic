#include <iostream>

using namespace std;

template <class T, int size>
class StaticArray_BASE
{
private:
    T m_array[size];

public:
    T* getArray() { return m_array; }

    T& operator [] (int index)
    {
        return m_array[index];
    }

    void print()
    {
        for (int count = 0; count < size; ++count)
            cout << (*this)[count] << ' ';
        cout << endl;
    }
};

//상속을 이용하여 맴버함수 특수화하기
template<class T, int size>
class StaticArray : public StaticArray_BASE<T, size>
{
};

//상속을 이용하여 부분적으로 맴버 함수 특수화 하기
template<int size>
class StaticArray<char, size> : public StaticArray_BASE<char, size>
{
public:
    void print()
    {
        for (int count = 0; count < size; ++count)
            cout << (*this)[count];
        cout << endl;
    }
};

//template <typename T, int size>
//void print(StaticArray<T, size>& array)
//{
//    for (int count = 0; count < size; ++count)
//        cout << array[count] << ' ';
//    cout << endl;
//}

////템플릿을 부분적으로 특수화하기
//template <int size>
//void print(StaticArray<char, size>& array)
//{
//    for (int count = 0; count < size; ++count)
//        cout << array[count];
//    cout << endl;
//}

int main()
{
    StaticArray<int, 4> int4;
    int4[0] = 1;
    int4[1] = 2;
    int4[2] = 3;
    int4[3] = 4;
    int4.print();

    StaticArray<char, 14> char14;
    char14[0] = 'H';
    char14[1] = 'e';
    strcpy_s(char14.getArray(), 14, "Hello, World");
    //strcpy_s((char*)&char14[0], 14 * sizeof(char), "Hello, World");
    char14.print();


    return 0;
}
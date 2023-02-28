#include "MyArray.h"

template<typename T>
void MyArray<T>::print()
{
	for (int i = 0; i < m_length; i++)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}

//explicit instantiation
//템블릿 쓸 때 헤더와 cpp 파일을 분리하면 컴파일러가 타입을 알 수 없기 때문에
//어떤 타입으로 컴파일 할지 설정

//클래스 전부 explicit instantiation 
template class MyArray<char>;
template class MyArray<double>;

//각각의 함수 explicit instantiation
//template void MyArray<char>::print();
//template void MyArray<double>::print();
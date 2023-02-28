#pragma once

#include <iostream>
#include <cassert>

//자료형이 아닌 템플릿 파라미터
template <typename T, unsigned int T_SIZE>
class MyArray
{
private:
	//int m_length;
	T* m_data; //T m_data[T_SIZE];

public:
	MyArray()
	{
		m_data = new T[T_SIZE];
	}

	~MyArray()
	{
		delete[] m_data;
	}

	T& operator [] (int index)
	{
		assert(0 <= index && index < T_SIZE);
		return m_data[index];
	}

	int getLength()
	{
		return T_SIZE;
	}

	void print()
	{
		for (int i = 0; i < T_SIZE; i++)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}
};
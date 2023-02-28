#pragma once

#include <iostream>

template <class T>
class Storage
{
private:
	T m_value;

public:
	Storage(T value)
	{
		m_value = value;
	}

	~Storage()
	{}

	void print()
	{
		std::cout << m_value << std::endl;
	}
};

void Storage<double>::print()
{
	std::cout << "Double type :";
	std::cout << std::scientific << m_value << std::endl;
}
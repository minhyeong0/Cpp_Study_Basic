#pragma once
#include <string>
#include "Position2D.h"

class Monster
{
private:
	std::string m_name;
	//int m_x;
	//int m_y;
	//���� Ŭ������ �ٸ� Ŭ������ ����ϴ� ���� ���� ���� ��� ��
	Position2D m_location;

public:
	Monster(const std::string name_in, const Position2D& pos_in)
		:m_name(name_in), m_location(pos_in)
	{}

	void moveTo(const Position2D& pos_target)
	{
		m_location.set(pos_target);
		//m_x = x_target;
		//m_y = y_target;
	}

	friend std::ostream& operator << (std::ostream& out, const Monster& monster)
	{
		out << monster.m_name << " " << monster.m_location;
		return out;
	}

};
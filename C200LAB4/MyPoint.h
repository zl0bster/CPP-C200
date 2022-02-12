#pragma once
#include <iostream>
using namespace std;

#include "MyCircle.h"

class MyPoint
{
	int m_x;
	int m_y;
	friend class MyCircle;
public:
	inline MyPoint(int x=0, int y=0)
	{
		m_x = x; m_y = y;
	};

	inline bool operator==(MyPoint& p) const
	{
		return ((m_x == p.m_x) && (m_y == p.m_y));
	}

	friend ostream& operator<<(ostream& os, const MyPoint& mp);
};


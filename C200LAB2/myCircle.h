#pragma once
#include "Shape.h"

class Circle :
	public Shape
{
private:
	int m_x, m_y, m_r;
public:
	Circle();
	Circle(int x, int y, int r, eColor col = eColor::WHITE);
	Circle(const Circle& other);
};


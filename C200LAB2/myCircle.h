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
	~Circle();
	virtual void WhereAmI() const;
	virtual void PrintShape() const;
	void PrintCircle() const;
	void SetAll(int x, int y, int r);
	void GetAll(int& x, int& y, int& r) const;
	void InflateCircle(int incr);
};


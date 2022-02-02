#pragma once
#include "Shape.h"
#include "myRect1.h"

class Circle :
	public Shape
{
private:
	int m_x, m_y, m_r;
public:
	Circle();
	Circle(int x, int y, int r, eColor col = eColor::WHITE);
	Circle(const Circle& other);
	Circle(const Rect& other);
	virtual ~Circle();
	virtual void WhereAmI() const;
	virtual void PrintShape() const;
	virtual void WhereAmIVirtual() const;
	void PrintCircle() const;
	void SetAll(int x, int y, int r);
	void GetAll(int& x, int& y, int& r) const;
	void InflateCircle(int incr);
};


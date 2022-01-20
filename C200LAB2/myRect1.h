#pragma once
#include "Shape.h"

class Rect:
	public Shape
{
private:
	void NormalizeRect();
	int m_left, m_right, m_top, m_bottom;
public:
	Rect();
	Rect(int x1, int y1, int x2, int y2, eColor col = eColor::WHITE);
	Rect(const Rect& other);
	Rect(const Rect& r1, const Rect& r2);
	~Rect();
	void PrintRect() const;
	void InflateRect(int ref_left , int ref_top , int ref_right , int ref_bottom );
	void InflateRect(int ref_hor = 1, int ref_vert = 1);
	// Set figure parameters by falues
	void SetAll(int x1, int y1, int x2, int y2, eColor col = eColor::WHITE);
	void GetAll(int& x1, int& y1, int& x2, int& y2) const;
	void BindRect(const Rect& r1, const Rect& r2);
	virtual void WhereAmI() const;
};
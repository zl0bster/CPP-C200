#include "myCircle.h"
#include "Shape.h"
#include "myRect1.h"

#include <stdio.h>
#include <cmath>

Circle::Circle()
{
	m_x = 0;
	m_y = 0;
	m_r = 0;
}

Circle::Circle(int x, int y, int r, eColor col)
{
	SetAll(x, y, r);
	set_color(col);
}

Circle::Circle(const Circle& other)
{
	SetAll(other.m_x, other.m_y, other.m_r);
	set_color(other.get_color());
}

Circle::Circle(const Rect& other)
{
	other.GetMinDim(m_r);
	m_r /=  2;
	other.GetMiddlePoint(m_x, m_y);
}

Circle::~Circle()
{
	printf("destroyed circle ID %d\n", get_id());
}

void Circle::WhereAmI() const
{
	printf("It is Circle ID %d\n", get_id());
}

void Circle::PrintShape() const
{
	PrintCircle();
}

void Circle::WhereAmIVirtual() const
{
	printf("It is virtual Circle \n");
}

void Circle::PrintCircle() const
{
	printf("---\n ID %d\n", get_id());
	printf(" center X, Y  = %d, %d \n", m_x, m_y);
	printf(" radius = %d \n", m_r);
	printf(" color = %d \n", get_color());
}

void Circle::SetAll(int x, int y, int r)
{
	m_x = x;
	m_y = y;
	m_r = r;
}

void Circle::GetAll(int& x, int& y, int& r) const
{
	x = m_x;
	y = m_y;
	r = m_r;
}

void Circle::InflateCircle(int incr)
{
	m_r += incr;
}

void Circle::Inflate(int dr)
{
	InflateCircle(dr);
}

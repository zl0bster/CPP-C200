#include "myRect1.h"
#include "Shape.h"

#include <stdio.h>


Rect::Rect()
{
	this->m_top = 0;
	this->m_bottom = 0;
	this->m_left = 0;
	this->m_right = 0;
}

Rect::Rect(int x1, int y1, int x2, int y2, eColor col)
{
	SetAll(x1, y1, x2, y2);
	set_color(col);
}

Rect::Rect(const Rect& other)
{
	m_top = other.m_top;
	m_left = other.m_left;
	m_bottom = other.m_bottom;
	m_right = other.m_right;
	set_color(other.get_color());
}

Rect::Rect(const Rect& r1, const Rect& r2)
{
	BindRect(r1, r2);
}

Rect::~Rect()
{
	printf("destroyed rectangle ID %d\n", get_id());
}

void Rect::WhereAmI() const
{
	printf("It is Rect ID %d\n", get_id());
}

void Rect::PrintShape() const
{
	PrintRect();
}

void WhereAmIVirtual() //const
{
	printf("It is virtual Rect\n");
}

void Rect::PrintRect() const
{
	printf("---\n ID %d\n", get_id());
	printf(" left-top  = %d, %d \n", this->m_left, this->m_top);
	printf(" right-bot = %d, %d \n", this->m_right, this->m_bottom);
	printf(" color = %d \n", get_color());
}

void Rect::InflateRect(int ref_left, int ref_top, int ref_right, int ref_bottom)
{
	m_left -= ref_left;
	m_top -= ref_top;
	m_right += ref_right;
	m_bottom += ref_bottom;
	NormalizeRect();
}

void Rect::InflateRect(int ref_hor, int ref_vert)
{
	m_left -= ref_hor;
	m_top -= ref_vert;
	m_right += ref_hor;
	m_bottom += ref_vert;
	NormalizeRect();
}

void Rect::NormalizeRect()
{
	if (m_left > m_right)
	{
		int x1 = m_left;
		m_left = m_right;
		m_right = x1;
	}
	if (m_top < m_bottom)
	{
		int y1 = m_top;
		m_top = m_bottom;
		m_bottom = y1;
	}
}


void Rect::SetAll(int x1, int y1, int x2, int y2, eColor col)
{
	m_top = y1;
	m_bottom = y2;
	m_left = x1;
	m_right = x2;
	NormalizeRect();
	set_color(col);
}



void Rect::GetAll(int& x1, int& y1, int& x2, int& y2) const
{
	x1 = m_left;
	y1 = m_top;
	x2 = m_right;
	y2 = m_bottom;
}

void Rect::BindRect(const Rect& r1, const Rect& r2)
{
	m_left = (r1.m_left < r2.m_left) ? r1.m_left : r2.m_left;
	m_right = (r1.m_right > r2.m_right) ? r1.m_right : r2.m_right;
	m_top = (r1.m_top < r2.m_top) ? r1.m_top : r2.m_top;
	m_bottom = (r1.m_bottom > r2.m_bottom) ? r1.m_bottom : r2.m_bottom;
	set_color(r1.get_color());
}
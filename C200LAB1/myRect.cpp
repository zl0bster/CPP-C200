#include "myRect.h"

#include <stdio.h>


size_t Rect::counter =0;

Rect::Rect()
{
	this->m_top = 0;
	this->m_bottom = 0;
	this->m_left = 0;
	this->m_right = 0;
	m_id = counter++;
	printf("def created ID %d\n", m_id);
}

Rect::Rect(int x1, int y1, int x2, int y2)
{
	SetAll(x1, y1, x2, y2);
	m_id = counter++;
	printf("new created ID %d\n", m_id);
}

Rect::Rect(const Rect& other)
{
	m_top = other.m_top;
	m_left = other.m_left;
	m_bottom = other.m_bottom;
	m_right = other.m_right;
	m_id = counter++;
	printf("cpy created ID %d\n", m_id);
}

Rect::Rect(const Rect& r1, const Rect& r2)
{
	BindRect(r1, r2);
	m_id = counter++;
	printf("mrg created ID %d\n", m_id);
}

Rect::~Rect()
{
	printf("destroyed ID %d\n", m_id);
}


void Rect::PrintRect() const
{
	printf("---\n ID %d\n", m_id);
	printf(" left-top  = %d, %d \n", this->m_left, this->m_top);
	printf(" right-bot = %d, %d \n", this->m_right, this->m_bottom);
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


void Rect::SetAll(int x1, int y1, int x2, int y2)
{
	m_top = y1;
	m_bottom = y2;
	m_left = x1;
	m_right = x2;
	NormalizeRect();
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
}

Rect BoundingRect(const Rect& r1, const Rect& r2)
{
	int r1lt, r1rt, r1tp, r1bt;
	int r2lt, r2rt, r2tp, r2bt;
	r1.GetAll(r1lt, r1tp, r1rt, r1bt);
	r2.GetAll(r2lt, r2tp, r2rt, r2bt);
	int x1 = (r1lt < r2lt) ? r1lt : r2lt;
	int x2 = (r1rt > r2rt) ? r1rt : r2rt;
	int y1 = (r1tp < r2tp) ? r1tp : r2tp;
	int y2 = (r1bt > r2bt) ? r1bt : r2bt;
	Rect r3(x1, y1, x2, y2);
	return r3;
}

#include "MyPoint.h"
#include <iostream>

size_t MyPoint::counter = 0;
MyPoint::MyPoint(int x, int y)
{
	mx = x;
	my = y;
	m_id = ++counter;
	std::cout << "_point ID_" << m_id << "\t - " << mx << ", " << my << " created\n";
}

MyPoint::~MyPoint()
{
	std::cout << "__point ID_"<<m_id<< "\t - "<< mx << ", " << my << " removed\n";
}

MyPoint::MyPoint(const MyPoint& oth)
{
	mx = oth.mx;
	my = oth.my;
	m_id = ++counter;
	std::cout << "_point ID_" << m_id << "\t - "<< mx << ", " << my << " copied\n";
}

void MyPoint::GetCoords(int& x, int& y)
{
	x = mx;
	y = my;
}

void MyPoint::PrintPoint()
{
	std::cout << "point ID_" << m_id << "\t - " << mx << ", " << my << "\n";
}

MyPoint& MyPoint::operator=(const MyPoint& oth)
{
	mx = oth.mx;
	my = oth.my;
	return *this;
}

MyPoint& MyPoint::operator+=(const MyPoint& oth)
{
	mx += oth.mx;
	my += oth.my;
	return *this;
}

MyPoint& MyPoint::operator+=(int inc)
{
	mx += inc;
	my += inc;
	return *this;

}

MyPoint& operator-=(MyPoint& pt1, const MyPoint& pt2)
{
	pt1.mx -= pt2.mx;
	pt1.my -= pt2.my;
	return pt1;
}

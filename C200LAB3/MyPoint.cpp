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

MyPoint::MyPoint(MyPoint&& oth)
{
	mx = oth.mx;
	my = oth.my;
	m_id = ++counter;
	std::cout << "_point ID_" << m_id << "\t - " << mx << ", " << my << " moved\n";
	//delete &oth !!!;
}

void MyPoint::GetCoords(int& x, int& y) const
{
	x = mx;
	y = my;
}

void MyPoint::PrintPoint() const
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

MyPoint MyPoint::operator+(const MyPoint& right) const
{
	return MyPoint(mx + right.mx, my + right.my);
}

MyPoint MyPoint::operator+(int right)
{
;
	return MyPoint(mx + right, my + right);
}

//MyPoint MyPoint::operator-(MyPoint& right)
//{
//	return MyPoint(mx - right.mx, my - right.my);
//}
//
//MyPoint MyPoint::operator-(const int& right)
//{
//	return MyPoint(mx - right, my - right);
//}

const MyPoint& MyPoint::operator+() const
{
	return *this;
}

MyPoint operator-(const MyPoint& pt)
{
	return MyPoint(-pt.mx, -pt.my);
}

MyPoint operator+(const int& left, const MyPoint& right)
{
	return MyPoint(right.mx + left, right.my + left);
}

MyPoint operator-(const MyPoint& left, const MyPoint& right)
{
	return MyPoint(left.mx - right.mx, left.my - right.my);
}

MyPoint operator-(const MyPoint& left, const int& right)
{
	return MyPoint(left.mx - right, left.my - right);
}

MyPoint& operator-=(MyPoint& pt1, const MyPoint& pt2)
{
	pt1.mx -= pt2.mx;
	pt1.my -= pt2.my;
	return pt1;
}

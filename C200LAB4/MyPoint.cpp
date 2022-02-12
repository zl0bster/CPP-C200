#include "MyPoint.h"

ostream& operator<<(ostream& os, const MyPoint& mp)
{
	os << "coord: "<< mp.m_x << ", " << mp.m_x;
	return os;
}

#include <random>
#include <iostream>
using namespace std;

#include "MyCircle.h"

ostream& operator<<(ostream& os, const MyCircle& mc)
{
	os << mc.m_pt << "\tr: " << mc.m_r;
	return os;
}

void MyCircle::set_rnd()
{
	m_pt.m_x = get_rnd(200);
	m_pt.m_y = get_rnd(200);
	m_r = get_rnd();
}

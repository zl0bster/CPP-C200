#pragma once
#include <iostream>
using namespace std;

//#include"MyPoint.h"


class MyPoint
{
	friend class MyCircle;
	int m_x;
	int m_y;
public:
	inline MyPoint(int x = 0, int y = 0)
	{
		m_x = x; m_y = y;
	};

	inline bool operator==(const MyPoint& p) const
	{
		return ((m_x == p.m_x) && (m_y == p.m_y));
	}

	friend ostream& operator<<(ostream& os, const MyPoint& mp);
};

class MyCircle
{
private:
	MyPoint m_pt;
	int m_r;
public:
	inline MyCircle(int x = 0, int y = 0, int r = 1):m_pt(x,y)
	{
		m_r = r;
	};
	inline bool operator<(const MyCircle& c) const
	{
		return (m_r < c.m_r);
	};
	inline bool operator>(const MyCircle& c) const
	{
		return (m_r > c.m_r);
	};
	inline bool operator==(const MyCircle& c) const
	{
		return ((m_r == c.m_r) && (m_pt == c.m_pt));
	};
	void set_rnd();
	friend ostream& operator<<(ostream& os, const MyCircle& mc);
private:
	static inline size_t get_rnd(size_t rng = 100)
	{
		return rand() % rng;
	};
};


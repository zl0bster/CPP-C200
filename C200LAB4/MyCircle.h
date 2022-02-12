#pragma once
#include <iostream>
using namespace std;


#include"MyPoint.h"

class MyCircle
{
	MyPoint m_pt;
	int m_r;
public:
	inline MyCircle(int x = 0, int y = 0, int r = 1)
	{
		m_pt.m_x = x; m_pt.m_y = y; m_r = r;
	};
	inline bool operator<(MyCircle& c) const
	{
		return (m_r < c.m_r);
	};
	inline bool operator==(MyCircle& c) const
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


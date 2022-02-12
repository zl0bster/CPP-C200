#pragma once

#include <iostream>
using namespace std;

//#include "MyNodeBi.h"
#include "MyCircle.h"

class MyList
{
	class MyNodeBi
	{
		friend class MyList;
		MyNodeBi* pPrev;
		MyNodeBi* pNext;
		MyCircle* m_dat;
	public:
		MyNodeBi();
		MyNodeBi(MyNodeBi* prv, MyNodeBi* nxt, const MyCircle* dat);
		~MyNodeBi();
		friend ostream& operator<<(ostream& os, const MyNodeBi& mn);
	};

private:
	MyNodeBi m_head;
	MyNodeBi m_tale;
	size_t m_qty;
public:
	MyList();
	void push_head(const MyCircle* c);
	void push_tale(const MyCircle* c);
	MyCircle& pop_head();
	MyCircle& pop_tale();
	MyCircle& operator[](size_t n);
	void empty_list();
	inline size_t get_qty() const
	{
		return m_qty;
	};
	friend ostream& operator<<(ostream& os, MyList& ml);
	friend ostream& operator<<(ostream& os, const MyNodeBi& mn);
};


#pragma once

#include <iostream>
using namespace std;

//#include "MyNodeBi.h"
#include "MyCircle.h"

class MyList
{
public:
	class MyNodeBi	// to public
	{
		friend class MyList;
		MyNodeBi* pPrev;
		MyNodeBi* pNext;
		MyCircle m_dat; // внедренный
	public:
		MyNodeBi();
		MyNodeBi(MyNodeBi* prv, MyNodeBi* nxt, const MyCircle* dat);
		~MyNodeBi();
		friend ostream& operator<<(ostream& os, MyList& ml);
		friend ostream& operator<<(ostream& os, const MyNodeBi& mn);
	};

private:
	MyNodeBi m_head; // внедренный
	MyNodeBi m_tale; // внедренный
	size_t m_qty;
public:
	MyList();
	~MyList();
	MyList(const MyList& ol);
	MyList(MyList&& ol);
	MyList& operator=(const MyList& ol);
	MyList& operator=(MyList&& ol);
	void push_head(const MyCircle* c);
	void push_tale(const MyCircle* c);
	MyCircle& pop_head(); // by value
	MyCircle& pop_tale(); // by value
	MyCircle& operator[](size_t n);
	void empty_list();
	inline size_t get_qty() const
	{
		return m_qty;
	};
	friend ostream& operator<<(ostream& os, const MyList& ml);
	friend ostream& operator<<(ostream& os, const MyNodeBi& mn);
};


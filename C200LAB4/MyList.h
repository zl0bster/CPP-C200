#pragma once

#include <iostream>
using namespace std;

//#include "MyNodeBi.h"
#include "MyCircle.h"

class MyList
{
public:
	class MyNodeBi
	{
	public:
		friend class MyList;
		MyNodeBi* pPrev;
		MyNodeBi* pNext;
		MyCircle m_dat;

		MyNodeBi();
		MyNodeBi(MyNodeBi* prv, const MyCircle* dat);
		~MyNodeBi();
		MyNodeBi& operator=(const MyNodeBi& on);
		MyNodeBi& operator=(MyNodeBi&& on);
		inline bool operator<(const MyNodeBi& on) const
		{ return (m_dat < on.m_dat); };
		inline bool operator>(const MyNodeBi& on) const
		{ return (m_dat > on.m_dat); };
		friend ostream& operator<<(ostream& os, MyList& ml);
		friend ostream& operator<<(ostream& os, const MyNodeBi& mn);
	};

private:
	MyNodeBi m_head;
	MyNodeBi m_tail;
	size_t m_qty;
public:
	MyList();
	~MyList();
	MyList(const MyList& ol);
	MyList(MyList&& ol);
	MyList& operator=(const MyList& ol);
	MyList& operator=(MyList&& ol);
	void push_head(const MyCircle* c);
	void push_tail(const MyCircle* c);
	MyCircle pop_head();
	MyCircle pop_tail();
	MyCircle& operator[](size_t n);
	void empty_list();
	inline size_t get_qty() const
	{
		return m_qty;
	};
	void sort(); // TODO
	friend ostream& operator<<(ostream& os, const MyList& ml);

private:
	void remove_to_tail(MyNodeBi* first_to_remove);
};


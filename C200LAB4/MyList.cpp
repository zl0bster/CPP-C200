
#include <iostream>
using namespace std;

//#include "MyNodeBi.h"
#include "MyCircle.h"

#include "MyList.h"

MyList::MyList()
{
	m_head = new MyNodeBi;
	m_tale = new MyNodeBi;
	m_qty = 0;
	m_head.pNext = &m_tale;
	m_tale.pPrev = &m_head;
}

void MyList::push_head(const MyCircle* c)
{
	MyNodeBi* tmpN = new MyNodeBi(&m_head, m_head->pNext, c);
	m_qty++;
}

void MyList::push_tale(const MyCircle* c)
{
	MyNodeBi* tmpN = new MyNodeBi(m_tale->pPrev, &m_tale, c);
	m_qty++;
}

MyCircle& MyList::pop_head()
{
	MyCircle* tmp
}

MyCircle& MyList::pop_tale()
{
	// TODO: insert return statement here
}

MyCircle& MyList::operator[](size_t n)
{
	// TODO: insert return statement here
}

void MyList::empty_list()
{
}

ostream& operator<<(ostream& os, MyList& ml)
{
	// TODO: insert return statement here
}


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
	m_head->pNext = m_tale;
	m_tale->pPrev = m_head;
}

void MyList::push_head(const MyCircle* c)
{
	MyNodeBi* tmpN = new MyNodeBi(m_head, m_head->pNext, c);
	m_qty++;
}

void MyList::push_tale(const MyCircle* c)
{
	MyNodeBi* tmpN = new MyNodeBi(m_tale->pPrev, m_tale, c);
	m_qty++;
}

MyCircle& MyList::pop_head()
{
	MyCircle* tmp = new MyCircle();
	*tmp = *m_head->pNext->m_dat;
	delete m_head->pNext;
	m_qty--;
	return *tmp; // return by value
}

MyCircle& MyList::pop_tale()
{
	MyCircle* tmp = new MyCircle();
	*tmp = *m_tale->pPrev->m_dat;
	delete m_tale->pPrev;
	m_qty--;
	return *tmp; // return by value
}

MyCircle& MyList::operator[](size_t n)
{
	if (n >= m_qty) n %= m_qty;
	MyNodeBi* currentNode = m_head->pNext;
	while (n > 0)
	{
		currentNode = currentNode->pNext;
		n--;
	}
	return *currentNode->m_dat;
}
//
//void MyList::empty_list()
//{
//	MyNodeBi* currentNode = m_head->pNext;
//	while(m_qty>0)
//	{
//		currentNode = currentNode->pNext;
//		delete currentNode->pPrev;
//		m_qty--;
//	}
//}
void MyList::empty_list()
{
	while(Head->pNext != tale)
	{
		delete head->pNext;
	}
	m_qty = 0;
}

ostream& operator<<(ostream& os, MyList& ml)
{
	os << "List qty: " << ml.m_qty << endl;
	os << "==========================\n";
	if (ml.m_qty > 0)
	{
		MyList::MyNodeBi* currentNode = ml.m_head->pNext;
		for (int i = 0; i < ml.m_qty; i++)
		{
			os << *currentNode->m_dat;
			currentNode = currentNode->pNext;
		}
	}
	os << "==========================\n";
	return os;
}

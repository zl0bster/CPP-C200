
#include <iostream>
using namespace std;

//#include "MyNodeBi.h"
#include "MyCircle.h"
#include "MyList.h"

MyList::MyList()
{
	m_qty = 0;
	m_head.pNext = &m_tail;
	m_tail.pPrev = &m_head;
}

MyList::~MyList()
{
	empty_list();
}

MyList::MyList(const MyList& ol)
{
	m_qty = 0;
	m_head.pNext = &m_tail;
	m_tail.pPrev = &m_head;
	MyNodeBi* sorsNode = ol.m_head.pNext;
	for (int i = 0; i < ol.m_qty; i++) {
		push_tail(&sorsNode->m_dat);
		sorsNode = sorsNode->pNext;
	}
}

MyList::MyList(MyList&& ol)
{
	m_head.pNext = ol.m_head.pNext;
	m_tail.pPrev = ol.m_tail.pPrev;
	m_qty = ol.m_qty;
	ol.m_head.pNext = &ol.m_tail;
	ol.m_tail.pPrev = &ol.m_head;
	ol.m_qty = 0;
}

MyList& MyList::operator=(const MyList& ol)
{
	MyNodeBi* destNode = m_head.pNext;
	MyNodeBi* sorsNode = ol.m_head.pNext;
	if (m_qty >= ol.m_qty) {
		for (int i = 0; i < ol.m_qty; i++) {
			*destNode = *sorsNode;
			destNode = destNode->pNext;
			sorsNode = sorsNode->pNext;
		}
		if (m_qty > ol.m_qty) remove_to_tail(destNode);
	}
	else {
		for (int i = 0; i < m_qty; i++) {
			*destNode = *sorsNode;
			destNode = destNode->pNext;
			sorsNode = sorsNode->pNext;
		}
		for (int i = m_qty; i < ol.m_qty; i++) {
			push_tail(&sorsNode->m_dat);
			sorsNode = sorsNode->pNext;
		}
	}
	return *this;
}

MyList& MyList::operator=(MyList&& ol)
{
	empty_list();
	m_head.pNext = ol.m_head.pNext;
	m_tail.pPrev = ol.m_tail.pPrev;
	m_qty = ol.m_qty;
	ol.m_head.pNext = &ol.m_tail;
	ol.m_tail.pPrev = &ol.m_head;
	ol.m_qty = 0;
	return *this;
}

void MyList::push_head(const MyCircle* c)
{
	MyNodeBi* tmpN = new MyNodeBi(&m_head, c);
	m_qty++;
}

void MyList::push_tail(const MyCircle* c)
{
	MyNodeBi* tmpN = new MyNodeBi(m_tail.pPrev, c);
	m_qty++;
}

MyCircle MyList::pop_head()
{
	MyCircle tmp = m_head.pNext->m_dat;
	delete m_head.pNext;
	m_qty--;
	return tmp; // return by value
}

MyCircle MyList::pop_tail()
{
	MyCircle tmp = m_tail.pPrev->m_dat;
	delete m_tail.pPrev;
	m_qty--;
	return tmp; // return by value
}

MyCircle& MyList::operator[](size_t n)
{
	if (n >= m_qty) n %= m_qty;
	MyNodeBi* currentNode = m_head.pNext;
	while (n > 0) {
		currentNode = currentNode->pNext;
		n--;
	}
	return currentNode->m_dat;
}

void MyList::empty_list()
{
	while(m_head.pNext != &m_tail)
	{
		delete m_head.pNext;
	}
	m_qty = 0;
}

void MyList::sort() // TODO
{
}

void MyList::remove_to_tail(MyNodeBi* first_to_remove)
{
	MyNodeBi* next = first_to_remove->pNext;
	do {
		delete next->pPrev;
		next = next->pNext;
		m_qty--;
	} while (next != nullptr); //&m_tale
}

ostream& operator<<(ostream& os, const MyList& ml)
{
	os << "List qty: " << ml.m_qty << endl;
	os << "==========================\n";
	if (ml.m_qty > 0) {
		MyList::MyNodeBi* currentNode = ml.m_head.pNext;
		for (int i = 0; i < ml.m_qty; i++) {
			os << currentNode->m_dat<<endl;
			currentNode = currentNode->pNext;
		}
	}
	os << "==========================\n";
	return os;
}

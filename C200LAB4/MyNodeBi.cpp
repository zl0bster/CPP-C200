
#include <iostream>
using namespace std;

#include "MyCircle.h"
//#include "MyNodeBi.h"
#include "MyList.h"

MyList::MyNodeBi::MyNodeBi()
{
	pPrev = nullptr;
	pNext = nullptr;
	m_dat = nullptr;
}

MyList::MyNodeBi::MyNodeBi(MyNodeBi* prv, MyNodeBi* nxt, const MyCircle* dat)
{
	//TODO check for nullptr each param
	pPrev = prv;
	prv->pNext = this;
	pNext = nxt;
	nxt->pPrev = this;
	MyCircle* tmp = new MyCircle;
	*tmp = *dat;
	m_dat = tmp;
}

MyList::MyNodeBi::~MyNodeBi()
{ // add check for nullptr if head and tale
	pPrev->pNext = pNext;
	pNext->pPrev = pPrev;
	delete m_dat;
}

ostream& operator<<(ostream& os, const MyList::MyNodeBi& mn)
{
	os << "NODE: " << *mn.m_dat;
	return os;
}

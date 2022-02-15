
#include <iostream>
using namespace std;

#include "MyCircle.h"
//#include "MyNodeBi.h"
#include "MyList.h"

MyList::MyNodeBi::MyNodeBi()
{
	pPrev = nullptr;
	pNext = nullptr;
}

MyList::MyNodeBi::MyNodeBi(MyNodeBi* prv, const MyCircle* dat)
{
	//TODO check for nullptr each param
	pPrev = prv;
	pNext = prv->pNext;
	prv->pNext = this;
	pNext->pPrev = this;
	m_dat = *dat;
}

MyList::MyNodeBi::~MyNodeBi()
{
	if ((pNext != nullptr) && (pPrev != nullptr)) {
		pPrev->pNext = pNext;
		pNext->pPrev = pPrev;
	}
}

MyList::MyNodeBi& MyList::MyNodeBi::operator=(const MyNodeBi& on)
{
	m_dat = on.m_dat;
	return *this;
}

MyList::MyNodeBi& MyList::MyNodeBi::operator=(MyNodeBi&& on)
{
	m_dat = on.m_dat;
	return *this;
}

ostream& operator<<(ostream& os, const MyList::MyNodeBi& mn)
{
	os << "NODE: " << mn.m_dat;
	return os;
}

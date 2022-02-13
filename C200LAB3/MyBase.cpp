
#include <iostream>
#include <exception>

#include "MyBase.h"
//#include "MyPair.h"

MyBase::MyBase()
{
	qty = 0;
	capacity = 0;
	pBase = nullptr;
	add_capacity(1);
	std::cout << "base created\n";
}

MyBase::~MyBase()
{
	clear_base();
	delete[] pBase;
	capacity = 0;
	pBase = nullptr;
	std::cout << "base removed\n";
}

MyBase::MyBase(const MyBase& ob)
{
	qty = 0;
	capacity = 0;
	pBase = nullptr;
	if (ob.qty == 0) return;
	add_capacity(ob.qty + 1);
	for (int i = 0; i < ob.qty; i++)
	{
		pBase[i] = new MyPair(*ob.pBase[i]);
		qty++;
	}
}

MyBase::MyBase( MyBase&& ob)
{
	qty = 0;
	capacity = 0;
	pBase = nullptr;
	if (ob.qty == 0) return;
	add_capacity(ob.qty + 1);
	for (int i = 0; i < ob.qty; i++)
	{
		pBase[i] = ob.pBase[i];
		ob.pBase[i] = nullptr;
	}
	qty = ob.qty;
	ob.qty = 0;
}

MyBase& MyBase::operator=(const MyBase& ob)
{
	clear_base();
	if (ob.qty > 0)
	{
		if ((capacity-1)< ob.qty)
			add_capacity(ob.qty- capacity + 1);
		for (int i = 0; i < ob.qty; i++)
		{
			pBase[i] = new MyPair(*ob.pBase[i]);
			qty++;
		}
	}
	return *this;
}

MyBase& MyBase::operator=(MyBase&& ob)
{
	clear_base();
	if (ob.qty > 0)
	{
		if ((capacity - 1) < ob.qty)
			add_capacity(ob.qty - capacity + 1);
		for (int i = 0; i < ob.qty; i++)
		{
			pBase[i] = ob.pBase[i];
			ob.pBase[i] = nullptr;
		}
		qty = ob.qty;
		ob.qty = 0;
	}
	return *this;
}

MyData& MyBase::operator[](const char* key) // throws out_of_range if not match
{
	int posFound = find_item(key); // checks for nullptr by itself
	if(posFound >=0) return pBase[posFound]->data;
	//throw out_of_range{""};
	MyPair tmp=MyPair(key);
	add_item(tmp);
	posFound = find_item(key);
	return pBase[posFound]->data;
}

bool MyBase::operator+=(const MyPair& p)
{
	int posFound = find_item(p.key.GetString());
	if (posFound>=0) return false;
	add_item(p);
	return true;
}

bool MyBase::operator-=(const char* key)
{
	int posFound = find_item(key);
	if (posFound<0) return false;
	remove_item(posFound);
	return true;
}

bool MyBase::if_contains(const char* key) const
{
	if (key != nullptr)
		if (find_item(key) > 0) return true;
	return false;
}

void MyBase::print_bd() const
{
	size_t i = qty;
	while (i > 0)
	{
		cout << *pBase[i - 1] << endl;
		i--;
	}
}

void MyBase::add_capacity(size_t n)
{
	size_t newCap = capacity + n;
	MyPair** newBase = new MyPair * [newCap];
	if (capacity != 0)
	{
		size_t cpySize = sizeof(pBase) * (qty + 1);
		memcpy(newBase, pBase, cpySize);
		delete[]pBase;		// remove pointers array
		for (size_t i = qty+1; i < newCap; i++)
			newBase[i] = nullptr;
	}
	pBase = newBase;
	capacity = newCap;
}

int MyBase::find_item(const char* key) const
{
	if (key != nullptr)
	{
		size_t posFound = 0;
		while (posFound < qty)
		{
			//cout << "  _" << posFound << endl;
			if (*pBase[posFound] == key)
				return posFound;
			posFound++;
		}
	}
	return -1;
}

void MyBase::add_item(const MyPair& p)
{
	int capReserv = capacity - qty;
	if (capReserv < 1)
	{
		capReserv = 2;
		//capReserv = (capReserv < 0) ? (qty - capacity + 1) : 1;
		add_capacity(capReserv);
	}
	MyPair* tmp = new MyPair;
	*tmp = p;
	pBase[qty] = tmp;
	//cout << "___added to pos _" << qty << "\t" << *pBase[qty] << endl;
	qty++;

}

void MyBase::remove_item(int pos)
{
	if ((pos >= 0) && (pos < qty))
	{
		delete pBase[pos];
		pBase[pos] = pBase[qty - 1];
		pBase[qty - 1] = nullptr;
		qty--;
	}
}

void MyBase::clear_base()
{
	if (qty > 0)
	{
		for (size_t i = 0; i < qty; i++)
		{
			delete pBase[i];
			pBase[i] = nullptr;
		}
		qty = 0;
	}
}

ostream& operator<<(ostream& os, const MyBase& bd)
{
	os << "BD Items Qty= " << bd.qty << " of " << bd.capacity <<endl;
	os << "=====================================================\n";
	bd.print_bd();
	os << "=====================================================\n";
	return os;
}

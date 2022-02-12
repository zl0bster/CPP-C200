
#include <iostream>
#include <exception>

#include "MyBase.h"
//#include "MyPair.h"

MyBase::MyBase()
{
	qty = 0;
	capacity = 0;
	pBase = nullptr;
	std::cout << "base created\n";
}

MyBase::~MyBase()
{
	delete[] pBase;
	std::cout << "base removed\n";
}

MyData& MyBase::operator[](const char* key) // throws out_of_range if not match
{
	int posFound = find_item(key); // checks for nullptr by itself
	if(posFound >=0) return pBase[posFound]->data;
	throw out_of_range{""};
}

bool MyBase::operator+(const MyPair& p)
{
	int posFound = find_item(p.key.GetString());
	if (posFound>=0) return false;
	add_item(p);
	return true;
}

bool MyBase::operator-(const char* key)
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
	while (qty > 0)
		cout << *pBase[i-1] << endl;
}

void MyBase::add_capacity(size_t qty)
{
	size_t newCap = capacity + qty;
	MyPair** newBase = new MyPair * [newCap];
	if (capacity != 0)
	{
		for (int i = 0; i < qty; i++)
			newBase[i] = pBase[i];
		delete[]pBase;		// remove pointers array
		for (size_t i = qty; i < capacity; i++)
			newBase[i] = nullptr;
	}
	pBase = newBase;
}

int MyBase::find_item(const char* key) const
{
	if (key != nullptr)
	{
		size_t posFound = 0;
		while (posFound < qty)
		{
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
		capReserv = (capReserv < 0) ? (qty - capacity + 1) : 1;
		add_capacity(capReserv);
	}
	MyPair* tmp = new MyPair;
	*tmp = p;
	pBase[qty] = tmp;
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

ostream& operator<<(ostream& os, const MyBase& bd)
{
	os << "BD Items Qty= " << bd.qty << " of " << bd.capacity;
	return os;
}

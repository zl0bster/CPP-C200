
#include <iostream>

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

MyData& MyBase::operator[](const char* key)
{
	// TODO: insert return statement here
}

bool MyBase::operator+(const MyPair&)
{
	return false;
}

bool MyBase::operator-(const char* key)
{
	return false;
}

void MyBase::add_capacity(size_t qty)
{
}

int MyBase::find_item(const char* key)
{
	return 0;
}

ostream& operator<<(ostream& os, const MyBase& bd)
{
	// TODO: insert return statement here
}

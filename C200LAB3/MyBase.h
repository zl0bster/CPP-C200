#pragma once
#include <iostream>

#include "MyPair.h"
#include "MyData.h"

class MyBase
{
	size_t qty;
	size_t capacity;
	MyPair* pBase;
public:
	MyBase();
	~MyBase();

	MyData& operator[](const char* key);

	friend ostream& operator<<(ostream& os, const MyBase& bd);
};


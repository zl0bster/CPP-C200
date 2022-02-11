#pragma once
#include "myString.h"
#include "MyData.h"
#include <iostream>

class MyPair
{
	MyString key;
	MyData data;
public:
	MyPair(const char* k = nullptr, const MyData* md = nullptr);
	bool operator==(const char* k) const;
	friend class MyBase;
	friend ostream& operator<<(ostream& os, const MyPair& mp);
};


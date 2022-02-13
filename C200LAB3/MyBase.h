#pragma once
#include <iostream>

#include "MyPair.h"
#include "MyData.h"

class MyBase
{
	size_t qty;
	size_t capacity;
	MyPair** pBase;
public:
	MyBase();
	~MyBase();
	MyBase(const MyBase& ob);
	MyBase(MyBase&& ob);
	MyBase& operator=(const MyBase& ob);
	MyBase& operator=(MyBase&& ob);

	MyData& operator[](const char* key);
	bool operator+=(const MyPair&);
	bool operator-=(const char* key);
	bool if_contains(const char* key) const;
	void print_bd() const;
	friend ostream& operator<<(ostream& os, const MyBase& bd);
	
private:
	void add_capacity(size_t qty = 1);
	int find_item(const char* key) const;	// negative if not found
	void add_item(const MyPair&);			//no check for correct arg
	void remove_item(int pos);				//no check for correct arg
	void clear_base();
};


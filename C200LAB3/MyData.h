#pragma once
#include <iostream>
#include "myString.h"

class MyData
{
	static size_t counter;
public:
	enum Sex {UNDEF, MALE, FEMALE};
private:
	size_t m_id;
	Sex m_sex;
	size_t m_age;
	MyString m_job;
	float m_salary;
public:
	MyData(Sex s = UNDEF, size_t age = 0, const char* job = nullptr, float sal = 0);
	//MyData(const MyData& md);
	//MyData(MyData&& md);
	//~MyData();
	//MyData& operator=(const MyData& md);
	//MyData& operator=(MyData&& md);

	friend ostream& operator<<(ostream& os, const MyData& md);
};


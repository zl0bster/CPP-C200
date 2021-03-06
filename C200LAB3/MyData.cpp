#include <iostream>
#include "MyData.h"

size_t MyData::counter = 0;

MyData::MyData(Sex s, size_t age, const char* job, float sal)
{
	m_sex = s;
	m_age = age;
	m_job = MyString(job);
	m_salary = sal;
	m_id = ++counter;
}
//
//MyData::MyData(const MyData& md)
//{
//}
//
//MyData::MyData(MyData&& md)
//{
//	m_sex = md.m_sex;
//	m_age = md.m_age;
//	m_job = md.m_job;
//	m_salary = md.m_salary;
//	m_id = ++counter;
//}
//
//MyData::~MyData()
//{
//}

ostream& operator<<(ostream& os, const MyData& md)
{
	char sxAlph[]{ "UMF" };
	char sx = sxAlph[md.m_sex];
	os << "ID: " << md.m_id << "\t" << sx << "\t" << md.m_age
		<< "\t" << md.m_job << "\t" << md.m_salary;
	return os;
}
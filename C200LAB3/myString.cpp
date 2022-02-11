#pragma warning(disable : 4996)


#include <stdio.h>
#include <string>
#include <iostream>
#include "myString.h"
using namespace std;

size_t MyString::counter = 0;

MyString::MyString()
{
	m_pStr = nullptr;
	m_id = ++counter;
}

MyString::~MyString()
{
	if (m_pStr != nullptr)
		cout << "free string memory\t" << m_pStr << "\n" << "ID: " << m_id << " = = =\n";
	else
		cout << "free string memory\t" << "ID: " << m_id << " = = =\n";
}

MyString::MyString(const char* other)
{
	m_pStr = nullptr;
	m_id = ++counter;
	SetNewString(other);
}

MyString::MyString(const MyString& other)
{
	m_pStr = nullptr;
	m_id = ++counter;
	SetNewString(other.m_pStr);
}

MyString::MyString(MyString&& other)
{
	m_pStr = other.m_pStr;
	m_id = ++counter;
}

void MyString::SetNewString(const char* other)
{
	delete[] m_pStr;
	if (other != nullptr)
	{
		size_t len = strlen(other) + 1;
		m_pStr = new char[len];
		strcpy_s(m_pStr, len, other);
	}
	else
		m_pStr = nullptr;
}

void MyString::PrintMyString() const
{
	if (m_pStr != nullptr)
	{
		printf(m_pStr);
		printf("\n");
	}
}

const char* MyString::GetString() const
{
	return m_pStr;
}

void MyString::Concat(const char* other)
{
	if (other == nullptr) return;
	if (m_pStr != nullptr)
	{
		size_t lenOther = strlen(other) + 1;
		size_t lenOrig = strlen(m_pStr) + 1;
		char* newStr = new char[lenOther + lenOrig + 1];
		strcpy_s(newStr, lenOrig, m_pStr);
		strcat(newStr, other);
		delete[] m_pStr;
		m_pStr = newStr;
	}
	else
	{
		size_t lenOther = strlen(other) + 1;
		char* newStr = new char[lenOther + 1];
		strcpy_s(newStr, lenOther, other);
		delete[] m_pStr;
		m_pStr = newStr;
	}
}

MyString& MyString::operator=(const MyString& oth)
{
	if (this != &oth)
	{
		SetNewString(oth.m_pStr);
	}
	return *this;
}

MyString& MyString::operator=(MyString&& oth)
{
	if (this != &oth)
	{
		SetNewString(oth.m_pStr);
	}
	return *this;
}

MyString& MyString::operator=(const char* oth)
{
	SetNewString(oth);
	return *this;
}

MyString& MyString::operator+=(const MyString& oth)
{
	Concat(oth.m_pStr);
	return *this;
}

MyString MyString::operator+(const MyString& oth) const
{
	MyString tmp(m_pStr);
	tmp.Concat(oth.m_pStr);
	return tmp;
}

//
//MyString operator+(const MyString& left, const MyString& right)
//{
//	MyString tmp(left);
//	tmp.Concat(right.m_pStr);
//	return tmp;
//}

ostream& operator<<(ostream& os, const MyString& it)
{
	if (it.m_pStr != nullptr)
		os << "ID: " << it.m_id << "\t" << it.m_pStr;
	else
		os << "ID: " << it.m_id << "\tempty";
	return os;
}

MyString ConcatLines(const char* line, ...)// nullptr is end of line
{
	size_t lineLength = 1;
	const char** p_arg = &line;
	const char* currentLine = *p_arg;
	while (currentLine != nullptr)
	{
		lineLength += strlen(currentLine);
		p_arg++;
		currentLine = *p_arg;
	}
	char* newLine = new char[lineLength + 1];
	*newLine = 0;
	p_arg = &line;
	currentLine = *p_arg;;
	char* destPos = newLine;
	while (currentLine != nullptr)
	{
		strcat(newLine, currentLine);
		p_arg++;
		currentLine = *p_arg;
	}
	MyString tmp(newLine);
	delete[] newLine;
	return tmp; // don't use std::move()
}

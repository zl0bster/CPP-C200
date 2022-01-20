#pragma warning(suppress : 4996)


#include <stdio.h>
#include <string>
#include <iostream>
#include "myString.h"
using namespace std;

MyString::MyString()
{
	m_pStr = nullptr;
}

MyString::~MyString()
{
	cout << "free string memory\n";
}

MyString::MyString(const char* other)
{
	m_pStr = nullptr;
	SetNewString(other);
}

void MyString::SetNewString(const char* other)
{
	size_t len = strlen(other)+1;
	char* newStr = new char[len + 1];
	strcpy_s(newStr, len, other);
	if (m_pStr != nullptr)
		delete [] m_pStr;
	m_pStr = newStr;
}

void MyString::PrintMyString()
{
	if (m_pStr != nullptr)
	{
		printf(m_pStr);
		printf("\n");
	}
}

const char* MyString::GetString()
{
	return m_pStr;
}

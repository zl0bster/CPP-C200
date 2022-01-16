#pragma warning(suppress : 4996)


#include <stdio.h>
#include <string>
#include <iostream>
#include "myString.h"
using namespace std;

// Определение конструктора.


// Определение деструктора.

MyString::MyString()
{
	m_pStr = nullptr;
}

MyString::~MyString()
{
	cout << "free string memory\n";
	//if (m_pStr != nullptr)
	//	delete [] m_pStr;
	//m_pStr = nullptr;
	//delete m_pStr;
}

MyString::MyString(const char* other)
{
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
	//cout << m_pStr << '\n';
	printf(m_pStr);
	printf("\n");
}

const char* MyString::GetString()
{
	return m_pStr;
}

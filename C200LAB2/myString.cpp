#pragma warning(disable : 4996)


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
	if  (m_pStr != nullptr)
		cout << "free string memory : " << m_pStr << "\n";
	else
		cout << "free empty string memory \n";
	delete[] m_pStr;
}

MyString::MyString(const char* other)
{
	m_pStr = nullptr;
	SetNewString(other);
}

MyString::MyString(const MyString& other)
{
	m_pStr = nullptr;
	SetNewString(other.m_pStr);
}

MyString::MyString(MyString&& other)
{
	m_pStr = other.m_pStr;
	other.m_pStr = nullptr;
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
	size_t lenOther = strlen(other) + 1;
	size_t lenOrig = strlen(m_pStr) + 1;
	char* newStr = new char[lenOther + lenOrig + 1];
	strcpy_s(newStr, lenOrig, m_pStr);
	strcpy_s(newStr + lenOrig, lenOther, other);
	delete[] m_pStr;
	m_pStr = newStr;
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
		//int len = strlen(currentLine);
		//strcpy_s(destPos, lineLength, currentLine);
		//strcpy(destPos, currentLine);
		strcat(newLine, currentLine);
		//destPos += len;
		p_arg++;
		currentLine = *p_arg;
	}
	//*destPos = 0;
	//newLine[lineLength-1] = 0;
	MyString tmp(newLine);
	delete[] newLine;
	return tmp; // don't use std::move()
}

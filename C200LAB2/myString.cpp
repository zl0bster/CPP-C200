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
	size_t lineLength = 0;
	char** currentLine = line;//const_cast<char*> (line);
	while (currentLine != nullptr)
	{
		lineLength += strlen(*currentLine);
		currentLine ++;
	}
	char* newLine = new char[lineLength + 1];
	currentLine = const_cast<char*> (line);
	char* destPos = newLine;
	while (currentLine != nullptr)
	{
		lineLength = strlen(*currentLine);
		strcpy_s(destPos, lineLength, *currentLine);
		destPos += lineLength;
		currentLine++;
	}
	*destPos = '/0';
	return MyString(newLine);
}

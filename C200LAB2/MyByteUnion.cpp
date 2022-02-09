#include <iostream>

#include "MyByteUnion.h"


using namespace std;

MyUnion::MyUnion(unsigned char byte)
{
	bt = byte;
}

void Bin::show() const
{
	int val[]{b7,b6,b5,b4,b3,b2,b1,b0};
	char str[]{ "00000000" };
	const char* alfabet = "01";
	for (unsigned char i = 0; i < 8;i++ )
	{
			str[i] = alfabet[val[i]];
	}
	cout << str << endl;
}

void Bin::showPos(size_t pos) const
{
}

void Bin::edit(size_t pos, size_t val)
{
	if (pos > 7) return;
	if (val > 1) return;
	switch (pos)
	{
	case 0:
		b0 = val;
		break;
	case 1:
		b1 = val;
		break;
	case 2:
		b2 = val;
		break;
	case 3:
		b3 = val;
		break;
	case 4:
		b4 = val;
		break;
	case 5:
		b5 = val;
		break;
	case 6:
		b6 = val;
		break;
	case 7:
		b7 = val;
		break;
	}
}

void Oct::show() const
{
	int val[]{ oct2, oct1, oct0 };
	char str[]{ "000" };
	const char* alfabet = "01234567";
	unsigned char buf = 0;
	for (unsigned char i = 0; i < 3; i++)
	{
		str[i] = alfabet[val[i]];
	}
	cout << str << endl;
}

void Oct::showPos(size_t pos) const
{
}

void Oct::edit(size_t pos, size_t val)
{
	if (pos > 2) return;
	if (val > 7) return;
	switch (pos)
	{
	case 0:
		oct0 = val;
		break;
	case 1:
		oct1 = val;
		break;
	case 2:
		oct2 = val;
		break;
	}
}


void Hex::show() const
{
	int val[]{ hex1, hex0 };
	char str[]{ "00" };
	const char* alfabet = "0123456789ABCDEF";
	unsigned char buf = 0;
	for (unsigned char i = 0; i < 2; i++)
	{
		str[i] = alfabet[val[i]];
	}
	cout << str << endl;
}

void Hex::showPos(size_t pos) const
{
}

void Hex::edit(size_t pos, size_t val)
{
	if (pos > 1) return;
	if (val > 15) return;
	switch (pos)
	{
	case 0:
		hex0 = val;
		break;
	case 1:
		hex1 = val;
		break;
	}
}

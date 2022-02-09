#include <iostream>

#include "MyByteUnion.h"


using namespace std;

MyUnion::MyUnion(unsigned char byte)
{
	bt = byte;
}

void Bin::show() const
{
	char val[9]{"00000000"};
	const char* alfabet = "01";
	unsigned char buf = 0;
	for (unsigned char i = 0; i < 8;i++ )
	{
		switch (i)
		{
		case 0:
			buf = b7;
			break;
		case 1:
			buf = b6;
			break;
		case 2:
			buf = b5;
			break;
		case 3:
			buf = b4;
			break;
		case 4:
			buf = b3;
			break;
		case 5:
			buf = b2;
			break;
		case 6:
			buf = b1;
			break;
		case 7:
			buf = b0;
			break;
		}
		if (buf < 2)
		{
			val[i] = alfabet[buf];
		}
	}
	cout << val << endl;
}

void Bin::showPos(size_t pos)
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
	char val[4]{ "000" };
	const char* alfabet = "01234567";
	unsigned char buf = 0;
	for (unsigned char i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 0:
			buf = oct2;
			break;
		case 1:
			buf = oct1;
			break;
		case 2:
			buf = oct0;
			break;
		}
		if (buf < 16)
		{
			val[i] = alfabet[buf];
		}
	}
	cout << val << endl;
}

void Oct::showPos(size_t pos)
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
	char val[3]{ "00" };
	const char* alfabet = "0123456789ABCDEF";
	unsigned char buf = 0;
	for (unsigned char i = 0; i < 2; i++)
	{
		switch (i)
		{
		case 0:
			buf = hex1;
			break;
		case 1:
			buf = hex0;
			break;
		}
		if (buf < 16)
		{
			val[i] = alfabet[buf];
		}
	}
	cout << val << endl;
}

void Hex::showPos(size_t pos)
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

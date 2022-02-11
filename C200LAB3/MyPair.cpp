#include <string>
#include "MyPair.h"

MyPair::MyPair(const char* k, const MyData* md)
{
	key = MyString(k);
	data = *md;
}

bool MyPair::operator==(const char* k) const
{
	int cpResult = strcmp(key.GetString(), k);
	if (cpResult == 0) return true;
	return false;
}

ostream& operator<<(ostream& os, const MyPair& mp)
{
	os << mp.key << "\t" << mp.data;
	return os;
}

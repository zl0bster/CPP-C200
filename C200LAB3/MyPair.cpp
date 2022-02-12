#include <string>
#include <random>
#include "MyPair.h"

MyPair::MyPair(const char* k, const MyData* md)
{
	key = MyString(k);
	if (md!=nullptr)
		data = *md;
}

bool MyPair::operator==(const char* k) const
{
	if ((k != nullptr) && (key.GetString() != nullptr))
	{
		int cpResult = strcmp(key.GetString(), k);
		if (cpResult == 0) return true;
	}
	return false;
}

void MyPair::fill_it_rnd()
{
	const char* names[] = { "John", "Sam", "Mike", "Sergio", "Marko", "Rufalo", "Ras", "Hnu", "Ptah"};
	const char* jobs[] = { "carpenter", "student", "scientist", "driver", "engineer" };
	size_t namesQty = sizeof(names)/sizeof(char*);
	size_t tmp = rand() % namesQty;
	const char* name = names[tmp];
	tmp = rand() % (sizeof(jobs) / sizeof(char*));
	const char* job = jobs[tmp];
	//cout << name << "\t" << job << endl;
	int age = rand() % 50;
	float salary = rand() % 3000;
	key.operator=(name);
	data = MyData(MyData::MALE, age, job, salary);
}

ostream& operator<<(ostream& os, const MyPair& mp)
{
	os << mp.key << "\t" << mp.data;
	return os;
}

#include <iostream>
using namespace std;

#include "MyList.h"
#include "MyCircle.h"

void main()
{
	MyList ml;
	MyCircle mc;
	cout << ml << endl;
	for (int i = 0; i < 12; i++)
	{
		mc.set_rnd();
		ml.push_tail(&mc);
	}

	MyList ml1(ml);
	ml.pop_head();
	ml.pop_tail();

	cout << ml << endl;
	cout << ml1 << endl;
	ml1 = ml;
	cout << ml << endl;
}
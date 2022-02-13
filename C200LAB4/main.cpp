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
		ml.push_tale(&mc);
	}

	cout << ml << endl;
}
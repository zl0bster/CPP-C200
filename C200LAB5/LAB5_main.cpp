#include <iostream>
#include <string.h>

#include "String2.h"

int main() {
	const char* sc1 = "abc";
	String2 s1(sc1);
	String2 s2("abc");
	String2 s3("abcd");
	String2 s4;
	s4 = s2;
	String2::print_list();
	return 0;
}
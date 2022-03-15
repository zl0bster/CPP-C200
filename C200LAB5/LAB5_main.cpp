#include <iostream>
#include <string.h>

#include "String2.h"

int main() {
	const char* sc1 = "abc";
	String2 s1(sc1);
	String2 s2("abc");
	String2 s3("dabcd");
	String2 s4;
	s4 = s2;
	std::cout << s3 << std::endl;
	std::cout << sc1 << std::endl;
	String2::print_list();
	return 0;
}
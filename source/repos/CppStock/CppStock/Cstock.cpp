#define  _CRT_SECURE_NO_WARNINGS
#include"Cstock.h"


void test()
{
	CStock <string> l1;

	l1.Push("h");
	l1.Push("e");
	l1.Push("l");
	l1.Push("l");
	l1.Push("o");
	l1.Print();
}

int main()
{
	test();
}

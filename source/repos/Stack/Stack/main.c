#define  _CRT_SECURE_NO_WARNINGS
#include"Stack.h"
void test()
{
	Tc a;
	InitStack(&a);
	AddStack(&a, 1);
	AddStack(&a, 2);
	AddStack(&a, 3);
	AddStack(&a, 4);
	AddStack(&a, 5);
	/*PrintStack(&a);*/

	DATA c=TopStack(&a);
	printf("%d ", c);

	DesStack(&a);
}

int main()
{
	test();
	return 0;
}
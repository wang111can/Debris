#define  _CRT_SECURE_NO_WARNINGS



#include"queue.h"

void test()
{
	Queue Que;
	Que.Push(1);
	Que.Push(2);
	
	Que.Push(3);
	Que.Push(4);
	Que.Print();
	std::cout << std::endl;
	Que.Pop();
	Que.Print();
	std::cout << std::endl;

	Que.Push(5);
	Que.Pop();
	Que.Pop();
	Que.Pop();
	Que.Print();
	std::cout << std::endl;


}
int main()
{
	test();
	return 0;


}
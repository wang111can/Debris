#define  _CRT_SECURE_NO_WARNINGS
#include"class.h"






void test()
{
	List one;
	one.HeadNonde(9);
	one.HeadNonde(8);
	one.Print();
	one.HeadNonde(7);
	one.HeadDes();
	one.HeadNonde(6);
	one.Print();

}



void test2()
{
	List one;
	one.EndNode(1);	
	one.Print();

	one.EndDes();
	one.Print();
	one.EndNode(2);
	

	one.EndNode(3);
	one.EndNode(4);
	one.EndDes();
	one.EndNode(5);
	one.EndNode(1);
	
}
void test3()
{
	List one;
	one.HeadNonde(1);
	one.HeadNonde(2);
	one.SpDele(3);

	one.Print();
	one.SpDele(2);
	one.HeadNonde(3);
	one.HeadNonde(4);
	one.Print();
	one.HeadNonde(5);
	one.HeadNonde(6);
	one.HeadNonde(7);


}
int main()
{
	test3();
}
#define  _CRT_SECURE_NO_WARNINGS
#include"List.h"
void Print( SListNode** pphead)
{
	SListNode* p = *pphead;
	while (p)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}
void test()
{
	SListNode *p= BuySListNode(0);
	SListPushBack(&p, 2);
	SListPushFront(&p, 1);
	Print(&p);
}
int main()
{
	test();

}
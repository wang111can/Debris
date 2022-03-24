#define  _CRT_SECURE_NO_WARNINGS
#include"List.h"
SListNode* BuySListNode(SLTDateType x)// 动态申请一个节点
{
	SListNode* p = (SListNode*)malloc(sizeof(SListNode));
	p->data = x;
	p->next = NULL;
	return p;
}

void SListPushBack(SListNode** pplist, SLTDateType x)// 单链表尾插
{
	assert(pplist);
	SListNode* p = BuySListNode(x);
	SListNode* pr = *pplist;
	while (pr->next)
	{
		pr = pr->next;
	}
	pr->next = p;
}
void SListPushFront(SListNode** pplist, SLTDateType x)// 单链表的头插
{
	SListNode* newnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		newnode->next = *pplist;
		*pplist = newnode;
	}
}
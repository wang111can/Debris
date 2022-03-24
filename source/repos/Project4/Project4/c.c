#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int LIST;
typedef  struct SList
{
	LIST data;
	struct SList* next;
}SLIST;


SLIST* BuyBode(LIST x)
{
	SLIST* newnode = (SLIST*)malloc(sizeof(SLIST));//为新节点开辟空间
	newnode->data = x;
	return newnode;
}

SLIST* NodeSeek(SLIST* phead,LIST x)//查找
{
	SLIST* replica = phead;
	while (replica != NULL)
	{
		if (replica->data == x)
			return replica;
		replica = replica->next;
	}
	return NULL;
}

void ListData(SLIST** pphead, LIST x)//尾增
{
	SLIST* newnode = BuyBode(x);
	newnode->next = NULL;//最后一个单链表的指针指向空
	if (*pphead == NULL)//判断链表是否为空
	{
		*pphead = newnode;
	}
	else
	{
		SLIST* replica = *pphead;
		while (replica->next != NULL)
		{
			replica = replica->next;
		}
		replica->next = newnode;//存放下一节点的地址
	}
}
void ListData1(SLIST** pphead, LIST x)//头增
{		

	SLIST* newnode = BuyBode(x);
	if (*pphead == NULL)//判断链表是否为空
	{	
		newnode->next = NULL;
		*pphead = newnode;
	}
	else
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}


}
void listprint(SLIST* phead)//打印
{
	if (phead == NULL)
		return;
	SLIST* replica = phead;
	while (replica != NULL)
	{
		printf("%d-> ", replica->data);
		replica = replica->next;
	}
	printf("NULL\n");
}
void InsertNode(SLIST** pphead,SLIST*pos, LIST x)
{
	if (pos == *pphead)
	{
		ListData1(pphead, x);//当要被插入的位置是第一个元素前时，就相当于头增
	}
	else
	{
		SLIST* newnode = BuyBode(x);
		SLIST* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
	
}
void HeadDel(SLIST** pphead)//头删
{
	SLIST* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}
void EndDel(SLIST** pphead)//尾删
{
	if (*pphead == NULL)//如果链表为空
		return;
	else if ((*pphead)->next == NULL)//如果链表只有一个元素
	{
		free(*pphead);
		*pphead = NULL;
	}

	else//链表有多个元素
	{
		SLIST* rev = NULL;
		SLIST* replica = *pphead;
		while (replica->next != NULL)//查找最后一个元素
		{

			rev = replica;//存放replica前一个元素
			replica = replica->next;
		}
		free(replica);
		rev->next = NULL;
	}

}
void DelNode(SLIST** pphead, SLIST* pos)//删除指定位置元素
{
	if ((*pphead) == pos)
	{
		HeadDel(pphead);
	}
	else
	{
		SLIST* sev = *pphead;
		while (sev->next != pos)
		{
			sev = sev->next;
		}
		sev->next = pos->next;
		free(pos);
	}
}

void Singlelist()
{
	SLIST* p = NULL;//定义一个标头
	ListData(&p, 1);
	EndDel(&p);
	ListData1(&p, 2);
	//HeadDel(&p);
	ListData(&p, 3);
	ListData(&p, 4);
	SLIST* pos = NodeSeek(p, 2);
	if (pos)
	{
		InsertNode(&p, pos, 10);
	}
	pos = NodeSeek(p, 3);
		if (pos)
		{
			DelNode(&p, pos);
		}
	listprint(p);//打印
}


int main()
{
	Singlelist();
	return 0;
}
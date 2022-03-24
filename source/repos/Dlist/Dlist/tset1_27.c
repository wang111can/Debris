#define  _CRT_SECURE_NO_WARNINGS
#include"List.h"
LIST* BuyNode(int x)
{
	LIST* newnode = (LIST*)malloc(sizeof(LIST));
	if (newnode == NULL)
		return NULL;
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}


LIST* BuyHead()
{
	LIST* head = BuyNode(0);
	head->next = head;
	head->prev = head;
	return head;
}

void Print(LIST* phead)//打印
{
	LIST* replica = phead->next;
	
	while (replica != phead)
	{
		printf("%d ", replica->data);
		replica = replica->next;
	}
	printf("\n");
}

void Hnode(LIST* phead,int x)//头增
{
	assert(phead);
	LIST* newnode = BuyNode(x);
	newnode->next = phead->next;
	phead->next->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;
}


void Wnode(LIST* phead, int x)//尾
{
	LIST* newnode = BuyNode(x);
	LIST* replica = phead->prev;
	replica->next = newnode;
	newnode->prev = replica;
	newnode->next = phead;
	phead->prev = newnode;


}

void DenHnode(LIST* phead)//头删
{

	assert(phead);
	assert(phead->next != phead);
	LIST* replica = phead->next;
	replica->next->prev = phead;
	phead->next = replica->next;
	free(replica);
	replica = NULL;


}
void DenWnode(LIST* phead)//尾删
{
	assert(phead);
	assert(phead->prev != phead);
	LIST* replica = phead->prev;
	phead->prev = replica->prev;
	replica->prev->next = phead;
	free(replica);
	replica = NULL;

}

LIST* SeekList(LIST* head, int x)//查找
{
	assert(head);
	LIST* replica = head->next;
	while (replica != head)
	{
		if (replica->data == x)
		{
			return replica;
		}
		replica = replica->next;
	}
	return NULL;
}

void SpDen(LIST* cop)//删除指定元素
{
	LIST* prev = cop->prev;
	LIST* next = cop->next;
	prev->next = next;
	next->prev = prev;
	free(cop);
	cop = NULL;
}
void SpAdd(LIST* cop,int x)
{
	LIST* newnode = BuyNode(x);
	LIST* replica = cop->prev;
	replica->next = newnode;
	newnode->prev = replica;
	newnode->next = cop;
	cop->prev = newnode;


}

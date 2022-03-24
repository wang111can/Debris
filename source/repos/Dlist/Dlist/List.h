#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct LIST
{
	struct LIST* prev;
	struct LIST* next;
	int data;
}LIST;

LIST* BuyHead();
LIST* BuyNode(int x);

void Hnode(LIST* phead,int x);
void Wnode(LIST* phead, int x);
void DenHnode(LIST* phead);//头删
void DenWnode(LIST* phead);//尾删

void SpDen(LIST* cop);//删除指定元素
LIST* SeekList(LIST* head, int x);//查找
void SpAdd(LIST* cop,int x);
void Print(LIST* phead);


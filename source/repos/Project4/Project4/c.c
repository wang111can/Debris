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
	SLIST* newnode = (SLIST*)malloc(sizeof(SLIST));//Ϊ�½ڵ㿪�ٿռ�
	newnode->data = x;
	return newnode;
}

SLIST* NodeSeek(SLIST* phead,LIST x)//����
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

void ListData(SLIST** pphead, LIST x)//β��
{
	SLIST* newnode = BuyBode(x);
	newnode->next = NULL;//���һ���������ָ��ָ���
	if (*pphead == NULL)//�ж������Ƿ�Ϊ��
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
		replica->next = newnode;//�����һ�ڵ�ĵ�ַ
	}
}
void ListData1(SLIST** pphead, LIST x)//ͷ��
{		

	SLIST* newnode = BuyBode(x);
	if (*pphead == NULL)//�ж������Ƿ�Ϊ��
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
void listprint(SLIST* phead)//��ӡ
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
		ListData1(pphead, x);//��Ҫ�������λ���ǵ�һ��Ԫ��ǰʱ�����൱��ͷ��
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
void HeadDel(SLIST** pphead)//ͷɾ
{
	SLIST* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}
void EndDel(SLIST** pphead)//βɾ
{
	if (*pphead == NULL)//�������Ϊ��
		return;
	else if ((*pphead)->next == NULL)//�������ֻ��һ��Ԫ��
	{
		free(*pphead);
		*pphead = NULL;
	}

	else//�����ж��Ԫ��
	{
		SLIST* rev = NULL;
		SLIST* replica = *pphead;
		while (replica->next != NULL)//�������һ��Ԫ��
		{

			rev = replica;//���replicaǰһ��Ԫ��
			replica = replica->next;
		}
		free(replica);
		rev->next = NULL;
	}

}
void DelNode(SLIST** pphead, SLIST* pos)//ɾ��ָ��λ��Ԫ��
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
	SLIST* p = NULL;//����һ����ͷ
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
	listprint(p);//��ӡ
}


int main()
{
	Singlelist();
	return 0;
}
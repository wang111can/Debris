#include"contact.h"

void InitContact(Contact* pc)
{
	pc->data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		perror("InitContact");
		return;
	}
	pc->capacity = DEFAULT_SZ;
	pc->sz = 0;
}



void CheckCapacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data,(pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			return;
		}
		else
		{
			perror("AddContact");
			printf("������ϵ��ʧ��\n");
			return;
		}
	}
}



void AddContact(Contact* pc)
{
	CheckCapacity(pc);
	printf("����������:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("�������Ա�:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("����������:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("������绰:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ:>");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("��ӳɹ�\n");
}



static int FindByName(Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}

	return -1;//�Ҳ���
}



void DelContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�����ɾ��\n");
		return;
	}
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name);
	//1. ����Ҫɾ������
	//��/û��
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	//2. ɾ��
	int i = 0;
	for (i = pos; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");
}


void PrintContact(const Contact* pc)
{
	int i = 0;
	//��ӡ����
	printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	//��ӡ����
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-15s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}



void SearchContact(const Contact* pc)
{
	char name[MAX_NAME];
	printf("������Ҫ�����˵�����:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	else
	{
		printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
			printf("%-15s\t%-5d\t%-5s\t%-12s\t%-20s\n",
				pc->data[pos].name,
				pc->data[pos].age,
				pc->data[pos].sex,
				pc->data[pos].tele,
				pc->data[pos].addr);
	}
}


void ModifyContact(Contact* pc)
{
	char name[MAX_NAME];
	printf("�������޸��˵�����:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	else
	{
		printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\n", "1.����", "2.����", "3.�Ա�", "4.�绰", "5.��ַ");
		printf("%-15s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr);
		printf("������Ҫ�޸ĵ���Ϣ(���,0�˳�):>");
		int i = 0;
		scanf("%d", &i);
		do
		{
			switch (i)
			{
			case 1:
				printf("����:>");
				scanf("%s", pc->data[pos].name);
				break;
			case 2:
				printf("����:>");
				scanf("%d", pc->data[pos].age);
				break;
			case 3:
				printf("�Ա�:>");
				scanf("%s", pc->data[pos].sex);
				break;
			case 4:
				printf("�绰:>");
				scanf("%s", pc->data[pos].tele);
				break;
			case 5:
				printf("��ַ: >");
				scanf("%s", pc->data[pos].addr);
				break;
			default:
				printf("ѡ�����,����ѡ��");
				break;
			}
		} while (i);
	}
	printf("�޸����\n");
}

int NameSort(const void* e1, const void* e2)
{
	return strcmp(((Contact*)e1)->data->name, ((Contact*)e2)->data->name);
}
int SexSort(const void* x, const void* y)
{
	return strcmp(((Contact*)x)->data->sex, ((Contact*)y)->data->sex);
}
int AgeSort(const void* x, const void* y)
{
	return ((Contact*)x)->data->age - ((Contact*)y)->data->age;
}
 void sortConcate(Contact* pc)
{
	printf("      1.����������\n");
	printf("      2.���Ա�����\n");
	printf("      3.����������\n");
	printf("��ѡ���������:>");
	int input = 0;
	scanf("%d", input);
	switch (input) {

	case 1:
		qsort(pc, pc->sz, sizeof(Contact), NameSort);
		break;
	case 2:
		qsort(pc, pc->sz, sizeof(Contact), SexSort);
		break;
	case 3:
		qsort(pc, pc->sz, sizeof(Contact), AgeSort);
		break;

	}

}


void DestoryContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}
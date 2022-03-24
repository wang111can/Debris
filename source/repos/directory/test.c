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
			printf("增加联系人失败\n");
			return;
		}
	}
}



void AddContact(Contact* pc)
{
	CheckCapacity(pc);
	printf("请输入姓名:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("添加成功\n");
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

	return -1;//找不到
}



void DelContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("通讯录为空，无需删除\n");
		return;
	}
	printf("请输入要删除人的姓名:>");
	scanf("%s", name);
	//1. 查找要删除的人
	//有/没有
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	//2. 删除
	int i = 0;
	for (i = pos; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("删除成功\n");
}


void PrintContact(const Contact* pc)
{
	int i = 0;
	//打印标题
	printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
	//打印数据
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
	printf("请输入要查找人的姓名:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	else
	{
		printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
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
	printf("请输入修改人的姓名:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	else
	{
		printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\n", "1.姓名", "2.年龄", "3.性别", "4.电话", "5.地址");
		printf("%-15s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr);
		printf("请输入要修改的信息(序号,0退出):>");
		int i = 0;
		scanf("%d", &i);
		do
		{
			switch (i)
			{
			case 1:
				printf("姓名:>");
				scanf("%s", pc->data[pos].name);
				break;
			case 2:
				printf("年龄:>");
				scanf("%d", pc->data[pos].age);
				break;
			case 3:
				printf("性别:>");
				scanf("%s", pc->data[pos].sex);
				break;
			case 4:
				printf("电话:>");
				scanf("%s", pc->data[pos].tele);
				break;
			case 5:
				printf("地址: >");
				scanf("%s", pc->data[pos].addr);
				break;
			default:
				printf("选择错误,重新选择");
				break;
			}
		} while (i);
	}
	printf("修改完毕\n");
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
	printf("      1.按姓名排序\n");
	printf("      2.按性别排序\n");
	printf("      3.按年龄排序\n");
	printf("请选择排序类别:>");
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
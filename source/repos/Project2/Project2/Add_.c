#define  _CRT_SECURE_NO_WARNINGS

#include"ADD.h"


void menu()//菜单
{
	printf("_____________________________\n");
	printf("|                            | \n");
	printf("|                            | \n");
	printf("|  1.增加信息    2.删除信息  |\n");
	printf("|  3.查找信息    4.修改信息  |\n");
	printf("|           5.查看           | \n");
	printf("|           0.退出           | \n");
	printf("|                            | \n");
	printf("|----------------------------|\n");


}
//增容
void Congestion(PeopleColl* con)
{
	if (con->sz == con->capacity)
	{


		PeopleInfor* p = (PeopleInfor*)realloc(con->date, (con->capacity + VALUE) * sizeof(PeopleInfor));

		if (con->date == NULL)
		{
			perror("Congestion");
			printf("增容失败\n");
			return;
		}
		else
		{
			con->date = p;
			con->capacity += VALUE;
			printf("增容成功\n");
		}

	}

}




//读取信息
void ReadIfor(PeopleColl* con)
{
	FILE* ptr = fopen("AddBook.dat", "rb");
	if (ptr == NULL)
	{
		perror("ReadIfor");
		printf("读取失败\n");
		return;
	}
	else {
		PeopleInfor mat = { 0 };
		while (fread(&mat, sizeof(PeopleInfor), 1, ptr))
		{
			Congestion(con);
			con->date[con->sz] = mat;
			con->sz++;

		}
	}

}



//储存信息到文件
void StoreIfor(PeopleColl* con)
{
	FILE* p = fopen("AddBook.dat", "wb");
	if (p == NULL)
	{
		perror("StoreIfor");
		printf("存储失败\n");
		return;
	}
	//存储文件
	int i = 0;
	for (i = 0; i < con->sz; i++)
	{
		fwrite(con->date + i, sizeof(PeopleInfor), 1, p);

	}

	printf("存储成功\n");
	//关闭文件
	//释放指针避免内存泄露
	fclose(p);
	p = NULL;
}






//初始化
void Initial(PeopleColl* con)
{
	
	con->date = (PeopleInfor*)calloc(DOUBLE_SZ, sizeof(PeopleInfor));
	if (con->date == NULL)
	{
		perror("Initial");
		return;
	}
	con->sz = 0;
	con->capacity = DOUBLE_SZ;
	ReadIfor(con);
}


//增加信息
void ADDITION(PeopleColl* con)
{
	Congestion(con);

	printf("请输入姓名:\n");
	scanf("%s", con->date[con->sz].name);
	printf("请输入性别:\n");
	scanf("%s", con->date[con->sz].sex);
	printf("请输入地址:\n");
	scanf("%s", con->date[con->sz].add);
	printf("请输入号码:\n");
	scanf("%s", &(con->date[con->sz].num));
	printf("请输入年龄:\n");
	scanf("%d", &(con->date[con->sz].age));
	con->sz++;
	printf("录入成功\n");
}


//小查找
int  Seek(const PeopleColl* con, char arr[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < con->sz; i++)
	{
		if (strcmp(con->date[i].name, arr) == 0)
			return i;
	}
	return -1;

}


//删除信息
void Delete(PeopleColl* con)
{
	if (con->sz == 0) {
		printf("通讯录为空\n");
		return;
	}
	char arr[MAX_NAME] = { 0 };
	printf("请输入要删除人的名字:\n");
	scanf("%s", arr);
	int p = Seek(con, arr);
	if (p == -1) {
		printf("删除的人不存在\n");

	}
	else
	{
		int i = 0;
		for (i = p; i < con->sz - 1; i++) {
			con->date[i] = con->date[i + 1];
		}
		con->sz--;
		printf("删除成功\n");
	}


}


//查找指定人的信息
void SEEK(PeopleColl* con)
{

	if (con->sz == 0) {
		printf("通讯录为空\n");
		return;
	}
	char arr[MAX_NAME] = { 0 };
	printf("请输入要查找人的名字:\n");
	scanf("%s", arr);
	int p = Seek(con, arr);
	if (p == -1) {
		printf("查找的人不存在\n");

	}
	else
	{
		printf("查找人的信息为:\n");
		printf("%-10s %-10s %-20s %-20s %-10s\n", "姓名", "性别", "地址", "号码", "年龄");
		printf("%-10s %-10s %-20s %-20s %-10d\n", con->date[p].name,
			con->date[p].sex,
			con->date[p].add,
			con->date[p].num,
			con->date[p].age);
	}

}




//修改信息
void Revise(PeopleColl* con)
{
	if (con->sz == 0) {
		printf("通讯录为空\n");
		return;
	}
	char arr[MAX_NAME] = { 0 };
	printf("请输入要修改人的名字:\n");
	scanf("%s", arr);
	int p = Seek(con, arr);
	if (p == -1) {
		printf("修改的人不存在\n");

	}
	else {
		printf("请输入姓名:\n");
		scanf("%s", con->date[p].name);
		printf("请输入性别:\n");
		scanf("%s", con->date[p].sex);
		printf("请输入地址:\n");
		scanf("%s", con->date[p].add);
		printf("请输入号码:\n");
		scanf("%s", &(con->date[p].num));
		printf("请输入年龄:\n");
		scanf("%d", &(con->date[p].age));
		printf("修改成功\n");

	}
}


//查看信息
void Check(PeopleColl con)
{
	if (con.sz == 0) {
		printf("请先录入信息\n");
	}

	int i = 0;
	printf("%-10s %-10s %-20s %-20s %-10s\n", "姓名", "性别", "地址", "号码", "年龄");
	for (i = 0; i < con.sz; i++)
	{
		printf("%-10s %-10s %-20s %-20s %-10d\n", con.date[i].name,
			con.date[i].sex,
			con.date[i].add,
			con.date[i].num,
			con.date[i].age);


	}
}


//释放
void Freed(PeopleColl* con)
{
	free(con->date);
	con->date = NULL;
	con->capacity = 0;
	con->sz = 0;
}
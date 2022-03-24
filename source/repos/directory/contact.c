#include"contact.h"

void menu()
{
	printf("                                     \n");
	printf("        1. 增加联系人\t\t\t2. 删除联系人   \n");
	printf("        3. 查找联系人\t\t\t4. 修改信息   \n");
	printf("        5. 进行排序\t\t\t6. 查看信息 \n");
	printf("        0. 退出                        \n");
	printf("                                       \n");
}

enum option
{
	Exit,
	add,
	del,
	search,
	modify,
	sort,
	print
};

int main()
{
	int input;
	Contact con;
	InitContact(&con);
	menu();
	do
	{
		printf("\n请输入选择:>");
		scanf("%d", &input);
		char c;//清理缓冲区避免出错
		while ((c = getchar()) != '\n' && c != EOF);
		printf("\n");
		switch (input)
		{
		case add:
			AddContact(&con);
			break;
		case del:
			DelContact(&con);
			break;
		case search:
			SearchContact(&con);
			break;
		case modify:
			ModifyContact(&con);
			break;
		case sort:
			sortConcate(&con);
			break;
		case print:
			PrintContact(&con);
			break;
		case Exit:
			DestoryContact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误,重新选择\n");
			break;
		}
	} while (input);
	return 0;
}




#include"contact.h"

void menu()
{
	printf("                                     \n");
	printf("        1. ������ϵ��\t\t\t2. ɾ����ϵ��   \n");
	printf("        3. ������ϵ��\t\t\t4. �޸���Ϣ   \n");
	printf("        5. ��������\t\t\t6. �鿴��Ϣ \n");
	printf("        0. �˳�                        \n");
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
		printf("\n������ѡ��:>");
		scanf("%d", &input);
		char c;//���������������
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
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����,����ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}




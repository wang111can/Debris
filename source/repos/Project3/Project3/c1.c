#define  _CRT_SECURE_NO_WARNINGS
#include"c1.h"

//��Ϸ�˵�
void menu(void)
{
	printf("****************************************\n");
	printf("*****1.��ʼ��Ϸ            0.�˳���Ϸ*****\n");
	printf("****************************************\n");
}

void game(void)
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�ʤ��
		ret = Win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�ʤ��
		ret = Win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}

	if (ret == '*')
	{
		printf("��ϲ��Ӯ����������������������µģ��ҵ��㷨û���κμ�����������ͷ��ͷ��ͷ����\n");
		printf("\n");
	}
	else if (ret == '#')
	{
		printf("�����ˣ��������汿���������Ǹ������ɣ�\n");
		printf("\n");
	}
	else
	{
		printf("ƽ�֣��������汿�����������ԣ�\n");
		printf("\n");
	}
}

void test(void)
{
	srand((unsigned int)time(NULL));

	int input = 0;
	do
	{
		menu();
		printf("\n");
		printf("ϵͳ��ʾ����ѡ��>>>");
		scanf("%d", &input);
		printf("\n");
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("����Ϸ���������ˡ�\n");
			break;
		default:
			printf("���ԣ�FBI warning �Ƿ����룬�Ƿ����룬�����Ծ��㡣\n\n���ԣ��ԣ����������룡����\n");
			break;
		}
	} while (input);
}

int main(void)
{
	test();
	return 0;
}

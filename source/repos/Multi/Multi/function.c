#define  _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()//�˵�
{
	printf("\n");
	printf("       ������      \n");
	printf("\n");
	printf("\n");
	printf("    1.play     2.quit          \n ");
	printf("\n");
	printf("\n");
		
}
void Inita(char arr[ROW][LIST], int  row, int  list)//��ʼ������
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < list; j++)
		{
			arr[i][j]= ' ';
		}
	}
}
void CheckerBoard(char arr[ROW][LIST],int row,int list)//��ӡ����
{	
	for (int i = 0; i < list; i++)
	{
		printf("   %d",i);
	}
	printf("\n");
	for (int i = 0; i < row; i++)
	{
		printf("%2d", i);
		for (int j = 0; j < list; j++)
		{
			printf("%c", arr[i][j]);
			if (j <list - 1)
			{
				printf("  |");
			}
		}
		printf("\n");
		printf(" ");
		for (int j = 0; j < list; j++)
		{
			if (i != row - 1)
				printf(" __");
			
			if (i != row - 1&&j <list -1 )
			
				printf(" |");
			
		}
		printf("\n");
			
	}

}
void PlaOper(char arr[ROW][LIST], int  row, int  list)//��Ҳ���
{
	printf("��Ҳ�����ѡ�����ӵ�:");
	int a = 0, b = 0;
	while (1) {
		scanf("%d %d", &a, &b);
		if (a > row - 1 || b > list - 1||a<0||b<0)
		{
			printf("�����������������:");
			continue;
		}
			
		else if (arr[a][b] == '*' || arr[a][b] == '#')
		{
			printf("�����������ӣ�����������:");
			continue;

		}
		else
		{
			arr[a][b] = '*';
			break;
		}


	}

}
void Complay(char arr[ROW][LIST], int  row, int  list)
{
	
	while (1) {
		int a = rand() % ROW;
		int b = rand() % LIST;
		if (a > row - 1 || b > list - 1 || a < 0 || b < 0)
		{
			
			continue;
		}

		else if (arr[a][b] == '*' || arr[a][b] == '#')
		{
			continue;
		}
		else
		{
			arr[a][b] = '#';
			break;
		}


	}



}
char  Judge(char arr[ROW][LIST], int  row, int  list)
{	
	int i = 0, j = 0, z = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < list; j++)
		{
			for (z = 0; z < CON; z++)
			{
				if (arr[i][j] == arr[i][j + z] && arr[i][j] != ' ')
						;
				else 
					break;
			}
			if (arr[i][j] == arr[i][j + z] && arr[i][j] != ' ')
				return arr[i][j];
		}
	}
}

void game()
{
	char arr[ROW][LIST] = { 0 };
	Inita(arr, ROW, LIST);
	CheckerBoard(arr,ROW,LIST);//��ӡ����
	srand((unsigned int)time(NULL));
	while (1)
	{
		PlaOper(arr, ROW, LIST);//��Ҳ���
		char not=Judge(arr, ROW, LIST);//�ж���Ӯ
		if (not == '*')
		{
			printf("��һ�ʤ\n");
			CheckerBoard(arr, ROW, LIST);//��ӡ����
			break;
		}
		else if (not == '#')
		{
			printf("���Ի�ʤ\n");

			CheckerBoard(arr, ROW, LIST);//��ӡ����
			break;
		}
		else if (not == '1')
		{
			printf("ƽ��\n");
			
			CheckerBoard(arr, ROW, LIST);//��ӡ����
			break;;
		}
		CheckerBoard(arr, ROW, LIST);//��ӡ����
		
		not =Judge(arr, ROW, LIST);//�ж���Ӯ
		if (not  == '*')
		{
			printf("��һ�ʤ\n");
			CheckerBoard(arr, ROW, LIST);//��ӡ����
			break;
		}
		else if (not  == '#')
		{
			printf("���Ի�ʤ\n");
			CheckerBoard(arr, ROW, LIST);//��ӡ����
			break;
		}
		else if (not  == '1')
		{
			printf("ƽ��\n");
			CheckerBoard(arr, ROW, LIST);//��ӡ����
			break;
		}
		Complay(arr, ROW, LIST);//���Բ���
		CheckerBoard(arr, ROW, LIST);//��ӡ����

	}
}
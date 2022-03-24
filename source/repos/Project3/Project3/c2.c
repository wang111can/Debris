#define  _CRT_SECURE_NO_WARNINGS
#include"c1.h"

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < col; i++)
	{
		if (i == 0)
		{
			printf("  %d   ", i + 1);
		}
		else
		{
			printf("%d   ", i + 1);
		}
	}
	printf("\n");

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (j == 0)
			{
				printf("%d %c |", i + 1, board[i][j]);
			}
			else if (j > 0 && j < col - 1)
			{
				printf(" %c |", board[i][j]);
			}
			else
				printf(" %c ", board[i][j]);
		}
		printf("\n");
		if (i < row - 1)
		{

			for (int k = 0; k < col; k++)
			{
				if (k == 0)
				{
					printf(" ---|");
				}
				else if (k > 0 && k < col - 1)
				{
					printf("---|");
				}
				else
				{
					printf("---");
				}
			}
		}
		printf("\n");
	}
}

//�������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("ϵͳ��ʾ����������Ҫ�µ����꣺>>>");

		scanf("%d%d", &x, &y);
		printf("\n");
		//�ж�xy�Ƿ�Ϸ���һ�����Ƿ������һ�����Ƿ�ռ��
		if (x > 0 && x < row + 1 && y>0 && y < col + 1)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("���ԣ����¹��ˣ����������\n");
				printf("\n");

			}
		}
		else
		{
			printf("���ԣ�FBI warning �Ƿ����룬�Ƿ����룡���������Ծ��㡣\n\n���ԣ��ԣ����������룡����\n\n");
		}
	}
}

//��������
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("���ԣ����߹���������������������\n\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//�ж�ʤ��
char Win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//�ж���
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4] && board[i][1] != ' ')//��Ԫ��һ���Ҳ��ǿո�
		{
			return board[i][1];
		}
	}
	//�ж���
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[3][i] == board[4][i] && board[1][i] != ' ')//��Ԫ��һ���Ҳ��ǿո�
		{
			return board[1][i];
		}
	}
	//�ж϶Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4] && board[1][1] != ' ')//�Խ���Ԫ��һ���Ҳ��ǿո�
	{
		return board[1][1];
	}
	if (board[4][0] == board[3][1] && board[3][1] == board[2][2] && board[2][2] == board[1][3] && board[1][3] == board[0][4] && board[2][2] != ' ')
	{
		return board[1][1];
	}
	//�ж��Ƿ�ƽ��
	if (1 == Full(board, ROW, COL))//ƽ���жϣ����������棬����ͷ�ļ���������λ�þ�����ν��
	{
		return 'Q';
	}
	return 'C';
}

//ƽ���㷨����
char Full(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

#define  _CRT_SECURE_NO_WARNINGS
#include"c1.h"

//初始化棋盘
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

//打印棋盘
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

//玩家输入
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("系统提示：请输入您要下的坐标：>>>");

		scanf("%d%d", &x, &y);
		printf("\n");
		//判断xy是否合法，一个是是否溢出，一个是是否被占用
		if (x > 0 && x < row + 1 && y>0 && y < col + 1)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("电脑：这下过了，你个憨憨。\n");
				printf("\n");

			}
		}
		else
		{
			printf("电脑：FBI warning 非法输入，非法输入！！！请您自觉点。\n\n电脑：乖，咱重新输入！！！\n\n");
		}
	}
}

//电脑输入
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑：我走过啦！！！到你啦！！！\n\n");
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

//判断胜负
char Win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//判断行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4] && board[i][1] != ' ')//行元素一样且不是空格
		{
			return board[i][1];
		}
	}
	//判断列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[3][i] == board[4][i] && board[1][i] != ' ')//列元素一样且不是空格
		{
			return board[1][i];
		}
	}
	//判断对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4] && board[1][1] != ' ')//对角线元素一样且不是空格
	{
		return board[1][1];
	}
	if (board[4][0] == board[3][1] && board[3][1] == board[2][2] && board[2][2] == board[1][3] && board[1][3] == board[0][4] && board[2][2] != ' ')
	{
		return board[1][1];
	}
	//判断是否平局
	if (1 == Full(board, ROW, COL))//平局判断，函数在下面，已在头文件中声明，位置就无所谓了
	{
		return 'Q';
	}
	return 'C';
}

//平局算法函数
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

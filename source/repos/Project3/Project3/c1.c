#define  _CRT_SECURE_NO_WARNINGS
#include"c1.h"

//游戏菜单
void menu(void)
{
	printf("****************************************\n");
	printf("*****1.开始游戏            0.退出游戏*****\n");
	printf("****************************************\n");
}

void game(void)
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否胜利
		ret = Win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否胜利
		ret = Win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}

	if (ret == '*')
	{
		printf("恭喜你赢啦！！！（不过我是随机下的，我的算法没有任何技术含量（狗头狗头狗头））\n");
		printf("\n");
	}
	else if (ret == '#')
	{
		printf("你输了！！！你真笨！！！你是个憨憨吧！\n");
		printf("\n");
	}
	else
	{
		printf("平局！！！你真笨！！！略略略！\n");
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
		printf("系统提示：请选择：>>>");
		scanf("%d", &input);
		printf("\n");
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("破游戏，俺不玩了。\n");
			break;
		default:
			printf("电脑：FBI warning 非法输入，非法输入，请您自觉点。\n\n电脑：乖，咱重新输入！！！\n");
			break;
		}
	} while (input);
}

int main(void)
{
	test();
	return 0;
}

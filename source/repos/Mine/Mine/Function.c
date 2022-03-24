#define  _CRT_SECURE_NO_WARNINGS
#include"MineGame.h"




void game()
{
	char mine[ROWS][COLS];                 //扫雷数组
	char show[ROWS][COLS];                 //展示数组
	srand((unsigned int)time(NULL));       //产生随机数
	InitMine(mine, ROWS, COLS);            //初始化的雷盘
	InitShow(show, ROW, COL);              //初始化展示的雷盘
	SetMine(mine, ROW, COL, MINECOUNT);    //随机布雷
	DisplayBoard(show, ROW, COL);          //打印雷盘
	PlayGame(mine, show);                  //主逻辑函数
}

int main()
{
	int input = 0;

	do
	{
		menu();
		printf("请选择是否开始游戏(1/0):>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏退出！");
			break;
		default:
			printf("输入错误！请重新输入：");
			break;
		}
	} while (input);
	return 0;
}

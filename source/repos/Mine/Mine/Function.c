#define  _CRT_SECURE_NO_WARNINGS
#include"MineGame.h"




void game()
{
	char mine[ROWS][COLS];                 //ɨ������
	char show[ROWS][COLS];                 //չʾ����
	srand((unsigned int)time(NULL));       //���������
	InitMine(mine, ROWS, COLS);            //��ʼ��������
	InitShow(show, ROW, COL);              //��ʼ��չʾ������
	SetMine(mine, ROW, COL, MINECOUNT);    //�������
	DisplayBoard(show, ROW, COL);          //��ӡ����
	PlayGame(mine, show);                  //���߼�����
}

int main()
{
	int input = 0;

	do
	{
		menu();
		printf("��ѡ���Ƿ�ʼ��Ϸ(1/0):>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ�˳���");
			break;
		default:
			printf("����������������룺");
			break;
		}
	} while (input);
	return 0;
}

#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS ROW+2
#define COLS COL+2
#define ROW  10
#define COL  10
#define MINECOUNT  10      //�����׵ĸ���

void menu();  //��Ϸ�˵�
void InitMine(char mine[ROWS][COLS], int row, int col);  //��ʼ������
void InitShow(char show[ROWS][COLS], int row, int col);  //��ʼ��չʾ������
void SetMine(char mine[ROWS][COLS], int x, int y, int count);  // �������
void DisplayBoard(char arr[ROWS][COLS], int row, int col);  // ��ӡչʾ����
void ResetMine(char mine[ROWS][COLS], int row, int col);  // ��һ�βȵ��ף����²���
int  GetMineCount(char mine[ROWS][COLS], int i, int j);  //ͳ���׵ĸ���
void expand(char mine[ROWS][COLS], int x, int y, char show[ROWS][COLS], int* p);  //��չ����
void PlayGame(char mine[ROWS][COLS], char show[ROWS][COLS]);  // ���߼�


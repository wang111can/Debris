#define  _CRT_SECURE_NO_WARNINGS
//�궨��
#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 5
#define COL 5

//���ÿ⺯��
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//��������
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
char Win(char board[ROW][COL], int row, int col);
char Full(char board[ROW][COL], int row, int col);

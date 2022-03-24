#define  _CRT_SECURE_NO_WARNINGS
//宏定义
#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 5
#define COL 5

//引用库函数
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//函数声明
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
char Win(char board[ROW][COL], int row, int col);
char Full(char board[ROW][COL], int row, int col);

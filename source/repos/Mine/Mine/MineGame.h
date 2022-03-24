#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS ROW+2
#define COLS COL+2
#define ROW  10
#define COL  10
#define MINECOUNT  10      //布置雷的个数

void menu();  //游戏菜单
void InitMine(char mine[ROWS][COLS], int row, int col);  //初始化雷盘
void InitShow(char show[ROWS][COLS], int row, int col);  //初始化展示的雷盘
void SetMine(char mine[ROWS][COLS], int x, int y, int count);  // 随机布雷
void DisplayBoard(char arr[ROWS][COLS], int row, int col);  // 打印展示雷盘
void ResetMine(char mine[ROWS][COLS], int row, int col);  // 第一次踩到雷，重新布雷
int  GetMineCount(char mine[ROWS][COLS], int i, int j);  //统计雷的个数
void expand(char mine[ROWS][COLS], int x, int y, char show[ROWS][COLS], int* p);  //扩展函数
void PlayGame(char mine[ROWS][COLS], char show[ROWS][COLS]);  // 主逻辑


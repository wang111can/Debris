#define  _CRT_SECURE_NO_WARNINGS
#define ROW 15
#define LIST 15
#define CON 5

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

extern void menu();
extern void game();
extern void CheckerBoard(char arr[ROW][LIST], int row, int list);//´òÓ¡ÆåÅÌ

extern void Inita(char arr[ROW][LIST],int  row,int  list);

extern void PlaOper(char arr[ROW][LIST], int  row, int  list);//Íæ¼Ò²Ù×÷

extern void Complay(char arr[ROW][LIST], int  row, int  list);

extern char Judge(char arr[ROW][LIST], int  row, int  list);

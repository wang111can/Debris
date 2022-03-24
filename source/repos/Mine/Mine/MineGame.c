#define  _CRT_SECURE_NO_WARNINGS
#include"MineGame.h"
#define _CRT_SECURE_NO_WARNINGS 1


void menu()  //��Ϸ�˵�
{
    printf("****************************\n");
    printf("****      ɨ����Ϸ      ****\n");
    printf("****     1.��ʼ��Ϸ     ****\n");
    printf("****     0.�˳���Ϸ     ****\n");
    printf("****************************\n");
}

void InitMine(char mine[ROWS][COLS], int row, int col) // ��ʼ������
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            mine[i][j] = '0';
        }
    }
}

void InitShow(char show[ROWS][COLS], int row, int col) //��ʼ��չʾ������
{
    int i = 0;
    int j = 0;
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= col; j++)
        {
            show[i][j] = '*';
        }
    }
}

void SetMine(char mine[ROWS][COLS], int row, int col, int count) // �������
{
    while (count)
    {
        int x = rand() % row + 1;
        int y = rand() % col + 1;
        mine[x][y] = '1';
        count--;
    }
}

void DisplayBoard(char arr[ROWS][COLS], int row, int col) // ��ӡչʾ����
{
    int i = 0;
    int j = 0;
    printf(" ");
    for (i = 0; i <= row; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 1; i <= row; i++)
    {
        printf("%2d", i);
        for (j = 1; j <= col; j++)
        {
            printf(" %c", arr[i][j]);
        }
        printf("\n");
    }
}

void ResetMine(char mine[ROWS][COLS], int row, int col, int x, int y, int count) // ��һ�βȵ��ף����²���
{
    mine[x][y] = '0';
    while (count)
    {
        int i = rand() % row + 1;
        int j = rand() % col + 1;
        if ((mine[i][j] != '1') && i != x && j != y)
        {
            mine[i][j] = '1';
            count--;
        }
    }
}

int  GetMineCount(char mine[ROWS][COLS], int i, int j)   //ͳ���׵ĸ���
{
    return mine[i - 1][j] +
        mine[i - 1][j - 1] +
        mine[i][j - 1] +
        mine[i + 1][j - 1] +
        mine[i + 1][j] +
        mine[i + 1][j + 1] +
        mine[i][j + 1] +
        mine[i - 1][j + 1] - 8 * '0';
}

void expand(char mine[ROWS][COLS], int x, int y, char show[ROWS][COLS], int* p)    //��չ����
{

    int i = -1;
    int j = -1;
    for (i = -1; i < 2; i++)      //�߽�
    {
        for (j = -1; j < 2; j++)
        {
            if (i != 0 || j != 0)      // �����ŵ��Լ�ע��˴����߼���ϵ
            {
                if (x + i >= 1 && x + i <= ROW && y + j >= 1 && y + j <= COL)     //x y�����Ƿ�Ϸ�
                {
                    if (show[x + i][y + j] == '*' && mine[x + i][y + j] != '1')
                    {

                        int count = GetMineCount(mine, x + i, y + j);
                        if (count != 0)
                        {
                            show[x + i][y + j] = count + '0';
                            (*p)++;
                        }
                        else
                        {
                            show[x + i][y + j] = ' ';
                            (*p)++;
                            expand(mine, x + i, y + j, show, p);
                        }

                    }

                }
            }
        }
    }


}

// ���߼�
void PlayGame(char mine[ROWS][COLS], char show[ROWS][COLS])
{
    int x = 0;
    int y = 0;
    int win = 0;        //ͳ�����׵ĸ���
    int count = 0;     // ͳ���׵ĸ���
    while (win < ROW * COL - count)
    {
        printf("���������꣺>");
        scanf("%d %d", &x, &y);
        if (show[x][y] == count + '0')    //�����ظ�����
        {
            printf("�Ѿ��Ź���\n");
        }
        if (x >= 1 && x <= ROW && y >= 1 && y <= COL)   //���������Ƿ�Ϸ�
        {
            if (mine[x][y] == '1')
            {
                if (0 == win)      //Ϊ����Ϸ���飬��һ�βȵ��ף����²���
                {
                    ResetMine(mine, ROW, COL, x, y, 1);
                    //display(mine, ROW, COL);
                    count = GetMineCount(mine, x, y);

                    if (count == 0)
                    {
                        show[x][y] = ' ';
                        win++;
                        expand(mine, x, y, show, &win);  //�����Χû���ף�������չ
                        DisplayBoard(show, ROW, COL);
                    }
                    else
                    {
                        show[x][y] = count + '0';
                        DisplayBoard(show, ROW, COL);
                    }
                }
                else
                {
                    printf("���ź����㱻ը����\n");
                    DisplayBoard(mine, ROW, COL);
                    break;
                }
            }
            else
            {
                count = GetMineCount(mine, x, y);
                if (count == 0)
                {
                    show[x][y] = ' ';
                }
                else
                {
                    show[x][y] = count + '0';
                }
                win++;
                expand(mine, x, y, show, &win);
                DisplayBoard(show, ROW, COL);
                //display(mine, ROW, COL);
            }
        }

        else
        {
            printf("�������겻�Ϸ�\n");
        }

    }
    if (win == ROW * COL - count)
    {
        printf("���׳ɹ�\n");
        DisplayBoard(mine, ROW, COL);
    }
}

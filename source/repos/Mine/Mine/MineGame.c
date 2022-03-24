#define  _CRT_SECURE_NO_WARNINGS
#include"MineGame.h"
#define _CRT_SECURE_NO_WARNINGS 1


void menu()  //游戏菜单
{
    printf("****************************\n");
    printf("****      扫雷游戏      ****\n");
    printf("****     1.开始游戏     ****\n");
    printf("****     0.退出游戏     ****\n");
    printf("****************************\n");
}

void InitMine(char mine[ROWS][COLS], int row, int col) // 初始化雷盘
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

void InitShow(char show[ROWS][COLS], int row, int col) //初始化展示的雷盘
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

void SetMine(char mine[ROWS][COLS], int row, int col, int count) // 随机布雷
{
    while (count)
    {
        int x = rand() % row + 1;
        int y = rand() % col + 1;
        mine[x][y] = '1';
        count--;
    }
}

void DisplayBoard(char arr[ROWS][COLS], int row, int col) // 打印展示雷盘
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

void ResetMine(char mine[ROWS][COLS], int row, int col, int x, int y, int count) // 第一次踩到雷，重新布雷
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

int  GetMineCount(char mine[ROWS][COLS], int i, int j)   //统计雷的个数
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

void expand(char mine[ROWS][COLS], int x, int y, char show[ROWS][COLS], int* p)    //扩展函数
{

    int i = -1;
    int j = -1;
    for (i = -1; i < 2; i++)      //边界
    {
        for (j = -1; j < 2; j++)
        {
            if (i != 0 || j != 0)      // 避免排到自己注意此处的逻辑关系
            {
                if (x + i >= 1 && x + i <= ROW && y + j >= 1 && y + j <= COL)     //x y坐标是否合法
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

// 主逻辑
void PlayGame(char mine[ROWS][COLS], char show[ROWS][COLS])
{
    int x = 0;
    int y = 0;
    int win = 0;        //统计排雷的个数
    int count = 0;     // 统计雷的个数
    while (win < ROW * COL - count)
    {
        printf("请输入坐标：>");
        scanf("%d %d", &x, &y);
        if (show[x][y] == count + '0')    //避免重复排雷
        {
            printf("已经排过雷\n");
        }
        if (x >= 1 && x <= ROW && y >= 1 && y <= COL)   //输入坐标是否合法
        {
            if (mine[x][y] == '1')
            {
                if (0 == win)      //为了游戏体验，第一次踩到雷，重新布雷
                {
                    ResetMine(mine, ROW, COL, x, y, 1);
                    //display(mine, ROW, COL);
                    count = GetMineCount(mine, x, y);

                    if (count == 0)
                    {
                        show[x][y] = ' ';
                        win++;
                        expand(mine, x, y, show, &win);  //如果周围没有雷，进行扩展
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
                    printf("很遗憾，你被炸死了\n");
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
            printf("输入坐标不合法\n");
        }

    }
    if (win == ROW * COL - count)
    {
        printf("排雷成功\n");
        DisplayBoard(mine, ROW, COL);
    }
}

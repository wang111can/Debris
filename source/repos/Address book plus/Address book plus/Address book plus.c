#define  _CRT_SECURE_NO_WARNINGS
#include"project.h"
int main()
{
	int a = 0;
	PeopleColl con;
	Initial(&con);//初始化
	do {
		menu();
		printf("请选择：");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			ADDITION(&con);//增加联系人
			Check(con);
			break;
		case 2:
			Delete(&con);//删除信息
			break;
		case 3:
			SEEK(&con);//查找指定人的信息
			break;
		case 4:
			Revise(&con);//修改信息
			break;
		case 5:
			Check(con);//查看通讯录
			break;
		case 0: StoreIfor(&con);
			Freed(&con);//释放通讯录
			break;
		default :
			printf("选择错误，重新输入\n");
			break;
		}
	} while (a);
	return 0;

}
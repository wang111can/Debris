#define  _CRT_SECURE_NO_WARNINGS
#include"game.h"
int main()
{	
	int a = 0;
	do {
		menu();
		printf("请选择: ");
		scanf("%d", &a);
		switch (a) {
		case 1:
			game();
			break;
		case 0:
			printf("下次再见\n");
			break;
		default :
			printf("请重新输入\n");
			break;
		}

	} while (a);
	return 0;
}
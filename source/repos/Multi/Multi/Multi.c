#define  _CRT_SECURE_NO_WARNINGS
#include"game.h"
int main()
{	
	int a = 0;
	do {
		menu();
		printf("��ѡ��: ");
		scanf("%d", &a);
		switch (a) {
		case 1:
			game();
			break;
		case 0:
			printf("�´��ټ�\n");
			break;
		default :
			printf("����������\n");
			break;
		}

	} while (a);
	return 0;
}
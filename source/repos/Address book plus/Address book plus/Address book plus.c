#define  _CRT_SECURE_NO_WARNINGS
#include"project.h"
int main()
{
	int a = 0;
	PeopleColl con;
	Initial(&con);//��ʼ��
	do {
		menu();
		printf("��ѡ��");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			ADDITION(&con);//������ϵ��
			Check(con);
			break;
		case 2:
			Delete(&con);//ɾ����Ϣ
			break;
		case 3:
			SEEK(&con);//����ָ���˵���Ϣ
			break;
		case 4:
			Revise(&con);//�޸���Ϣ
			break;
		case 5:
			Check(con);//�鿴ͨѶ¼
			break;
		case 0: StoreIfor(&con);
			Freed(&con);//�ͷ�ͨѶ¼
			break;
		default :
			printf("ѡ�������������\n");
			break;
		}
	} while (a);
	return 0;

}
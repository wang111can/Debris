#define  _CRT_SECURE_NO_WARNINGS

#include"ADD.h"


void menu()//�˵�
{
	printf("_____________________________\n");
	printf("|                            | \n");
	printf("|                            | \n");
	printf("|  1.������Ϣ    2.ɾ����Ϣ  |\n");
	printf("|  3.������Ϣ    4.�޸���Ϣ  |\n");
	printf("|           5.�鿴           | \n");
	printf("|           0.�˳�           | \n");
	printf("|                            | \n");
	printf("|----------------------------|\n");


}
//����
void Congestion(PeopleColl* con)
{
	if (con->sz == con->capacity)
	{


		PeopleInfor* p = (PeopleInfor*)realloc(con->date, (con->capacity + VALUE) * sizeof(PeopleInfor));

		if (con->date == NULL)
		{
			perror("Congestion");
			printf("����ʧ��\n");
			return;
		}
		else
		{
			con->date = p;
			con->capacity += VALUE;
			printf("���ݳɹ�\n");
		}

	}

}




//��ȡ��Ϣ
void ReadIfor(PeopleColl* con)
{
	FILE* ptr = fopen("AddBook.dat", "rb");
	if (ptr == NULL)
	{
		perror("ReadIfor");
		printf("��ȡʧ��\n");
		return;
	}
	else {
		PeopleInfor mat = { 0 };
		while (fread(&mat, sizeof(PeopleInfor), 1, ptr))
		{
			Congestion(con);
			con->date[con->sz] = mat;
			con->sz++;

		}
	}

}



//������Ϣ���ļ�
void StoreIfor(PeopleColl* con)
{
	FILE* p = fopen("AddBook.dat", "wb");
	if (p == NULL)
	{
		perror("StoreIfor");
		printf("�洢ʧ��\n");
		return;
	}
	//�洢�ļ�
	int i = 0;
	for (i = 0; i < con->sz; i++)
	{
		fwrite(con->date + i, sizeof(PeopleInfor), 1, p);

	}

	printf("�洢�ɹ�\n");
	//�ر��ļ�
	//�ͷ�ָ������ڴ�й¶
	fclose(p);
	p = NULL;
}






//��ʼ��
void Initial(PeopleColl* con)
{
	
	con->date = (PeopleInfor*)calloc(DOUBLE_SZ, sizeof(PeopleInfor));
	if (con->date == NULL)
	{
		perror("Initial");
		return;
	}
	con->sz = 0;
	con->capacity = DOUBLE_SZ;
	ReadIfor(con);
}


//������Ϣ
void ADDITION(PeopleColl* con)
{
	Congestion(con);

	printf("����������:\n");
	scanf("%s", con->date[con->sz].name);
	printf("�������Ա�:\n");
	scanf("%s", con->date[con->sz].sex);
	printf("�������ַ:\n");
	scanf("%s", con->date[con->sz].add);
	printf("���������:\n");
	scanf("%s", &(con->date[con->sz].num));
	printf("����������:\n");
	scanf("%d", &(con->date[con->sz].age));
	con->sz++;
	printf("¼��ɹ�\n");
}


//С����
int  Seek(const PeopleColl* con, char arr[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < con->sz; i++)
	{
		if (strcmp(con->date[i].name, arr) == 0)
			return i;
	}
	return -1;

}


//ɾ����Ϣ
void Delete(PeopleColl* con)
{
	if (con->sz == 0) {
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	char arr[MAX_NAME] = { 0 };
	printf("������Ҫɾ���˵�����:\n");
	scanf("%s", arr);
	int p = Seek(con, arr);
	if (p == -1) {
		printf("ɾ�����˲�����\n");

	}
	else
	{
		int i = 0;
		for (i = p; i < con->sz - 1; i++) {
			con->date[i] = con->date[i + 1];
		}
		con->sz--;
		printf("ɾ���ɹ�\n");
	}


}


//����ָ���˵���Ϣ
void SEEK(PeopleColl* con)
{

	if (con->sz == 0) {
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	char arr[MAX_NAME] = { 0 };
	printf("������Ҫ�����˵�����:\n");
	scanf("%s", arr);
	int p = Seek(con, arr);
	if (p == -1) {
		printf("���ҵ��˲�����\n");

	}
	else
	{
		printf("�����˵���ϢΪ:\n");
		printf("%-10s %-10s %-20s %-20s %-10s\n", "����", "�Ա�", "��ַ", "����", "����");
		printf("%-10s %-10s %-20s %-20s %-10d\n", con->date[p].name,
			con->date[p].sex,
			con->date[p].add,
			con->date[p].num,
			con->date[p].age);
	}

}




//�޸���Ϣ
void Revise(PeopleColl* con)
{
	if (con->sz == 0) {
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	char arr[MAX_NAME] = { 0 };
	printf("������Ҫ�޸��˵�����:\n");
	scanf("%s", arr);
	int p = Seek(con, arr);
	if (p == -1) {
		printf("�޸ĵ��˲�����\n");

	}
	else {
		printf("����������:\n");
		scanf("%s", con->date[p].name);
		printf("�������Ա�:\n");
		scanf("%s", con->date[p].sex);
		printf("�������ַ:\n");
		scanf("%s", con->date[p].add);
		printf("���������:\n");
		scanf("%s", &(con->date[p].num));
		printf("����������:\n");
		scanf("%d", &(con->date[p].age));
		printf("�޸ĳɹ�\n");

	}
}


//�鿴��Ϣ
void Check(PeopleColl con)
{
	if (con.sz == 0) {
		printf("����¼����Ϣ\n");
	}

	int i = 0;
	printf("%-10s %-10s %-20s %-20s %-10s\n", "����", "�Ա�", "��ַ", "����", "����");
	for (i = 0; i < con.sz; i++)
	{
		printf("%-10s %-10s %-20s %-20s %-10d\n", con.date[i].name,
			con.date[i].sex,
			con.date[i].add,
			con.date[i].num,
			con.date[i].age);


	}
}


//�ͷ�
void Freed(PeopleColl* con)
{
	free(con->date);
	con->date = NULL;
	con->capacity = 0;
	con->sz = 0;
}
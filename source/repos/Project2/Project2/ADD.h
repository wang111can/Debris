#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_NAME 10
#define MAX_ADD 20
#define MAX_SEX 5
#define MAX_NUM 15


#define VALUE 2
#define DOUBLE_SZ 3
typedef struct PeopleInfor
{
	char name[MAX_NAME];//����
	char add[MAX_ADD];//סַ
	char sex[MAX_SEX];//�Ա�
	char num[MAX_NUM];//�绰����
	int age;//����


}PeopleInfor;
//�ϼ�
typedef struct PeopleColl
{
	PeopleInfor* date;//����ĳ�ָ��
	int sz;
	int capacity;
}PeopleColl;


//�˵�
extern void menu();

//��ʼ��
extern void Initial(PeopleColl* con);


//������Ϣ
extern  void ADDITION(PeopleColl* con);


//ɾ����Ϣ
extern void Delete(PeopleColl* con);


//����ָ���˵���Ϣ
extern void SEEK(PeopleColl* con);

//�޸���Ϣ
extern  void Revise(PeopleColl* con);

//�鿴��Ϣ
extern void Check(PeopleColl con);


//�ͷ�ͨѶ¼
extern void Freed(PeopleColl* con);


//������Ϣ���ļ�
extern void StoreIfor(PeopleColl* con);

//��ȡ��Ϣ
extern void ReadIfor(PeopleColl* con);
extern void Congestion(PeopleColl* con);
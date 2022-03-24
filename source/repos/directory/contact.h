#pragma once

#define _CRT_SECURE_NO_WARNINGS 
#pragma warning(MSBuild:802)

#define MAX_NAME 20
#define MAX_SEX 2
#define MAX_TELE 15
#define MAX_ADDR 30
#define DEFAULT_SZ 3
#define INC_SZ 2


#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>



//���͵Ķ���
typedef struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

typedef struct Contact
{
	PeoInfo* data;//ָ��̬����Ŀռ䣬���������ϵ�˵���Ϣ
	int sz;//��¼���ǵ�ǰͨѶ¼����Ч��Ϣ�ĸ���
	int capacity;//��¼��ǰͨѶ¼���������
}Contact;


//��ʼ��ͨѶ¼
void InitContact(Contact* pc);

//������ϵ��
void AddContact(Contact* pc);

//��ӡ��ϵ����Ϣ
void PrintContact(const Contact* pc);

//ɾ����ϵ�˵���Ϣ
void DelContact(Contact* pc);

//����ָ����ϵ��
void SearchContact(const Contact* pc);

//�޸�ָ����ϵ��
void ModifyContact(Contact* pc);

//������ݵ�����
void CheckCapacity(Contact* pc);

//����ͨѶ¼
void DestoryContact(Contact* pc);


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



//类型的定义
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
	PeoInfo* data;//指向动态申请的空间，用来存放联系人的信息
	int sz;//记录的是当前通讯录中有效信息的个数
	int capacity;//记录当前通讯录的最大容量
}Contact;


//初始化通讯录
void InitContact(Contact* pc);

//增加联系人
void AddContact(Contact* pc);

//打印联系人信息
void PrintContact(const Contact* pc);

//删除联系人的信息
void DelContact(Contact* pc);

//查找指定联系人
void SearchContact(const Contact* pc);

//修改指定联系人
void ModifyContact(Contact* pc);

//检测增容的问题
void CheckCapacity(Contact* pc);

//销毁通讯录
void DestoryContact(Contact* pc);


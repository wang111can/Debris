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
	char name[MAX_NAME];//名字
	char add[MAX_ADD];//住址
	char sex[MAX_SEX];//性别
	char num[MAX_NUM];//电话号码
	int age;//年龄


}PeopleInfor;
//合集
typedef struct PeopleColl
{
	PeopleInfor* date;//必须改成指针
	int sz;
	int capacity;
}PeopleColl;


//菜单
extern void menu();

//初始化
extern void Initial(PeopleColl* con);


//增加信息
extern  void ADDITION(PeopleColl* con);


//删除信息
extern void Delete(PeopleColl* con);


//查找指定人的信息
extern void SEEK(PeopleColl* con);

//修改信息
extern  void Revise(PeopleColl* con);

//查看信息
extern void Check(PeopleColl con);


//释放通讯录
extern void Freed(PeopleColl* con);


//储存信息到文件
extern void StoreIfor(PeopleColl* con);

//读取信息
extern void ReadIfor(PeopleColl* con);
extern void Congestion(PeopleColl* con);
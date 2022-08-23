#pragma once


#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30



#include <stdio.h>
#include <stdlib.h>
#include <string.h>



enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
};



struct PeoInfo//个人信息类型
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};



struct Contact//通讯录信息类型
{
	struct PeoInfo data[MAX];
	int size;//记录当前已有的数据个数
};



void InitContact(struct Contact* ps);//初始化通讯录
void AddContact(struct Contact* ps);//增加联系人信息
void ShowContact(const struct Contact* ps);//显示联系人信息
void DelContact(struct Contact* ps);//删除指定联系人的信息
void SearchContact(const struct Contact* ps);//查找指定的人的信息
void ModifyContact(const struct Contact* ps);//修改指定的人的信息
void SortContact(struct Contact* ps);//排序整个通讯录
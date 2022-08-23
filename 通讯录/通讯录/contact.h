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



struct PeoInfo//������Ϣ����
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};



struct Contact//ͨѶ¼��Ϣ����
{
	struct PeoInfo data[MAX];
	int size;//��¼��ǰ���е����ݸ���
};



void InitContact(struct Contact* ps);//��ʼ��ͨѶ¼
void AddContact(struct Contact* ps);//������ϵ����Ϣ
void ShowContact(const struct Contact* ps);//��ʾ��ϵ����Ϣ
void DelContact(struct Contact* ps);//ɾ��ָ����ϵ�˵���Ϣ
void SearchContact(const struct Contact* ps);//����ָ�����˵���Ϣ
void ModifyContact(const struct Contact* ps);//�޸�ָ�����˵���Ϣ
void SortContact(struct Contact* ps);//��������ͨѶ¼
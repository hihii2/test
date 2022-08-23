#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"



void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}



void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("通讯录已满，无法增加\n");
	}
	else
	{
		printf("请输入名字: ");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄: ");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别: ");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话: ");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址: ");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("添加成功\n");
	}
}



void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}



static int FindByName(const struct Contact* ps, char name[MAX_NAME])//找到返回下标，找不到返回-1
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
			return i;
	}
	return -1;
}



void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除人的名字: ");
	scanf("%s", name);
	int ret = FindByName(ps, name);
	if (ret == -1)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		int j = 0;
		for (j = ret; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}



void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找人的名字: ");
	scanf("%s", name);
	int ret = FindByName(ps, name);
	if (ret == -1)
	{
		printf("要查找的人不存在\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[ret].name,
			ps->data[ret].age,
			ps->data[ret].sex,
			ps->data[ret].tele,
			ps->data[ret].addr);
	}
}



void ModifyContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改的人的名字: ");
	scanf("%s", name);
	int ret = FindByName(ps, name);
	if (ret == -1)
	{
		printf("要修改的人不存在\n");
	}
	else
	{
		printf("请输入名字: ");
		scanf("%s", ps->data[ret].name);
		printf("请输入年龄: ");
		scanf("%d", &(ps->data[ret].age));
		printf("请输入性别: ");
		scanf("%s", ps->data[ret].sex);
		printf("请输入电话: ");
		scanf("%s", ps->data[ret].tele);
		printf("请输入地址: ");
		scanf("%s", ps->data[ret].addr);
		printf("修改成功\n");
	}
}



int Sort_By_Name(const void* e1, const void* e2)//用名字比较
{
	return strcmp(((struct Contact*)e1)->data->name, ((struct Contact*)e2)->data->name);
}



int Sort_By_Age(const void* e1, const void* e2)//用年龄比较
{
	return ((struct Contact*)e1)->data->age - ((struct Contact*)e2)->data->age;
}



void MethodChoose()//选择排序方法
{
	printf("#######################################################################################################################\n");
	printf("########################################         1. Name        2. Age         ########################################\n");
	printf("########################################                0. exit                ########################################\n");
	printf("#######################################################################################################################\n");
}



void SortContact(struct Contact* ps)
{
	int input = 0;
	int (*pfarr[])(const void* , const void* ) = { 0,Sort_By_Name ,Sort_By_Age };
	int sz = sizeof(pfarr) / sizeof(pfarr[0]);
	do
	{
		MethodChoose();
		printf("请选择: ");
		scanf("%d", &input);
		if (input > 0 && input < sz)
		{
			qsort(ps, ps->size, sizeof(ps->data[0]), pfarr[input]);
			printf("排序成功\n");
			system("pause");
			break;
		}
		else if (input == 0)
		{
			system("cls");
			printf("您已退出排序\n");
			system("pause");
		}
		else
		{
			printf("选择错误,请重新选择\n");
			system("pause");
			system("cls");
		}
	} while (input);
}
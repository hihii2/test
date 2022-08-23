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
		printf("ͨѶ¼�������޷�����\n");
	}
	else
	{
		printf("����������: ");
		scanf("%s", ps->data[ps->size].name);
		printf("����������: ");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�: ");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰: ");
		scanf("%s", ps->data[ps->size].tele);
		printf("�������ַ: ");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("��ӳɹ�\n");
	}
}



void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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



static int FindByName(const struct Contact* ps, char name[MAX_NAME])//�ҵ������±꣬�Ҳ�������-1
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
	printf("������Ҫɾ���˵�����: ");
	scanf("%s", name);
	int ret = FindByName(ps, name);
	if (ret == -1)
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else
	{
		int j = 0;
		for (j = ret; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}



void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�����˵�����: ");
	scanf("%s", name);
	int ret = FindByName(ps, name);
	if (ret == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	printf("������Ҫ�޸ĵ��˵�����: ");
	scanf("%s", name);
	int ret = FindByName(ps, name);
	if (ret == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
	}
	else
	{
		printf("����������: ");
		scanf("%s", ps->data[ret].name);
		printf("����������: ");
		scanf("%d", &(ps->data[ret].age));
		printf("�������Ա�: ");
		scanf("%s", ps->data[ret].sex);
		printf("������绰: ");
		scanf("%s", ps->data[ret].tele);
		printf("�������ַ: ");
		scanf("%s", ps->data[ret].addr);
		printf("�޸ĳɹ�\n");
	}
}



int Sort_By_Name(const void* e1, const void* e2)//�����ֱȽ�
{
	return strcmp(((struct Contact*)e1)->data->name, ((struct Contact*)e2)->data->name);
}



int Sort_By_Age(const void* e1, const void* e2)//������Ƚ�
{
	return ((struct Contact*)e1)->data->age - ((struct Contact*)e2)->data->age;
}



void MethodChoose()//ѡ�����򷽷�
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
		printf("��ѡ��: ");
		scanf("%d", &input);
		if (input > 0 && input < sz)
		{
			qsort(ps, ps->size, sizeof(ps->data[0]), pfarr[input]);
			printf("����ɹ�\n");
			system("pause");
			break;
		}
		else if (input == 0)
		{
			system("cls");
			printf("�����˳�����\n");
			system("pause");
		}
		else
		{
			printf("ѡ�����,������ѡ��\n");
			system("pause");
			system("cls");
		}
	} while (input);
}
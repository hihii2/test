#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void menu()
{
	printf("#######################################################################################################################\n");
	printf("########################################         1. Add         2. Del         ########################################\n");
	printf("########################################         3. Search      4. Modify      ########################################\n");
	printf("########################################         5. Show        6. Sort        ########################################\n");
	printf("########################################                0. exit                ########################################\n");
	printf("#######################################################################################################################\n");
}
//���ӣ�ɾ�������ң��޸ģ���ʾ������

int main()
{
	int input = 0;
	struct Contact con;
	InitContact(&con);
	do
	{
		menu();
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			system("cls");
			AddContact(&con);
			system("pause");
			system("cls");
			break;
		case DEL:
			system("cls");
			DelContact(&con);
			system("pause");
			system("cls");
			break;
		case SEARCH:
			system("cls");
			SearchContact(&con);
			system("pause");
			system("cls");
			break;
		case MODIFY:
			system("cls");
			ModifyContact(&con);
			system("pause");
			system("cls");
			break;
		case SHOW:
			system("cls");
			ShowContact(&con);
			system("pause");
			system("cls");
			break;
		case SORT:
			system("cls");
			SortContact(&con);
			system("cls");
			break;
		case EXIT:
			system("cls");
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����,������ѡ��\n");
			system("pause");
			system("cls");
			break;
		}
	} while (input);
	return 0;
}
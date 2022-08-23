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
//增加，删除，查找，修改，显示，排序

int main()
{
	int input = 0;
	struct Contact con;
	InitContact(&con);
	do
	{
		menu();
		printf("请选择:");
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
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误,请重新选择\n");
			system("pause");
			system("cls");
			break;
		}
	} while (input);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


void menu()//起始菜单
{
	printf("****************************************************\n");
	printf("*******************   1.  pve    *******************\n");
	printf("*******************   2.  pvp    *******************\n");
	printf("*******************   0.  exit   *******************\n");
	printf("****************************************************\n");
}

void choose()//选择先手
{
	printf("****************************************************\n");
	printf("*****************   1.  玩家先手   *****************\n");
	printf("*****************   2.  电脑先手   *****************\n");
	printf("*****************   0.  退出页面   *****************\n");
	printf("****************************************************\n");
}

void test()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			pve();
			break;
		case 2:
			system("cls");
			pvp();
			break;
		case 0:
			Sleep(500);
			system("cls");
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			Sleep(1000);
			system("cls");
			break;
		}
	} while (input);
}

int main()
{
	srand((unsigned int)time(NULL));
	test();
	return 0;
}
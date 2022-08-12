#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

void menu()
{
	printf("#######################################################################################################################\n");
	printf("#######################################################################################################################\n");
	printf("#########################################         1. play     0. exit        ##########################################\n");
	printf("#######################################################################################################################\n");
	printf("#######################################################################################################################\n");
}

void game()
{
	int r = 0;
	int guess = 0;
	int i = 1;
	r = rand()%100+1;
	printf("请在8次内猜出数字1~100");
	Sleep(1500);
	system("cls");
	while (i <= 8)
	{
		printf("请输入数字>:");
		scanf("%d", &guess);
		if (guess < r)
		{
			printf("猜小了，剩余%d次\n", 8 - i);
		}
		else if (guess > r)
		{
			printf("猜大了，剩余%d次\n", 8 - i);
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
		i++;
	}
	if(i>8)
	printf("抱歉，8次机会已用光\n");
}



int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	char password[20] = { 0 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码:>");
		scanf("%s", password);
		if (strcmp(password, "123456") == 0)
		{
			printf("登录成功\n");
			Sleep(1500);
			system("cls");
			do
			{
				menu();
				printf(" \n \n");
				printf("      请选择>:");
				scanf("%d", &input);
				switch (input)
				{
				case 1:
					system("cls");
					game();
					Sleep(1500);
					system("cls");
					break;
				case 0:
					system("cls");
					printf("退出游戏\n");
					break;
				default:
					printf("选择错误,请重新输入\n");
					Sleep(500);
					system("cls");
					break;
				}
			} while (input);
			break;
		}
		else
		{
			printf("密码错误\n");
			Sleep(1000);
			system("cls");
		}
	}
	if (i == 3)
		printf("三次密码均错误，退出程序\n");

	return 0;
}
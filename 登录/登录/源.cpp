#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
#include<Windows.h>

int main()
{
	char password[20] = {0};
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码:>");
		scanf("%s", password);
		if (strcmp(password, "123456") == 0)
		{
			printf("登录成功\n");
			Sleep(800);
			system("cls");
			break;
		}
		else
		{
			printf("密码错误\n");
			Sleep(800);
			system("cls");
		}
	}
	if (i == 3)
		printf("三次密码均错误，退出程序\n");
	return 0;
}
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
		printf("����������:>");
		scanf("%s", password);
		if (strcmp(password, "123456") == 0)
		{
			printf("��¼�ɹ�\n");
			Sleep(800);
			system("cls");
			break;
		}
		else
		{
			printf("�������\n");
			Sleep(800);
			system("cls");
		}
	}
	if (i == 3)
		printf("��������������˳�����\n");
	return 0;
}
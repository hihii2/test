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
	printf("����8���ڲ³�����1~100");
	Sleep(1500);
	system("cls");
	while (i <= 8)
	{
		printf("����������>:");
		scanf("%d", &guess);
		if (guess < r)
		{
			printf("��С�ˣ�ʣ��%d��\n", 8 - i);
		}
		else if (guess > r)
		{
			printf("�´��ˣ�ʣ��%d��\n", 8 - i);
		}
		else
		{
			printf("��ϲ�㣬�¶���\n");
			break;
		}
		i++;
	}
	if(i>8)
	printf("��Ǹ��8�λ������ù�\n");
}



int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	char password[20] = { 0 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("����������:>");
		scanf("%s", password);
		if (strcmp(password, "123456") == 0)
		{
			printf("��¼�ɹ�\n");
			Sleep(1500);
			system("cls");
			do
			{
				menu();
				printf(" \n \n");
				printf("      ��ѡ��>:");
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
					printf("�˳���Ϸ\n");
					break;
				default:
					printf("ѡ�����,����������\n");
					Sleep(500);
					system("cls");
					break;
				}
			} while (input);
			break;
		}
		else
		{
			printf("�������\n");
			Sleep(1000);
			system("cls");
		}
	}
	if (i == 3)
		printf("��������������˳�����\n");

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


void menu()//��ʼ�˵�
{
	printf("****************************************************\n");
	printf("*******************   1.  pve    *******************\n");
	printf("*******************   2.  pvp    *******************\n");
	printf("*******************   0.  exit   *******************\n");
	printf("****************************************************\n");
}

void choose()//ѡ������
{
	printf("****************************************************\n");
	printf("*****************   1.  �������   *****************\n");
	printf("*****************   2.  ��������   *****************\n");
	printf("*****************   0.  �˳�ҳ��   *****************\n");
	printf("****************************************************\n");
}

void test()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
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
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
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
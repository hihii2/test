#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

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
	char ret = 0;
	char board[ROW][COL] = { 0 };
	initboard(board, ROW, COL);
	displayboard(board, ROW, COL);
	while (1)
	{
		player1move(board, ROW, COL);
		displayboard(board, ROW, COL);
		ret = iswin(board, ROW, COL);//@Ϊ�������ʤ����#Ϊ�������ʤ����FΪ����������CΪ����
		if (ret != 'C')
		{
			break;
		}
		player2move(board, ROW, COL);
		displayboard(board, ROW, COL);
		ret = iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '@')
	{
		printf("1�����ʤ��\n");
		system("pause");
		system("cls");
	}
	else if (ret == '#')
	{
		printf("2�����ʤ��\n");
		system("pause");
		system("cls");
	}
	else
	{
		printf("˫��ƽ��\n");
		system("pause");
		system("cls");
	}
}


void test()
{
	int input = 0;
	do
	{
		menu();
		printf("������:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			game();
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
	test();
	return 0;
}
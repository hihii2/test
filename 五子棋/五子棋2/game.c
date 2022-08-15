#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


void initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = '+';
		}
	}
}


void displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	system("cls");
	printf("  ");
	for (j = 0; j < col; j++)
	{
		printf("%-2d", j + 1);
	}
	printf("\n");
	for (i = 0; i < row; i++)
	{
		printf("%-2d", i + 1);
		for (j = 0; j < col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void player1move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		displayboard(board, ROW, COL);
		printf("请1号玩家输入横纵坐标：");
		scanf("%d%d", &y, &x);//x,y互换，确保数组在打印时对应为横纵坐标
		if (x - 1 >= 0 && x - 1 < row && y - 1 >= 0 && y - 1 < col)
		{
			if (board[x - 1][y - 1] == '+')
			{
				board[x - 1][y - 1] = '@';
				break;
			}
			else
			{
				printf("该坐标已被占用，请重新输入\n");
				system("pause");
				system("cls");
			}
		}
		else
		{
			printf("该坐标超出范围，请重新输入\n");
			system("pause");
			system("cls");
		}
	}
}

void player2move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		displayboard(board, ROW, COL);
		printf("请2号玩家输入横纵坐标：");
		scanf("%d%d", &y, &x);
		if (x - 1 >= 0 && x - 1 < row && y - 1 >= 0 && y - 1 < col)
		{
			if (board[x - 1][y - 1] == '+')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else
			{
				printf("该坐标已被占用，请重新输入\n");
				system("pause");
				system("cls");
			}
		}
		else
		{
			printf("该坐标超出范围，请重新输入\n");
			system("pause");
			system("cls");
		}
	}
}

int isfull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == '+')
				return 0;
		}
	}
	return 1;
}

char iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3] && board[i][j] == board[i][j + 4] && board[i][j] != '+')
			return board[i][j];
		}
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j] && board[i][j] == board[i + 4][j] && board[i][j] != '+')
			return board[i][j];
		}
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3] && board[i][j] == board[i + 4][j + 4] && board[i][j] != '+')
			return board[i][j];
		}
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2] && board[i][j] == board[i - 3][j + 3] && board[i][j] == board[i - 4][j + 4] && board[i][j] != '+')
			return board[i][j];
		}
	}
	if (isfull(board, ROW, COL) == 1)
	{
		return 'F';
	}
	return 'C';
}
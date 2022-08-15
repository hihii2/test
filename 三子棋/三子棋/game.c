#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)//初始化棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)//放置棋盘
{
	int i = 0;
	int j = 0;
	system("cls");//防止棋盘前先删除原有旧棋盘
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");//打印棋盘格
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");//打印分隔行
		}
	}
}

void pve_PlayerMove(char board[ROW][COL], int row, int col)//玩家落子
{
	int x = 0;
	int y = 0;
	while (1)
	{
		DisplayBoard(board, ROW, COL);
		printf("玩家走\n");
		printf("请输入坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//检测坐标合法性
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				Sleep(500);
				break;
			}
			else
			{
				printf("该坐标被占用,请重新输入\n");
				Sleep(1000);
				system("cls");
			}
		}
		else
		{
			printf("该坐标超出范围，请重新输入\n");
			Sleep(1000);
			system("cls");
		}
	}
}

void pvp_PlayerMove(char board[ROW][COL], int row, int col, int i)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		DisplayBoard(board, ROW, COL);
		printf("玩家%d走\n", i);
		printf("请输入坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' '&&i==1)//玩家1
			{
				board[x - 1][y - 1] = '*';
				Sleep(500);
				break;
			}
			else if (board[x - 1][y - 1] == ' '&&i == 2)//玩家2
			{
				board[x - 1][y - 1] = '#';
				Sleep(500);
				break;
			}
			else
			{
				printf("该坐标被占用,请重新输入\n");
				Sleep(1000);
				system("cls");
			}
		}
		else
		{
			printf("该坐标超出范围，请重新输入\n");
			Sleep(1000);
			system("cls");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	DisplayBoard(board, ROW, COL);
	printf("电脑走\n");
	Sleep(1000);
	while (1)
	{
		x = rand() % row;//生成随机坐标
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			Sleep(500);
			break;
		}
	}
}

int IsFull(char board[ROW][COL], int row, int col)//判断棋盘是否填满
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col)//判断三子棋是否有一方赢
{
	int i = 0;
	for (i = 0; i < row; i++)//横三
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	for (i = 0; i < col; i++)//竖三
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
	}
		if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')//斜三
			return board[0][0];
		if (board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[2][0] != ' ')
			return board[0][0];
		if (1 == IsFull(board, ROW, COL))//棋盘填满
		{
			return 'Q';
		}
		return 'C';
}

void game1()//人机：玩家先手
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	while (1)
	{
		pve_PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
		Sleep(1500);
		system("cls");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
		Sleep(1500);
		system("cls");
	}
	else
	{
		printf("平局\n");
		Sleep(1500);
		system("cls");
	}
}

void game2()//人机：电脑先手
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	while (1)
	{
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		pve_PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
		Sleep(1500);
		system("cls");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
		Sleep(1500);
		system("cls");
	}
	else
	{
		printf("平局\n");
		Sleep(1500);
		system("cls");
	}
}

void pvp()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	while (1)
	{
		pvp_PlayerMove(board, ROW, COL, 1);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		pvp_PlayerMove(board, ROW, COL, 2);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家1赢\n");
		Sleep(1500);
		system("cls");
	}
	else if (ret == '#')
	{
		printf("玩家2赢\n");
		Sleep(1500);
		system("cls");
	}
	else
	{
		printf("平局\n");
		Sleep(1500);
		system("cls");
	}
}

void pve()
{
	char ret = 0;
	int ch = 0;
	do
	{
		choose();
		printf("请选择:>");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			game1();//玩家先手
			break;
		case 2:
			game2();//电脑先手
			break;
		case 0:
			system("cls");//退出游戏
			break;
		default:
			printf("输入错误，请重新输入\n");
			Sleep(1000);
			system("cls");
			break;
		}
	} while (ch);
}

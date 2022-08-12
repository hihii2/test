#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)//��ʼ������
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

void DisplayBoard(char board[ROW][COL], int row, int col)//��������
{
	int i = 0;
	int j = 0;
	system("cls");//��ֹ����ǰ��ɾ��ԭ�о�����
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");//��ӡ���̸�
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");//��ӡ�ָ���
		}
	}
}

void pve_PlayerMove(char board[ROW][COL], int row, int col)//�������
{
	int x = 0;
	int y = 0;
	while (1)
	{
		DisplayBoard(board, ROW, COL);
		printf("�����\n");
		printf("����������:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//�������Ϸ���
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				Sleep(500);
				break;
			}
			else
			{
				printf("�����걻ռ��,����������\n");
				Sleep(1000);
				system("cls");
			}
		}
		else
		{
			printf("�����곬����Χ������������\n");
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
		printf("���%d��\n", i);
		printf("����������:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' '&&i==1)//���1
			{
				board[x - 1][y - 1] = '*';
				Sleep(500);
				break;
			}
			else if (board[x - 1][y - 1] == ' '&&i == 2)//���2
			{
				board[x - 1][y - 1] = '#';
				Sleep(500);
				break;
			}
			else
			{
				printf("�����걻ռ��,����������\n");
				Sleep(1000);
				system("cls");
			}
		}
		else
		{
			printf("�����곬����Χ������������\n");
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
	printf("������\n");
	Sleep(1000);
	while (1)
	{
		x = rand() % row;//�����������
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			Sleep(500);
			break;
		}
	}
}

int IsFull(char board[ROW][COL], int row, int col)//�ж������Ƿ�����
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j <= col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col)//�ж��������Ƿ���һ��Ӯ
{
	int i = 0;
	for (i = 0; i < row; i++)//����
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	for (i = 0; i < col; i++)//����
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
	}
		if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')//б��
			return board[0][0];
		if (board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[2][0] != ' ')
			return board[0][0];
		if (1 == IsFull(board, ROW, COL))//��������
		{
			return 'Q';
		}
		return 'C';
}

void game1()//�˻����������
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
		printf("���Ӯ\n");
		Sleep(1500);
		system("cls");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
		Sleep(1500);
		system("cls");
	}
	else
	{
		printf("ƽ��\n");
		Sleep(1500);
		system("cls");
	}
}

void game2()//�˻�����������
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
		printf("���Ӯ\n");
		Sleep(1500);
		system("cls");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
		Sleep(1500);
		system("cls");
	}
	else
	{
		printf("ƽ��\n");
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
		printf("���1Ӯ\n");
		Sleep(1500);
		system("cls");
	}
	else if (ret == '#')
	{
		printf("���2Ӯ\n");
		Sleep(1500);
		system("cls");
	}
	else
	{
		printf("ƽ��\n");
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
		printf("��ѡ��:>");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			game1();//�������
			break;
		case 2:
			game2();//��������
			break;
		case 0:
			system("cls");//�˳���Ϸ
			break;
		default:
			printf("�����������������\n");
			Sleep(1000);
			system("cls");
			break;
		}
	} while (ch);
}
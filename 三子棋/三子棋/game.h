#pragma once
#define ROW 3
#define COL 3
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>

void InitBoard(char board[ROW][COL], int row, int col);//��ʼ������
void DisplayBoard(char board[ROW][COL], int row, int col);//��������
void pve();//�˻��Ծ�
void pve_PlayerMove(char board[ROW][COL], int row, int col);//pve�������
void ComputerMove(char board[ROW][COL], int row, int col);//pve��������
char IsWin(char board[ROW][COL], int row, int col);//�ж��������Ƿ���һ��Ӯ
void game1();//pve�������
void game2();//pve��������
void pvp();//��ҶԾ�
void pvp_PlayerMove(char board[ROW][COL], int row, int col, int i);//pvp�������
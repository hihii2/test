#pragma once
#define ROW 15
#define COL 15
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>

void initboard(char board[ROW][COL], int row, int col);
void displayboard(char board[ROW][COL], int row, int col);
void player1move(char board[ROW][COL], int row, int col);
void player2move(char board[ROW][COL], int row, int col);
char iswin(char board[ROW][COL], int row, int col);//@Ϊ�������ʤ����#Ϊ�������ʤ����FΪ����������CΪ����
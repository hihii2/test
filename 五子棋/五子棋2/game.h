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
char iswin(char board[ROW][COL], int row, int col);//@为先手玩家胜利，#为后手玩家胜利，F为棋盘已满，C为继续
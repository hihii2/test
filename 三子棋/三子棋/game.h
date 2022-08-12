#pragma once
#define ROW 3
#define COL 3
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>

void InitBoard(char board[ROW][COL], int row, int col);//初始化棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);//放置棋盘
void pve();//人机对局
void pve_PlayerMove(char board[ROW][COL], int row, int col);//pve玩家落子
void ComputerMove(char board[ROW][COL], int row, int col);//pve电脑落子
char IsWin(char board[ROW][COL], int row, int col);//判断三子棋是否有一方赢
void game1();//pve玩家先手
void game2();//pve电脑先手
void pvp();//玩家对局
void pvp_PlayerMove(char board[ROW][COL], int row, int col, int i);//pvp玩家落子
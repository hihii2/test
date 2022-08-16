#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void menu()
{
	printf("#######################################################################################################################\n");
	printf("#############1 . Add        2 . Sub        3 .Mul        4 .Div        5 . And        6 .OR        7 .Xor##############\n");
	printf("###########################################      0 . exit      ########################################################\n");
	printf("#######################################################################################################################\n");
	printf("#######################################################################################################################\n");
}

int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

int And(int x, int y)
{
	return x & y;
}

int OR(int x, int y)
{
	return x | y;
}

int Xor(int x, int y)
{
	return x ^ y;
}


int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	int sz = 0;
	int (*pfarr[])(int, int) = { 0,Add,Sub,Mul,Div,And,OR,Xor };
	sz = sizeof(pfarr) / sizeof(pfarr[0]);
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		if (input >= 1 && input <= sz)
		{
			printf("请输入两个操作数：");
			scanf("%d%d", &x, &y);
			printf("%d\n", pfarr[input](x, y));
			system("pause");
			system("cls");
		}
		else if (input == 0)
		{
			system("cls");
			printf("退出程序\n");
		}
		else
		{
			printf("输入错误，请重新输入\n");
			system("pause");
			system("cls");
		}
	} while (input);
	return 0;
}
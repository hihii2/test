#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int line = 0;
	int i = 0;
	int j = 0;
	printf("请输入菱形大小：");
	scanf("%d", &line);
	//打印上半部分
	for (i = 0; i < line; i++)
	{
		//打印空格
		for (j =0 ;j <line-i-1; j++)
		{
			printf(" ");
		}
		//打印菱形
		for (j = 0; j <= i; j++)
		{
			if (j < i)
			{
				printf("* ");
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
	//打印下半部分
	for (i = 0; i < line - 1; i++)
	{
	//打印空格
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
	//打印菱形
		for (j = 0; j < line - i - 1; j++)
		{
			if (j < line-i-1)
			{
				printf("* ");
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}
//      *
//     * *
//    * * *
//   * * * *
//  * * * * *
// * * * * * *
//* * * * * * *
// * * * * * *
//  * * * * *
//   * * * *
//    * * *
//     * *
//      *
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int line = 0;
	int i = 0;
	int j = 0;
	printf("���������δ�С��");
	scanf("%d", &line);
	//��ӡ�ϰ벿��
	for (i = 0; i < line; i++)
	{
		//��ӡ�ո�
		for (j =0 ;j <line-i-1; j++)
		{
			printf(" ");
		}
		//��ӡ����
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
	//��ӡ�°벿��
	for (i = 0; i < line - 1; i++)
	{
	//��ӡ�ո�
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
	//��ӡ����
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
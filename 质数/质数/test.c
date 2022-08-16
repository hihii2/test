#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int N(int a)
{
	int i = 1;
	int z = 0;
	while (i <= a)
	{
		if (a % i == 0)
		{
			z++;
		}
		i++;
	}
	return z;
}



int main()
{
	int b = 0;//右区间
	int c = 0;//因数个数
	int x = 1;//数字
	int num = 0;
	scanf("%d", &b);
	while (x <= b)
	{
		c = N(x);
		if (c == 2)
		{
			printf("%d\n", x);
			num++;
		}
		x++;
	}
	printf("以上数字为质数\n");
	printf("该区间内共有%d个质数\n", num);
	return 0;
}
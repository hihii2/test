#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int weishu(int n)//求位数
{
	int i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return i;
}

int mi(int m, int a)//计算m的a次幂
{
	int ret = 1;
	int i = 0;
	for (i = 0; i < a; i++)
	{
		ret = ret * m;
	}
	return ret;
}

int main()
{
	int n = 1;
	int right = 0;
	scanf("%d", &right);
	printf("1-%d中的自幂数有：", right);
	for (n = 1; n <= right; n++)//100000以内的自幂数
	{
		int a = 0;//幂次
		int sum = 0;
		int m = n;
		a = weishu(n);
		while (m)
		{
			sum += mi(m % 10, a);
			m /= 10;
		}
		if (sum == n)
			printf("%d ", n);
	}
	return 0;
}
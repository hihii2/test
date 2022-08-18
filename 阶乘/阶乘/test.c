#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int sum = 0;
	int n = 1;
	int ret = 1;
	int m = 0;
	scanf("%d", &m);
	for (n = 1; n <= m; n++)
	{
		ret = ret * n;
		sum = sum + ret;
	}
	printf("sum = %d\n", sum);
	return 0;
}
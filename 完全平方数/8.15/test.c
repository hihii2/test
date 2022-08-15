#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

int main()
{
	int n = 0;
	int i = 0;
	int k = 0;
	scanf("%d", &k);
	printf("1~k中完全平方数有：");
	for (n = 1; n <= k; n++)
	{
		for (i = 1; i <= sqrt(n); i++)
		{
			if (n == i * i)
			printf("%d ", n);
		}
	}
}
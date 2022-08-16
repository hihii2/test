#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()    //输出一个数字的所有因数及个数
{
	int a = 0;
	int i = 1;
	int num = 0;
	scanf("%d", &a);
	while (i < a)
	{
		if (a%i == 0)
		{
			printf("%d,", i);
			num++;
		}
		i++;
	}
	printf("%d", a);
	printf("为%d的因数\n", a);
	num++;
	printf("%d共有%d个因数", a, num);
	return 0;
}
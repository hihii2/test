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
	int b = 0;//������
	int c = 0;//��������
	int x = 1;//����
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
	printf("��������Ϊ����\n");
	printf("�������ڹ���%d������\n", num);
	return 0;
}
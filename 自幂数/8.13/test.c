#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int weishu(int n)//��λ��
{
	int i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return i;
}

int mi(int m, int a)//����m��a����
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
	printf("1-%d�е��������У�", right);
	for (n = 1; n <= right; n++)//100000���ڵ�������
	{
		int a = 0;//�ݴ�
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
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()    //���һ�����ֵ���������������
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
	printf("Ϊ%d������\n", a);
	num++;
	printf("%d����%d������", a, num);
	return 0;
}
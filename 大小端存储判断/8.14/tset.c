#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a = 1;
	char* pa = (char*) & a;
	if (*pa == 1)
	{
		printf("��ϵͳΪС�˴洢\n");
	}
	else
	{
		printf("��ϵͳΪ��˴洢\n");
	}
	return 0;
}
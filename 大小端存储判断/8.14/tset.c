#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a = 1;
	char* pa = (char*) & a;
	if (*pa == 1)
	{
		printf("该系统为小端存储\n");
	}
	else
	{
		printf("该系统为大端存储\n");
	}
	return 0;
}
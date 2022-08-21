#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int is_move(char* str1, char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)
		return 0;

	strncat(str1, str1, 6);
	char* ret = strstr(str1, str2);
	if (ret == NULL)
		return 0;
	else
		return 1;
}

int main()
{
	char a[30] = { "abcdef" };
	char b[] = { "cdefab" };
	int ret = is_move(a, b);//是旋转返回1，不是旋转返回0
	if (ret==1)
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}
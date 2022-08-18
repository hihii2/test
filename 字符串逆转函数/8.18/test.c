#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

void reverse(char* str)
{
	int len = strlen(str);
	char* left = str;
	char* right = left + len - 1;
	while (left<right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}


int main()
{
	char arr[256] = { 0 };
	gets_s(arr, 256);
	reverse(arr);
	printf("%s", arr);
	return 0;
}
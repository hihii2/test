#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int Findnum(int arr[3][3],int *px,int *py, int k)
{
	int x = 0;
	int y = *py-1;
	while (x < *px && y >= 0)
	{
		if (arr[x][y] < k)
		{
			x++;
		}
		else if (arr[x][y] > k)
		{
			y--;
		}
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
	}
	return 0;
}


int main()
{
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int x = 3;
	int y = 3;
	int k = 0;
	printf("������Ҫ���ҵ����֣�");
	scanf("%d", &k);
	int ret = Findnum(arr, &x, &y, k);//�����ַ����������������������
	if (ret == 1)
	{
		printf("�ҵ���\n");
		printf("�±�Ϊ%d,%d\n", x, y);
	}
	else
	{
		printf("�Ҳ���\n");
	}
	return 0;
}
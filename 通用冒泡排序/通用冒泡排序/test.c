#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

struct stu
{
	char name[20];
	int age;
};

int cmp_int(const void* e1, const void* e2)//整形的比较函数
{
	return *(int*)e1 - *(int*)e2;
}

int cmp_float(const void* e1, const void* e2)//单精度浮点型的比较函数
{
	if (*(float*)e1 < *(float*)e2)
		return -1;
	else if (*(float*)e1 == *(float*)e2)
		return 0;
	else
		return 1;
}

int cmp_stu_by_age(const void* e1, const void* e2)//用年龄比较
{
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}

int cmp_stu_by_name(const void* e1, const void* e2)//用名字比较
{
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}

void Swap(char* p1, char* p2, int width)//交换
{
	int i = 0;
	for (i = 0; i < width; i++)//逐个字节交换
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2++;
	}
}

void bubble_sort(void* base,int sz,int width,int (*cmp)(const void* e1,const void* e2))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)//一趟冒泡排序
	{
		for (j = 0; j < sz - 1 - i; j++)//每一趟比较的个数
		{
			//比较
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}



void test1()
{
	int arr1[] = { 2,4,6,8,0,1,3,5,7,9 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	bubble_sort(arr1, sz, sizeof(arr1[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr1[i]);
	}
}

void test2()
{
	float f[] = { 9.0,8.0,7.0,6.0,5.0,4.0,3.5,2.7,2.6,1.3,0.8 };
	int sz = sizeof(f) / sizeof(f[0]);
	bubble_sort(f, sz, sizeof(f[0]), cmp_float);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%f ", f[i]);
	}
}

void test3()
{
	struct stu s[3] = { {"zhangsan",20},{"lisi",27},{"wangwu",18} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_age);
}

void test4()
{
	struct stu s[3] = { {"zhangsan",20},{"lisi",27},{"wangwu",18} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_name);
}

int main()
{
	//test1();//整形
	//test2();//单精度浮点型
	//test3();//年龄
	//test4();//名字
	return 0;
}
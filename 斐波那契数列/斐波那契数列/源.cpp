#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

//int Fib(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//		return Fib(n - 1) + Fib(n - 2);
//}
//
//int main()
//{
//	int n = 0;
//	int r = 0;
//	scanf("%d", &n);
//	r = Fib(n);
//	printf("%d\n", r);
//	return 0;
//}


long long Fib(long long x)
{
	long long a = 1;
	long long b = 1;
	long long c = 0;
	long long i = 0;
	for (i = 3; i <= x; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

int main()
{
	long long n = 0;
	long long r = 0;
	scanf("%lld", &n);
	r = Fib(n);
	printf("%lld\n", r);
	return 0;
}
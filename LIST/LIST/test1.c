#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int add(int a, int b)
{
	a = a + b;
	return a + b;
}
int main()
{
	int a = 10;
	int b = 20;
	int d = add(a, b);
	printf("%d\n", d);
}
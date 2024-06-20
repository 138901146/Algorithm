#include<stdio.h>

int abs(int x)
{
	return x<0?-x:x;
}

int main(void)
{
	int x, y;

	scanf("%d%d", &x, &y);
	--x;
	--y;

	printf("%d", abs(x/4-y/4)+abs(x%4-y%4));
	return 0;
}
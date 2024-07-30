#include<stdio.h>

int max(int x,int y)
{
	return x<y?y:x;
}

int main(void)
{
	int a, x, b, y, T;

	scanf("%d", &a);
	scanf("%d", &x);
	scanf("%d", &b);
	scanf("%d", &y);
	scanf("%d", &T);

	printf("%d %d", a+21*x*max(0,T-30), b+21*y*max(0,T-45));
	return 0;
}
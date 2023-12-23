#include<stdio.h>

int main(void)
{
	int x1, x2, a, b, c, d, e;

	scanf("%d%d", &x1, &x2);
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

	printf("%d", a/3*x2*x2*x2+b/2*x2*x2+c*x2-a/3*x1*x1*x1-b/2*x1*x1-c*x1-d/2*x2*x2-e*x2+d/2*x1*x1+e*x1);
	return 0;
}
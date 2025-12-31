#include<stdio.h>

int main(void)
{
	int X, Y, Z, U, V, W, total=0;

	scanf("%d%d%d", &X, &Y, &Z);
	scanf("%d%d%d", &U, &V, &W);

	printf("%d", X*U/100+Y*V/50+Z*W/20);
	return 0;
}
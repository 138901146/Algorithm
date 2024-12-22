#include<stdio.h>

int abs(int x)
{
	return x<0?-x:x;
}

int main(void)
{
	int X, L, R;

	scanf("%d%d%d", &X, &L, &R);

	printf("%d", L<=X&&X<=R?X:abs(L-X)<abs(R-X)?L:R);
	return 0;
}
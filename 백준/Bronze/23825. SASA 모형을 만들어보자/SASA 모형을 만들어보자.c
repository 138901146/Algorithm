#include<stdio.h>

int main(void)
{
	int N, M;

	scanf("%d%d", &N, &M);

	N>>=1;
	M>>=1;

	printf("%d", N<M?N:M);
	return 0;
}
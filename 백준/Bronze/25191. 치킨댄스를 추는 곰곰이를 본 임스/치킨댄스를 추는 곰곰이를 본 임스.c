#include<stdio.h>

int main(void)
{
	int N, A, B;

	scanf("%d", &N);
	scanf("%d%d", &A, &B);

	A>>=1;
	A+=B;

	printf("%d", N<A?N:A);
	return 0;
}
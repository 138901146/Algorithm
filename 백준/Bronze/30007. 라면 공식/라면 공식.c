#include<stdio.h>

int main(void)
{
	int N, A, B, X;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d%d%d", &A, &B, &X);
		printf("%d\n", A*(X-1)+B);
	}

	return 0;
}
#include<stdio.h>

int main(void)
{
	int T, N, A, D;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d%d%d", &N, &A, &D);
		printf("%d\n", N*(2*A+(N-1)*D)>>1);
	}

	return 0;
}
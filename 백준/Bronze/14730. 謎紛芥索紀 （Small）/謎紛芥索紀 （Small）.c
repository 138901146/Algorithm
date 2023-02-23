#include<stdio.h>

int main(void)
{
	int N, prime1=0;

	scanf("%d", &N);

	for(int n=0;n<N;n++)
	{
		int C, K;

		scanf("%d %d", &C, &K);

		prime1+=C*K;
	}

	printf("%d\n", prime1);

	return 0;
}
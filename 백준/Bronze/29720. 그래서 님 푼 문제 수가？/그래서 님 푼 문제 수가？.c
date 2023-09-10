#include<stdio.h>

int main(void)
{
	int N, M, K;

	scanf("%d%d%d", &N, &M, &K);

	printf("%d %d", N-M*K<=0?0:N-M*K, (N+M-1)-M*K<=0?0:(N+M-1)-M*K);
	return 0;
}
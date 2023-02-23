#include<stdio.h>

int main(void)
{
	int N, K;

	scanf("%d", &N);

	for(K=0;1+K+K*K<N;K++);

	printf("%d\n", K);
	return 0;
}
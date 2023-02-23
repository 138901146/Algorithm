#include<stdio.h>

int main(void)
{
	int N, M, K;

	scanf("%d %d %d", &N, &M, &K);

	printf("%d %d\n", K/M, K%M);
	return 0;
}
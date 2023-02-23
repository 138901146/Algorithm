#include<stdio.h>

int main(void)
{
	int N, M, K;

	scanf("%d %d %d", &N, &M, &K);
	printf("%d\n", (M>K?K:M)+(N-M>N-K?N-K:N-M));

	return 0;
}
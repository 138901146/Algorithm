#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, K, count=0, *coin=NULL;

	scanf("%d %d", &N, &K);
	coin=(int *)malloc(N*sizeof(int));

	for(int i=N-1;i>=0;i--)
		scanf("%d", &coin[i]);

	for(int i=0;i<N;i++)
	{
		count+=K/coin[i];
		K%=coin[i];
	}

	printf("%d\n", count);

	free(coin);
	return 0;
}
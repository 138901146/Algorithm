#include<stdio.h>

int main(void)
{
	int factorial[11]={1,1,}, N, K;

	scanf("%d %d", &N, &K);

	for(int i=1;i<=N;i++)
		factorial[i]=factorial[i-1]*i;

	printf("%d\n", factorial[N]/(factorial[K]*factorial[N-K]));

	return 0;
}
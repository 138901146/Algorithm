#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	long long int N, *factorial=NULL;

	scanf("%lld", &N);
	factorial=(long long int *)malloc((N+1)*sizeof(long long int));

	factorial[0]=1;
	for(int i=1;i<=N;i++)
		factorial[i]=i*factorial[i-1];

	printf("%lld\n", factorial[N]);

	free(factorial);
	return 0;
}
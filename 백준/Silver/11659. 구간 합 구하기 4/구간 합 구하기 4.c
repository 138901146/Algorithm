#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, M, *sum=0, i, j;

	scanf("%d%d", &N, &M);
	sum=(int *)calloc(N+1,sizeof(int));

	for(int n=1;n<=N;n++)
	{
		scanf("%d", &sum[n]);
		sum[n]+=sum[n-1];
	}

	for(int m=0;m<M;m++)
	{
		scanf("%d%d", &i, &j);
		printf("%d\n", sum[j]-sum[i-1]);
	}

	free(sum);
	return 0;
}
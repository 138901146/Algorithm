#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, M, *prefix_sum=NULL, i, j;

	scanf("%d%d", &N, &M);
	prefix_sum=(int *)malloc((N+1)*sizeof(int));
	prefix_sum[0]=0;

	for(int n=1;n<=N;++n)
	{
		scanf("%d", &prefix_sum[n]);
		prefix_sum[n]+=prefix_sum[n-1];
	}

	while(M--)
	{
		scanf("%d%d", &i, &j);
		printf("%d\n", prefix_sum[j]-prefix_sum[i-1]);
	}

	free(prefix_sum);
	return 0;
}
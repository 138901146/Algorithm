#include<stdio.h>

int N, M, prefix_sum[1000001], i, j;

int main(void)
{
	scanf("%d%d", &N, &M);

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

	return 0;
}
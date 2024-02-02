#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, M, **prefix_sum=NULL, x1, x2, y1, y2;

	scanf("%d%d", &N, &M);
	prefix_sum=(int **)malloc((N+1)*sizeof(int *));

	prefix_sum[0]=(int *)calloc(N+1,sizeof(int));
	for(int r=1;r<=N;++r)
	{
		prefix_sum[r]=(int *)malloc((N+1)*sizeof(int));
		prefix_sum[r][0]=0;

		for(int c=1;c<=N;++c)
		{
			scanf("%d", &prefix_sum[r][c]);
			prefix_sum[r][c]+=prefix_sum[r-1][c]+prefix_sum[r][c-1]-prefix_sum[r-1][c-1];
		}
	}

	while(M--)
	{
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", prefix_sum[x2][y2]-prefix_sum[x1-1][y2]-prefix_sum[x2][y1-1]+prefix_sum[x1-1][y1-1]);
	}

	for(int n=0;n<=N;++n)
		free(prefix_sum[n]);
	free(prefix_sum);
	return 0;
}
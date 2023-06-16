#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, M, **sum=NULL, x1, y1, x2, y2;

	scanf("%d%d", &N, &M);
	sum=(int **)malloc((N+1)*sizeof(int *));

	sum[0]=(int *)calloc(N+1,sizeof(int));
	for(int i=1;i<=N;i++)
	{
		sum[i]=(int *)calloc(N+1,sizeof(int));
		for(int j=1;j<=N;j++)
		{
			scanf("%d", &sum[i][j]);
			sum[i][j]=sum[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		}
	}

	for(int m=0;m<M;m++)
	{
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1]);
	}

	for(int n=0;n<=N;n++)
		free(sum[n]);
	free(sum);
	return 0;
}
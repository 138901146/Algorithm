#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, **profit=NULL, max=-999999999;

	scanf("%d", &N);

	profit=(int **)malloc((N+1)*sizeof(int *));
	profit[0]=(int *)calloc(N+1,sizeof(int));

	for(int i=1;i<=N;++i)
	{
		profit[i]=(int *)calloc(N+1,sizeof(int));
		for(int j=1;j<=N;++j)
		{
			scanf("%d", &profit[i][j]);
			profit[i][j]+=profit[i-1][j]+profit[i][j-1]-profit[i-1][j-1];
		}
	}

	for(int r=1;r<=N;++r)
		for(int c=1;c<=N;++c)
			for(int i=0;r+i<=N&&c+i<=N;++i)
				max=profit[r+i][c+i]-profit[r-1][c+i]-profit[r+i][c-1]+profit[r-1][c-1]<max?max:profit[r+i][c+i]-profit[r-1][c+i]-profit[r+i][c-1]+profit[r-1][c-1];

	printf("%d", max);
	for(int i=0;i<=N;++i)
		free(profit[i]);
	free(profit);
	return 0;
}
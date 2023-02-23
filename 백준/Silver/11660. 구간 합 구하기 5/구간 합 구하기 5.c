#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, M, **arr=NULL, **accumulate=NULL;

	scanf("%d%d", &N, &M);
	arr=(int **)malloc((N+1)*sizeof(int *));
	accumulate=(int **)malloc((N+1)*sizeof(int *));
	for(int n=0;n<=N;n++)
	{
		arr[n]=(int *)calloc(N+1,sizeof(int));
		accumulate[n]=(int *)calloc(N+1,sizeof(int));
	}

	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
		{
			scanf("%d", &arr[i][j]);
			accumulate[i][j]=arr[i][j]+accumulate[i-1][j]+accumulate[i][j-1]-accumulate[i-1][j-1];
		}

	for(int m=0;m<M;m++)
	{
		int x1, x2, y1, y2;

		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", accumulate[x2][y2]-accumulate[x2][y1-1]-accumulate[x1-1][y2]+accumulate[x1-1][y1-1]);
	}

	for(int n=0;n<=N;n++)
	{
		free(arr[n]);
		free(accumulate[n]);
	}
	free(arr);
	free(accumulate);
	return 0;
}
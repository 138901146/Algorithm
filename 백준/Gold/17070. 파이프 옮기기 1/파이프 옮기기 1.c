#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, **grid=NULL, ***method=NULL;

	scanf("%d", &N);
	grid=(int **)malloc(N*sizeof(int *));
	method=(int ***)malloc((N+1)*sizeof(int **));
	for(int i=0;i<=N;i++)
	{
		grid[i]=(int *)malloc((N+1)*sizeof(int));
		method[i]=(int **)malloc((N+1)*sizeof(int *));
		for(int j=0;j<=N;j++)
			method[i][j]=(int *)calloc(3,sizeof(int));
	}

	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			scanf("%d", &grid[i][j]);

	for(int i=2;i<=N;i++)
		if(grid[1][i]!=1)
			method[1][i][0]=1;
		else
			break;
	for(int i=2;i<=N;i++)
		for(int j=1;j<=N;j++)
			if(grid[i][j]==0)
			{
				if(grid[i][j-1]==0)
					method[i][j][0]+=method[i][j-1][0]+method[i][j-1][2];
				if(grid[i-1][j]==0)
					method[i][j][1]+=method[i-1][j][1]+method[i-1][j][2];
				if(grid[i-1][j-1]==0 && grid[i-1][j]==0 && grid[i][j-1]==0)
					method[i][j][2]+=method[i-1][j-1][0]+method[i-1][j-1][1]+method[i-1][j-1][2];
			}

	printf("%d\n", method[N][N][0]+method[N][N][1]+method[N][N][2]);
	return 0;
}
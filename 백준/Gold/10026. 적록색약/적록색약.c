#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	int N, R_G_B=0, RG_B=0;
	char **grid=NULL;
	bool **visited=NULL;

	scanf("%d", &N);
	grid=(char **)malloc(N*sizeof(char *));
	visited=(bool **)malloc(N*sizeof(bool *));
	for(int n=0;n<N;n++)
	{
		grid[n]=(char *)calloc(N+1,sizeof(char));
		visited[n]=(bool *)calloc(N,sizeof(bool));
	}

	for(int n=0;n<N;n++)
		scanf("%s", grid[n]);

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(!visited[i][j])
			{
				R_G_B++;
				int *queue=(int *)malloc(N*N*sizeof(int)), front=0, rear=0;

				queue[rear++]=101*i+j;
				visited[i][j]=true;

				while(front<rear)
				{
					int x=queue[front]/101, y=queue[front]%101;

					if(x>0 && !visited[x-1][y] && grid[x-1][y]==grid[x][y])
					{
						visited[x-1][y]=true;
						queue[rear++]=101*(x-1)+y;
					}
					if(x<N-1 && !visited[x+1][y] && grid[x+1][y]==grid[x][y])
					{
						visited[x+1][y]=true;
						queue[rear++]=101*(x+1)+y;
					}
					if(y>0 && !visited[x][y-1] && grid[x][y-1]==grid[x][y])
					{
						visited[x][y-1]=true;
						queue[rear++]=101*x+y-1;
					}
					if(y<N-1 && !visited[x][y+1] && grid[x][y+1]==grid[x][y])
					{
						visited[x][y+1]=true;
						queue[rear++]=101*x+y+1;
					}

					front++;
				}

				free(queue);
			}

	for(int n=0;n<N;n++)
	{
		free(visited[n]);
		visited[n]=(bool *)calloc(N,sizeof(bool));
	}

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(grid[i][j]=='G')
				grid[i][j]='R';

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(!visited[i][j])
			{
				RG_B++;
				int *queue=(int *)malloc(N*N*sizeof(int)), front=0, rear=0;

				queue[rear++]=101*i+j;
				visited[i][j]=true;

				while(front<rear)
				{
					int x=queue[front]/101, y=queue[front]%101;

					if(x>0 && !visited[x-1][y] && grid[x-1][y]==grid[x][y])
					{
						visited[x-1][y]=true;
						queue[rear++]=101*(x-1)+y;
					}
					if(x<N-1 && !visited[x+1][y] && grid[x+1][y]==grid[x][y])
					{
						visited[x+1][y]=true;
						queue[rear++]=101*(x+1)+y;
					}
					if(y>0 && !visited[x][y-1] && grid[x][y-1]==grid[x][y])
					{
						visited[x][y-1]=true;
						queue[rear++]=101*x+y-1;
					}
					if(y<N-1 && !visited[x][y+1] && grid[x][y+1]==grid[x][y])
					{
						visited[x][y+1]=true;
						queue[rear++]=101*x+y+1;
					}

					front++;
				}

				free(queue);
			}

	printf("%d %d\n", R_G_B, RG_B);
	for(int n=0;n<N;n++)
	{
		free(visited[n]);
		free(grid[n]);
	}
	free(visited);
	free(grid);
	return 0;
}
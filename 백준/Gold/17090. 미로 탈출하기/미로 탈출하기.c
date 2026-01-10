#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

int main(void)
{
	int N, M, *queue=NULL, front=0, rear=0, dr[4]={-1,0,0,1}, dc[4]={0,-1,1,0};
	char **maze=NULL, match[4]={'D','R','L','U'};
	bool **visited=NULL;

	scanf("%d%d", &N, &M);
	maze=(char **)malloc(N*sizeof(char *));
	visited=(bool **)malloc(N*sizeof(bool *));
	queue=(int *)malloc(N*M*sizeof(int));

	for(int r=0;r<N;++r)
	{
		maze[r]=(char *)calloc(M+1,sizeof(char));
		visited[r]=(bool *)calloc(M,sizeof(bool));
		scanf("%s", maze[r]);
	}

	for(int r=0;r<N;++r)
	{
		if(maze[r][0]=='L')
		{
			queue[rear++]=r<<9;
			visited[r][0]=true;
		}
		if(maze[r][M-1]=='R')
		{
			queue[rear++]=r<<9|M-1;
			visited[r][M-1]=true;
		}
	}
	for(int c=0;c<M;++c)
	{
		if(maze[0][c]=='U')
		{
			queue[rear++]=c;
			visited[0][c]=true;
		}
		if(maze[N-1][c]=='D')
		{
			queue[rear++]=(N-1)<<9|c;
			visited[N-1][c]=true;
		}
	}

	while(front<rear)
	{
		int r=queue[front]>>9, c=queue[front]&511;

		for(int i=0;i<4;++i)
		{
			int next_r=r+dr[i], next_c=c+dc[i];

			if(next_r<0||N<=next_r||next_c<0||M<=next_c||visited[next_r][next_c]||maze[next_r][next_c]!=match[i])
				continue;

			visited[next_r][next_c]=true;
			queue[rear++]=next_r<<9|next_c;
		}

		++front;
	}

	printf("%d", rear);
	for(int r=0;r<N;++r)
	{
		free(maze[r]);
		free(visited[r]);
	}
	free(maze);
	free(visited);
	free(queue);
	return 0;
}
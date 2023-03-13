#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	int N, M, K, **map=NULL, *queue=NULL, front=0, rear=0, count=0;
	bool arrived=false, ***visited=NULL;

	scanf("%d%d%d", &N, &M, &K);
	map=(int **)malloc(N*sizeof(int *));
	visited=(bool ***)malloc(N*sizeof(bool **));
	queue=(int *)malloc(50*N*M*sizeof(int));
	for(int n=0;n<N;n++)
	{
		map[n]=(int *)malloc(M*sizeof(int));
		visited[n]=(bool **)malloc(M*sizeof(bool *));
		for(int m=0;m<M;m++)
		{
			scanf("%1d", &map[n][m]);
			visited[n][m]=(bool *)calloc(K+1,sizeof(bool));
		}
	}

	queue[rear++]=0;
	while(front<rear)
	{
		int previous_rear=rear;

		while(front<previous_rear)
		{
			int y=(queue[front]>>11)&((1<<11)-1), x=queue[front]&((1<<11)-1), wall=queue[front]>>22;

			if(y==N-1 && x==M-1)
			{
				arrived=true;
				break;
			}

			if(y>0 && !visited[y-1][x][wall])
			{
				if(map[y-1][x]==0)
				{
					visited[y-1][x][wall]=true;
					queue[rear++]=(wall<<22)|((y-1)<<11)|x;
				}
				else if(wall<K && !visited[y-1][x][wall+1])
				{
					visited[y-1][x][wall+1]=true;
					queue[rear++]=((wall+1)<<22)|((y-1)<<11)|x;
				}
			}
			if(y<N-1 && !visited[y+1][x][wall])
			{
				if(map[y+1][x]==0)
				{
					visited[y+1][x][wall]=true;
					queue[rear++]=(wall<<22)|((y+1)<<11)|x;
				}
				else if(wall<K && !visited[y+1][x][wall+1])
				{
					visited[y+1][x][wall+1]=true;
					queue[rear++]=((wall+1)<<22)|((y+1)<<11)|x;
				}
			}
			if(x>0 && !visited[y][x-1][wall])
			{
				if(map[y][x-1]==0)
				{
					visited[y][x-1][wall]=true;
					queue[rear++]=(wall<<22)|(y<<11)|x-1;
				}
				else if(wall<K && !visited[y][x-1][wall+1])
				{
					visited[y][x-1][wall+1]=true;
					queue[rear++]=((wall+1)<<22)|(y<<11)|x-1;
				}
			}
			if(x<M-1 && !visited[y][x+1][wall])
			{
				if(map[y][x+1]==0)
				{
					visited[y][x+1][wall]=true;
					queue[rear++]=(wall<<22)|(y<<11)|x+1;
				}
				else if(wall<K && !visited[y][x+1][wall+1])
				{
					visited[y][x+1][wall+1]=true;
					queue[rear++]=((wall+1)<<22)|(y<<11)|x+1;
				}
			}

			front++;
		}

		count++;
		if(arrived)
			break;
	}

	printf("%d\n", arrived?count:-1);
	for(int n=0;n<N;n++)
	{
		for(int m=0;m<M;m++)
			free(visited[n][m]);
		free(map[n]);
		free(visited[n]);
	}
	free(map);
	free(visited);
	free(queue);
	return 0;
}
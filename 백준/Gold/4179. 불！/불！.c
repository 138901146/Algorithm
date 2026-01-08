#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

int main(void)
{
	int R, C, *queue_jh=NULL, *queue_fire=NULL, front_jh=0, rear_jh=1, front_fire=0, rear_fire=0, **visited=NULL, count=2, dr[4]={-1,0,0,1}, dc[4]={0,-1,1,0};
	char **maze=NULL;

	scanf("%d%d", &R, &C);

	maze=(char **)malloc(R*sizeof(char *));
	for(int r=0;r<R;++r)
	{
		maze[r]=(char *)calloc(C+1,sizeof(char));
		scanf("%s", maze[r]);
	}

	queue_jh=(int *)malloc(R*C*sizeof(int));
	queue_fire=(int *)malloc(R*C*sizeof(int));
	visited=(int **)malloc(R*sizeof(int *));

	for(int r=0;r<R;++r)
	{
		visited[r]=(int *)calloc(C,sizeof(int));
		for(int c=0;c<C;++c)
			if(maze[r][c]=='J')
			{
				queue_jh[0]=r<<10|c;
				maze[r][c]='.';
				visited[r][c]|=1;
				if(r==R-1||!r||c==C-1||!c)
				{
					printf("1");
					for(r=0;r<R;++r)
					{
						free(maze[r]);
						free(visited[r]);
					}
					free(maze);
					free(visited);
					free(queue_jh);
					free(queue_fire);
					return 0;
				}
			}
			else if(maze[r][c]=='F')
			{
				queue_fire[rear_fire++]=r<<10|c;
				visited[r][c]|=2;
			}
	}

	while(front_jh<rear_jh)
	{
		int previous_rear=rear_fire;

		while(front_fire<previous_rear)
		{
			int r=queue_fire[front_fire]>>10, c=queue_fire[front_fire]&1023;

			for(int i=0;i<4;++i)
			{
				int next_r=r+dr[i], next_c=c+dc[i];

				if(next_r<0||R<=next_r||next_c<0||C<=next_c||maze[next_r][next_c]=='#'||visited[next_r][next_c]&2)
					continue;

				visited[next_r][next_c]|=2;
				queue_fire[rear_fire++]=next_r<<10|next_c;
			}

			++front_fire;
		}

		previous_rear=rear_jh;

		while(front_jh<previous_rear)
		{
			int r=queue_jh[front_jh]>>10, c=queue_jh[front_jh]&1023;

			for(int i=0;i<4;++i)
			{
				int next_r=r+dr[i], next_c=c+dc[i];

				if(next_r<0||R<=next_r||next_c<0||C<=next_c||maze[next_r][next_c]=='#'||visited[next_r][next_c])
					continue;
				else if(next_r==R-1||!next_r||next_c==C-1||!next_c)
				{
					printf("%d", count);
					for(r=0;r<R;++r)
					{
						free(maze[r]);
						free(visited[r]);
					}
					free(maze);
					free(visited);
					free(queue_jh);
					free(queue_fire);
					return 0;
				}

				visited[next_r][next_c]|=1;
				queue_jh[rear_jh++]=next_r<<10|next_c;
			}

			++front_jh;
		}

		++count;
	}

	printf("IMPOSSIBLE");
	for(int r=0;r<R;++r)
	{
		free(maze[r]);
		free(visited[r]);
	}
	free(maze);
	free(visited);
	free(queue_jh);
	free(queue_fire);
	return 0;
}
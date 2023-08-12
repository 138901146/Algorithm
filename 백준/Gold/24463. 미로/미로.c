#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int main(void)
{
	int N, M, start=-1, end_y=-1, end_x, **last=NULL, *queue=NULL, front=0, rear=0, move[4][2]={{-1,0}, {0,-1}, {0,1}, {1,0}}, current;
	char **maze=NULL;
	bool **visited=NULL;

	scanf("%d%d", &N, &M);
	maze=(char **)malloc(N*sizeof(char *));
	last=(int **)malloc(N*sizeof(int *));
	visited=(bool **)malloc(N*sizeof(bool *));
	queue=(int *)malloc(N*M*sizeof(int));

	maze[0]=(char *)calloc(M+1,sizeof(char));
	last[0]=(int *)malloc(M*sizeof(int));
	visited[0]=(bool *)calloc(M,sizeof(bool));
	getchar();
	scanf("%s", maze[0]);
	for(int m=0;m<M;m++)
		if(maze[0][m]=='.')
		{
			if(start==-1)
				start=m;
			else
			{
				end_y=0;
				end_x=m;
				break;
			}
		}

	for(int n=1;n<N-1;n++)
	{
		maze[n]=(char *)calloc(M+1,sizeof(char));
		last[n]=(int *)malloc(M*sizeof(int));
		visited[n]=(bool *)calloc(M,sizeof(bool));

		getchar();
		scanf("%s", maze[n]);

		if(maze[n][0]=='.')
		{
			if(start==-1)
				start=n<<11;
			else
			{
				end_y=n;
				end_x=0;
			}
		}
		if(maze[n][M-1]=='.')
		{
			if(start==-1)
				start=n<<11|(M-1);
			else
			{
				end_y=n;
				end_x=M-1;
			}
		}

		for(int m=1;m<M-1;m++)
			if(maze[n][m]=='.')
				maze[n][m]='@';
	}

	maze[N-1]=(char *)calloc(M+1,sizeof(char));
	last[N-1]=(int *)malloc(M*sizeof(int));
	visited[N-1]=(bool *)calloc(M,sizeof(bool));
	getchar();
	scanf("%s", maze[N-1]);
	if(end_y<0)
		for(int m=0;m<M;m++)
			if(maze[N-1][m]=='.')
			{
				if(start==-1)
					start=(N-1)<<11|m;
				else
				{
					end_y=N-1;
					end_x=m;
					break;
				}
			}

	queue[rear++]=start;
	visited[start>>11][start&2047]=true;

	while(front<rear && !visited[end_y][end_x])
	{
		int y=queue[front]>>11, x=queue[front]&2047;

		for(int i=0;i<4;i++)
		{
			int next_y=y+move[i][0], next_x=x+move[i][1];

			if(next_y>=0 && next_y<N && next_x>=0 && next_x<M && maze[next_y][next_x]!='+' && !visited[next_y][next_x])
			{
				last[next_y][next_x]=queue[front];
				visited[next_y][next_x]=true;
				queue[rear++]=next_y<<11|next_x;
			}
		}

		front++;
	}

	current=end_y<<11|end_x;
	while(current!=start)
	{
		int y=current>>11, x=current&2047;

		maze[y][x]='.';
		current=last[y][x];
	}

	for(int n=0;n<N;n++)
	{
		printf("%s\n", maze[n]);
		free(maze[n]);
		free(last[n]);
		free(visited[n]);
	}
	free(maze);
	free(last);
	free(visited);
	free(queue);
	return 0;
}
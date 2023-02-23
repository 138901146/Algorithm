#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	int N, M, max=0;
	char **map=NULL;

	scanf("%d%d", &N, &M);
	map=(char **)malloc(N*sizeof(char *));
	for(int n=0;n<N;n++)
	{
		map[n]=(char *)calloc(M+1,sizeof(char));
		scanf("%s", map[n]);
	}

	for(int n=0;n<N;n++)
		for(int m=0;m<M;m++)
			if(map[n][m]=='L')
			{
				int *queue=(int *)malloc(N*M*sizeof(int)), front=0, rear=0, count=0;
				bool **visited=(bool **)malloc(N*sizeof(bool *));
				for(int i=0;i<N;i++)
					visited[i]=(bool *)calloc(M,sizeof(bool));

				queue[rear++]=100*n+m;
				visited[n][m]=true;

				while(front<rear)
				{
					int previous_rear=rear;

					while(front<previous_rear)
					{
						int x=queue[front]/100, y=queue[front]%100;

						visited[x][y]=true;

						if(x>0 && map[x-1][y]=='L' && !visited[x-1][y])
						{
							visited[x-1][y]=true;
							queue[rear++]=100*(x-1)+y;
						}
						if(x<N-1 && map[x+1][y]=='L' && !visited[x+1][y])
						{
							visited[x+1][y]=true;
							queue[rear++]=100*(x+1)+y;
						}
						if(y>0 && map[x][y-1]=='L' && !visited[x][y-1])
						{
							visited[x][y-1]=true;
							queue[rear++]=100*x+y-1;
						}
						if(y<M-1 && map[x][y+1]=='L' && !visited[x][y+1])
						{
							visited[x][y+1]=true;
							queue[rear++]=100*x+y+1;
						}

						front++;
					}

					count++;
				}

				if(count-1>max)
					max=count-1;

				for(int i=0;i<N;i++)
					free(visited[i]);
				free(visited);
			}

	printf("%d\n", max);
	for(int n=0;n<N;n++)
		free(map[n]);
	free(map);
	return 0;
}
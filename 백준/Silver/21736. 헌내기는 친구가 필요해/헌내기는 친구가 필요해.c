#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

int main(void)
{
	int N, M, *queue=NULL, front=0, rear=1, dx[4]={1,0,0,-1}, dy[4]={0,-1,1,0}, count=0;
	char **campus=NULL;
	bool **visited=NULL;

	scanf("%d%d", &N, &M);
	campus=(char **)malloc(N*sizeof(char *));
	visited=(bool **)malloc(N*sizeof(bool *));
	queue=(int *)malloc(N*M*sizeof(int));

	for(int n=0;n<N;++n)
	{
		campus[n]=(char *)calloc(M+1,sizeof(char));
		visited[n]=(bool *)calloc(M,sizeof(bool));
		scanf("%s", campus[n]);

		for(int m=0;m<M;++m)
			if(campus[n][m]=='I')
				queue[0]=n<<10|m;
	}

	visited[queue[0]>>10][queue[0]&1023]=true;

	while(front<rear)
	{
		int x=queue[front]>>10, y=queue[front]&1023;

		for(int i=0;i<4;++i)
		{
			int next_x=x+dx[i], next_y=y+dy[i];

			if(next_x<0 || N<=next_x || next_y<0 || M<=next_y || visited[next_x][next_y] || campus[next_x][next_y]=='X')
				continue;

			count+=campus[next_x][next_y]=='P';
			visited[next_x][next_y]=true;
			queue[rear++]=next_x<<10|next_y;
		}

		++front;
	}

	if(count)
		printf("%d", count);
	else
		printf("TT");
	for(int n=0;n<N;++n)
	{
		free(campus[n]);
		free(visited[n]);
	}
	free(campus);
	free(visited);
	free(queue);
	return 0;
}
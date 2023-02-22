#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	int N, M, **miro=NULL, *queue=NULL, front=0, rear=0, count=1;
	bool **visited=NULL;
	scanf("%d%d", &N, &M);
	miro=(int **)malloc(N*sizeof(int  *));
	visited=(bool **)malloc(N*sizeof(bool *));
	queue=(int *)malloc(N*M*sizeof(int));
	for(int n=0;n<N;n++)
	{
		miro[n]=(int *)malloc(M*sizeof(int));
		visited[n]=(bool *)calloc(M,sizeof(bool));

		for(int m=0;m<M;m++)
			scanf("%1d", &miro[n][m]);
	}

	visited[0][0]=true;
	queue[rear++]=0;

	while(front<rear && !visited[N-1][M-1])
	{
		int previous_rear=rear;

		while(front<previous_rear && !visited[N-1][M-1])
		{
			int y=queue[front]%1000, x=queue[front]/1000;

			if(x+1<N &&  miro[x+1][y]==1 &&!visited[x+1][y] )
			{
				visited[x+1][y]=true;
				queue[rear++]=1000*(x+1)+y;
			}
			if(y+1<M && miro[x][y+1]==1 && !visited[x][y+1])
			{
				visited[x][y+1]=true;
				queue[rear++]=1000*x+y+1;
			}
			if(x>0 &&  miro[x-1][y]==1 &&!visited[x-1][y] )
			{
				visited[x-1][y]=true;
				queue[rear++]=1000*(x-1)+y;
			}
			if(y>0 && miro[x][y-1]==1 && !visited[x][y-1])
			{
				visited[x][y-1]=true;
				queue[rear++]=1000*x+y-1;
			}

			front++;
		}
		count++;
	}

	printf("%d\n", count);
	free(queue);
	for(int n=0;n<N;n++)
	{
		free(visited[n]);
		free(miro[n]);
	}
	free(visited);
	free(miro);
	return 0;
}
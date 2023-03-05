#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	int N, M, **map=NULL, **zero=NULL, **order=NULL, *queue=NULL, count=1;
	bool **visited=NULL;

	scanf("%d%d", &N, &M);
	map=(int **)malloc(N*sizeof(int *));
	zero=(int **)malloc(N*sizeof(int *));
	order=(int **)malloc(N*sizeof(int *));
	visited=(bool **)malloc(N*sizeof(bool *));
	queue=(int *)malloc(N*M*sizeof(int));
	for(int n=0;n<N;n++)
	{
		map[n]=(int *)malloc(M*sizeof(int));
		zero[n]=(int *)malloc(M*sizeof(int));
		order[n]=(int *)calloc(M,sizeof(int));
		visited[n]=(bool *)calloc(M,sizeof(bool));
		for(int m=0;m<M;m++)
		{
			scanf("%1d", &map[n][m]);
			zero[n][m]=map[n][m];
		}
	}


	for(int n=0;n<N;n++)
		for(int m=0;m<M;m++)
			if(zero[n][m]==0)
			{
				int front=0, rear=0;
				queue[rear++]=n<<10|m;
				visited[n][m]=true;
				while(front<rear)
				{
					int y=queue[front]>>10, x=queue[front]&(1<<10)-1;

					if(y>0 && zero[y-1][x]==0 && !visited[y-1][x])
					{
						visited[y-1][x]=true;
						queue[rear++]=(y-1)<<10|x;
					}
					if(y<N-1 && zero[y+1][x]==0 && !visited[y+1][x])
					{
						visited[y+1][x]=true;
						queue[rear++]=(y+1)<<10|x;
					}
					if(x>0 && zero[y][x-1]==0 && !visited[y][x-1])
					{
						visited[y][x-1]=true;
						queue[rear++]=y<<10|x-1;
					}
					if(x<M-1 && zero[y][x+1]==0 && !visited[y][x+1])
					{
						visited[y][x+1]=true;
						queue[rear++]=y<<10|x+1;
					}
					front++;
				}
				for(int i=0;i<rear;i++)
				{
					int y=queue[i]>>10, x=queue[i]&(1<<10)-1;

					zero[y][x]=rear;
					order[y][x]=count;
				}
				count++;
			}

	for(int n=0;n<N;n++)
		for(int m=0;m<M;m++)
			if(map[n][m]==1)
			{
				int check[4]={0,0,0,0};

				if(n>0)
					check[0]=order[n-1][m];
				if(n<N-1)
					check[1]=order[n+1][m];
				if(m>0)
					check[2]=order[n][m-1];
				if(m<M-1)
					check[3]=order[n][m+1];

				for(int i=0;i<4;i++)
					for(int j=i+1;j<4;j++)
						if(check[i]==check[j])
							check[j]=0;
				if(check[0]>0)
					map[n][m]+=zero[n-1][m];
				if(check[1]>0)
					map[n][m]+=zero[n+1][m];
				if(check[2]>0)
					map[n][m]+=zero[n][m-1];
				if(check[3]>0)
					map[n][m]+=zero[n][m+1];
			}

	for(int n=0;n<N;n++)
	{
		for(int m=0;m<M;m++)
			printf("%d", map[n][m]%10);
		printf("\n");
		free(map[n]);
		free(zero[n]);
		free(order[n]);
		free(visited[n]);
	}
	free(map);
	free(zero);
	free(order);
	free(visited);
	free(queue);
	return 0;
}
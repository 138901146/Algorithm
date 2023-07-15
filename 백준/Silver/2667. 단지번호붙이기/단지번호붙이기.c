#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int main(void)
{
	int N, **square=NULL, *house=NULL, count=1, *queue=NULL, front=0, rear=0, four[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
	bool **visited=NULL;

	scanf("%d", &N);
	square=(int **)malloc(N*sizeof(int *));
	house=(int *)calloc(N*N,sizeof(int));
	visited=(bool **)malloc(N*sizeof(bool *));
	queue=(int *)malloc(N*N*sizeof(int));
	for(int i=0;i<N;i++)
	{
		square[i]=(int *)malloc(N*sizeof(int));
		visited[i]=(bool *)calloc(N,sizeof(bool));
		for(int j=0;j<N;j++)
			scanf("%1d", &square[i][j]);
	}

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(!visited[i][j] && square[i][j])
			{
				visited[i][j]=true;
				queue[rear++]=i<<5|j;

				while(front<rear)
				{
					int y=queue[front]>>5, x=queue[front]&31;

					house[count]++;
					for(int k=0;k<4;k++)
					{
						y+=four[k][0];
						x+=four[k][1];

						if(y>=0 && y<N && x>=0 && x<N && square[y][x] && !visited[y][x])
						{
							visited[y][x]=true;
							queue[rear++]=y<<5|x;
						}

						y-=four[k][0];
						x-=four[k][1];
					}

					front++;
				}

				count++;
			}

	for(int i=1;i<count;i++)
		for(int j=i+1;j<count;j++)
			if(house[i]>house[j])
			{
				int temp=house[i];
				house[i]=house[j];
				house[j]=temp;
			}

	printf("%d\n", count-1);
	for(int i=1;i<count;i++)
		printf("%d\n", house[i]);

	for(int i=0;i<N;i++)
	{
		free(square[i]);
		free(visited[i]);
	}
	free(queue);
	free(square);
	free(visited);
	free(house);
	return 0;
}
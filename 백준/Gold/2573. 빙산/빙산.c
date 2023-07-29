#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int main(void)
{
	int N, M, **northpole=NULL, year=0, *iceberg=NULL, *queue=NULL, move[4][2]={{-1,0},{0,-1},{0,1},{1,0}}, left=1, iceberg_count=0;

	scanf("%d%d", &N, &M);
	iceberg=(int *)malloc(N*M*sizeof(int));
	queue=(int *)malloc(N*M*sizeof(int));
	northpole=(int **)malloc(N*sizeof(int *));
	for(int n=0;n<N;n++)
	{
		northpole[n]=(int *)malloc(M*sizeof(int));
		for(int m=0;m<M;m++)
		{
			scanf("%d", &northpole[n][m]);
			if(northpole[n][m])
				iceberg[iceberg_count++]=n<<9|m;
		}
	}

	while(left)
	{
		int count=0, front=0, rear=0;
		bool **visited=malloc(N*sizeof(bool *));
		for(int n=0;n<N;n++)
			visited[n]=(bool *)calloc(M,sizeof(bool));

		left=0;
		year++;
		for(int i=0;i<iceberg_count;i++)
		{
			int y=iceberg[i]>>9, x=iceberg[i]&511, adjacent=0;

			if(northpole[y][x]<=0)
				continue;

			for(int j=0;j<4;j++)
			{
				y+=move[j][0];
				x+=move[j][1];

				adjacent+=northpole[y][x]<=0;

				y-=move[j][0];
				x-=move[j][1];
			}

			queue[rear++]=adjacent<<18|y<<9|x;
			left++;
		}

		for(int i=0;i<rear;i++)
			northpole[queue[i]>>9&511][queue[i]&511]-=queue[i]>>18;

		rear=0;
		for(int n=0;n<N && count<2;n++)
			for(int m=0;m<M && count<2;m++)
				if(northpole[n][m]>0 && !visited[n][m])
				{
					queue[rear++]=n<<9|m;
					visited[n][m]=true;

					while(front<rear)
					{
						int y=queue[front]>>9, x=queue[front]&511;

						for(int j=0;j<4;j++)
						{
							y+=move[j][0];
							x+=move[j][1];

							if(y>=0 && y<N && x>=0 && x<M && northpole[y][x]>0 && !visited[y][x])
							{
								visited[y][x]=true;
								queue[rear++]=y<<9|x;
							}

							y-=move[j][0];
							x-=move[j][1];
						}
						front++;
					}

					count++;
				}

		for(int n=0;n<N;n++)
			free(visited[n]);
		free(visited);
		if(count>1)
			break;
	}

	printf("%d\n", left?year:0);
	for(int n=0;n<N;n++)
		free(northpole[n]);
	free(northpole);
	free(iceberg);
	free(queue);
	return 0;
}
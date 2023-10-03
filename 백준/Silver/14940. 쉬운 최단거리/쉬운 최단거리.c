#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int n, m, **map=NULL, *queue=NULL, front=0, rear=1, move[4][2]={{-1,0},{0,-1},{0,1},{1,0}};

	scanf("%d%d", &n, &m);
	map=(int **)malloc(n*sizeof(int *));
	queue=(int *)malloc(n*m*sizeof(int));

	for(int i=0;i<n;++i)
	{
		map[i]=(int *)malloc(m*sizeof(int));
		for(int j=0;j<m;++j)
		{
			scanf("%d", &map[i][j]);
			if(map[i][j]==2)
			{
				queue[0]=i<<10|j;
				map[i][j]=0;
			}
			else if(map[i][j])
				map[i][j]=-1;
			else
				map[i][j]=0;
		}
	}

	while(front<rear)
	{
		int y=queue[front]>>10, x=queue[front]&1023;

		for(int i=0;i<4;++i)
		{
			int temp_y=y+move[i][0], temp_x=x+move[i][1];

			if(temp_y>=0 && temp_y<n && temp_x>=0 && temp_x<m && map[temp_y][temp_x]==-1)
			{
				map[temp_y][temp_x]=map[y][x]+1;
				queue[rear++]=temp_y<<10|temp_x;
			}
		}

		++front;
	}

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
			printf("%d ", map[i][j]);
		printf("\n");
		free(map[i]);
	}
	free(map);
	free(queue);
	return 0;
}
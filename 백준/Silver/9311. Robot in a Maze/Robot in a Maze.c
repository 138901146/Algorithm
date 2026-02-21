#include<stdio.h>

#define INF 1234

int main(void)
{
	int maze, R, C, path[15][15], queue[225], dr[4]={-1,0,0,1}, dc[4]={0,-1,1,0};

	scanf("%d", &maze);

	while(maze--)
	{
		int front=0, rear=1, min=INF;
		char grid[15][16]={0};

		scanf("%d%d", &R, &C);

		for(int r=0;r<R;++r)
			scanf("%s", grid[r]);

		for(int r=0;r<R;++r)
			for(int c=0;c<C;++c)
			{
				path[r][c]=INF;
				if(grid[r][c]=='S')
				{
					queue[0]=r<<4|c;
					path[r][c]=0;
				}
			}

		while(front<rear&&min==INF)
		{
			int r=queue[front]>>4, c=queue[front]&15;

			for(int i=0;i<4;++i)
			{
				int next_r=r+dr[i], next_c=c+dc[i];

				if(next_r<0||R<=next_r||next_c<0||C<=next_c||grid[next_r][next_c]=='X'||path[next_r][next_c]!=INF)
					continue;
				else if(grid[next_r][next_c]=='G')
				{
					min=path[r][c]+1;
					break;
				}

				path[next_r][next_c]=path[r][c]+1;
				queue[rear++]=next_r<<4|next_c;
			}

			++front;
		}

		if(min==INF)
			printf("No Exit\n");
		else
			printf("Shortest Path: %d\n", min);
	}

	return 0;
}
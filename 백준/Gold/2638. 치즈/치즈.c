#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	int Y, X, **board=NULL, *empty_queue=NULL, *cheese_queue=NULL, move[4][2]={{-1,0},{0,-1},{0,1},{1,0}}, cheese=0, empty_rear=0, empty_front, cheese_rear, count=0;
	bool **empty_visited=NULL, **cheese_visited=NULL;

	scanf("%d%d", &Y, &X);
	board=(int **)malloc(Y*sizeof(int *));
	empty_visited=(bool **)malloc(Y*sizeof(bool *));
	cheese_visited=(bool **)malloc(Y*sizeof(bool *));
	empty_queue=(int *)malloc(X*Y*sizeof(int));
	cheese_queue=(int *)malloc(X*Y*sizeof(int));
	for(int y=0;y<Y;y++)
	{
		board[y]=(int *)malloc(X*sizeof(int));
		empty_visited[y]=(bool *)calloc(X,sizeof(bool));
		cheese_visited[y]=(bool *)calloc(X,sizeof(bool));
		for(int x=0;x<X;x++)
		{
			scanf("%d", &board[y][x]);
			cheese+=board[y][x];
		}
	}

	empty_queue[empty_rear++]=0;
	empty_visited[0][0]=true;
	while(cheese>0)
	{
		empty_front=cheese_rear=0;

		while(empty_front<empty_rear)
		{
			int y=empty_queue[empty_front]>>7, x=empty_queue[empty_front]&127;

			for(int i=0;i<4;i++)
				if(y+move[i][0]>=0 && y+move[i][0]<Y && x+move[i][1]>=0 && x+move[i][1]<X)
				{
					if(board[y+move[i][0]][x+move[i][1]]==0 && !empty_visited[y+move[i][0]][x+move[i][1]])
					{
						empty_queue[empty_rear++]=(y+move[i][0])<<7|(x+move[i][1]);
						empty_visited[y+move[i][0]][x+move[i][1]]=true;
					}
					else if(board[y+move[i][0]][x+move[i][1]]==1 && !cheese_visited[y+move[i][0]][x+move[i][1]])
					{
						int near=0;
						for(int j=0;j<4;j++)
							if(y+move[i][0]+move[j][0]>=0 && y+move[i][0]+move[j][0]<Y && x+move[i][1]+move[j][1]>=0 && x+move[i][1]+move[j][1]<X && empty_visited[y+move[i][0]+move[j][0]][x+move[i][1]+move[j][1]])
								near++;
						if(near>1)
						{
							cheese_queue[cheese_rear++]=(y+move[i][0])<<7|(x+move[i][1]);
							cheese_visited[y+move[i][0]][x+move[i][1]]=true;
						}
					}
				}
			empty_front++;
		}

		for(int i=0;i<cheese_rear;i++)
			board[cheese_queue[i]>>7][cheese_queue[i]&127]=0;
		cheese-=cheese_rear;
		count++;
	}

	printf("%d\n", count);
	for(int y=0;y<Y;y++)
	{
		free(board[y]);
		free(empty_visited[y]);
		free(cheese_visited[y]);
	}
	free(board);
	free(empty_visited);
	free(cheese_visited);
	free(empty_queue);
	free(cheese_queue);
	return 0;
}
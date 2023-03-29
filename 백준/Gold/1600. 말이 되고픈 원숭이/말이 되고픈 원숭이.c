#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	int W, H, K, **obstacle=NULL, monkey_move[4][2]={{-1,0},{0,-1},{0,1},{1,0}}, horse_move[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}}, *queue=NULL, front=0, rear=0, count=-1, y, x, move;
	bool ***visited=NULL, arrived=false, check;

	scanf("%d", &K);
	scanf("%d%d", &W, &H);

	obstacle=(int **)malloc(H*sizeof(int *));
	visited=(bool ***)malloc(H*sizeof(bool **));
	queue=(int *)malloc(W*H*(K+1)*sizeof(int));
	for(int h=0;h<H;h++)
	{
		obstacle[h]=(int *)malloc(W*sizeof(int));
		visited[h]=(bool **)malloc(W*sizeof(bool *));
		for(int w=0;w<W;w++)
		{
			scanf("%d", &obstacle[h][w]);
			visited[h][w]=(bool *)calloc(K+1,sizeof(bool));
		}
	}

	visited[0][0][0]=true;
	queue[rear++]=0;

	while(front<rear && !arrived)
	{
		int previous_rear=rear;

		while(front<previous_rear)
		{
			x=queue[front]&255;
			queue[front]>>=8;
			y=queue[front]&255;
			queue[front]>>=8;
			move=queue[front];

			if(y==H-1 && x==W-1)
			{
				arrived=true;
				break;
			}

			for(int i=0;i<4;i++)
				if(y+monkey_move[i][0]>=0 && y+monkey_move[i][0]<H && x+monkey_move[i][1]>=0 && x+monkey_move[i][1]<W && obstacle[y+monkey_move[i][0]][x+monkey_move[i][1]]==0)
				{
					check=false;
					for(int j=0;j<=move;j++)
						if(visited[y+monkey_move[i][0]][x+monkey_move[i][1]][j])
						{
							check=true;
							break;
						}
					if(!check)
					{
						visited[y+monkey_move[i][0]][x+monkey_move[i][1]][move]=true;
						queue[rear++]=(move<<16)|((y+monkey_move[i][0])<<8)|(x+monkey_move[i][1]);
					}
				}
			if(move<K)
			{
				move++;
				for(int i=0;i<8;i++)
					if(y+horse_move[i][0]>=0 && y+horse_move[i][0]<H && x+horse_move[i][1]>=0 && x+horse_move[i][1]<W && obstacle[y+horse_move[i][0]][x+horse_move[i][1]]==0)
					{
						check=false;
						for(int j=0;j<=move;j++)
							if(visited[y+horse_move[i][0]][x+horse_move[i][1]][j])
							{
								check=true;
								break;
							}
						if(!check)
						{
							visited[y+horse_move[i][0]][x+horse_move[i][1]][move]=true;
							queue[rear++]=(move<<16)|((y+horse_move[i][0])<<8)|(x+horse_move[i][1]);
						}
					}
			}

			front++;
		}

		count++;
	}


	printf("%d\n", arrived?count:-1);
	for(int h=0;h<H;h++)
	{
		for(int w=0;w<W;w++)
			free(visited[h][w]);
		free(visited[h]);
		free(obstacle[h]);
	}
	free(visited);
	free(obstacle);
	free(queue);
	return 0;
}
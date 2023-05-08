#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int main(void)
{
	int N, front=0, rear=0, target_x=-1, target_y=-1, target_state=-1, count=0, *queue=NULL, move[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
	char **map=NULL;
	bool ***visited=NULL, found=false;

	scanf("%d", &N);
	queue=(int *)malloc(N*N*2*sizeof(int));
	map=(char **)malloc(N*sizeof(char *));
	visited=(bool ***)malloc(N*sizeof(bool *));

	for(int i=0;i<N;i++)
	{
		visited[i]=(bool **)malloc(N*sizeof(bool *));
		map[i]=(char *)calloc(N+1,sizeof(char));
		scanf("%s", map[i]);
		for(int j=0;j<N;j++)
			visited[i][j]=calloc(2,sizeof(bool));
	}

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			if(map[i][j]=='B')
			{
				if(i+1<N && map[i+1][j]=='B')
				{
					queue[rear++]=(1<<12)|((i+1)<<6)|j;
					visited[i+1][j][1]=true;
					map[i][j]=map[i+1][j]=map[i+2][j]='0';
				}
				else
				{
					queue[rear++]=(i<<6)|(j+1);
					visited[i][j+1][0]=true;
					map[i][j]=map[i][j+1]=map[i][j+2]='0';
				}
				break;
			}
		if(rear>0)
			break;
	}

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			if(map[i][j]=='E')
			{
				if(i+1<N && map[i+1][j]=='E')
				{
					target_y=i+1;
					target_x=j;
					target_state=1;
					map[i][j]=map[i+1][j]=map[i+2][j]='0';
				}
				else
				{
					target_y=i;
					target_x=j+1;
					target_state=0;
					map[i][j]=map[i][j+1]=map[i][j+2]='0';
				}
				break;
			}
		if(target_state!=-1)
			break;
	}
	
	while(front<rear)
	{
		int previousRear=rear;

		while(front<previousRear)
		{
			int x=queue[front]&63;
			queue[front]>>=6;
			int y=queue[front]&63;
			queue[front]>>=6;
			int state=queue[front];
			
			if(x==target_x && y==target_y && state==target_state)
			{
				found=true;
				break;
			}

			if(state==1)
			{
				if(y>1 && map[y-2][x]=='0' && !visited[y-1][x][1])
				{
					visited[y-1][x][1]=true;
					queue[rear++]=1<<12|(y-1)<<6|x;
				}
				if(x<N-1 && map[y-1][x+1]=='0' && map[y][x+1]=='0' && map[y+1][x+1]=='0' && !visited[y][x+1][1])
				{
					visited[y][x+1][1]=true;
					queue[rear++]=1<<12|y<<6|(x+1);
				}
				if(x>0 && map[y-1][x-1]=='0' && map[y][x-1]=='0' && map[y+1][x-1]=='0' && !visited[y][x-1][1])
				{
					visited[y][x-1][1]=true;
					queue[rear++]=1<<12|y<<6|(x-1);
				}
				if(y<N-2 && map[y+2][x]=='0' && !visited[y+1][x][1])
				{
					visited[y+1][x][1]=true;
					queue[rear++]=1<<12|(y+1)<<6|x;
				}
				if(!visited[y][x][0])
				{
					bool movable=true;
					for(int i=0;i<8;i++)
					{
						y+=move[i][0];
						x+=move[i][1];

						if(y<0 || y>=N || x<0 || x>=N || map[y][x]!='0')
						{
							movable=false;
							y-=move[i][0];
							x-=move[i][1];
							break;
						}
						y-=move[i][0];
						x-=move[i][1];
					}

					if(movable)
					{
						visited[y][x][0]=true;
						queue[rear++]=y<<6|x;
					}
				}
			}
			if(state==0)
			{
				if(y>0 && map[y-1][x-1]=='0' && map[y-1][x]=='0' && map[y-1][x+1]=='0' && !visited[y-1][x][0])
				{
					visited[y-1][x][0]=true;
					queue[rear++]=(y-1)<<6|x;
				}
				if(x<N-2 && map[y][x+2]=='0' && !visited[y][x+1][0])
				{
					visited[y][x+1][0]=true;
					queue[rear++]=y<<6|(x+1);
				}
				if(x>1 && map[y][x-2]=='0' && !visited[y][x-1][0])
				{
					visited[y][x-1][0]=true;
					queue[rear++]=y<<6|(x-1);
				}
				if(y<N-1 && map[y+1][x-1]=='0' && map[y+1][x]=='0' && map[y+1][x+1]=='0' && !visited[y+1][x][0])
				{
					visited[y+1][x][0]=true;
					queue[rear++]=(y+1)<<6|x;
				}
				if(!visited[y][x][1])
				{
					bool movable=true;
					for(int i=0;i<8;i++)
					{
						y+=move[i][0];
						x+=move[i][1];

						if(!(y>=0 && y<N && x>=0 && x<N && map[y][x]=='0'))
						{
							movable=false;
							y-=move[i][0];
							x-=move[i][1];
							break;
						}

						y-=move[i][0];
						x-=move[i][1];
					}

					if(movable)
					{
						visited[y][x][1]=true;
						queue[rear++]=1<<12|y<<6|x;
					}
				}
			}

			front++;
		}

		if(found)
			break;
		else
			count++;
	}

	printf("%d\n", found?count:0);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			free(visited[i][j]);
		free(visited[i]);
		free(map[i]);
	}
	free(visited);
	free(map);
	free(queue);
	return 0;
}
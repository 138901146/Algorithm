#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	int R, C, *hedgehog_queue=NULL, *water_queue=NULL, hedgehog_front=0, hedgehog_rear=0, water_front=0, water_rear=0, count=0;
	char **map=NULL;
	bool **visited=NULL, arrived=false;

	scanf("%d%d", &R, &C);
	map=(char **)malloc(R*sizeof(char *));
	hedgehog_queue=(int *)malloc(R*C*sizeof(int));
	water_queue=(int *)malloc(R*C*sizeof(int));
	visited=(bool **)malloc(R*sizeof(bool *));
	for(int r=0;r<R;r++)
	{
		map[r]=(char *)calloc(C+1,sizeof(char));
		visited[r]=(bool *)calloc(C,sizeof(bool));
		getchar();
		for(int c=0;c<C;c++)
		{
			scanf("%c", &map[r][c]);
			if(map[r][c]=='*')
				water_queue[water_rear++]=r<<6|c;
			else if(map[r][c]=='S')
			{
				visited[r][c]=true;
				hedgehog_queue[hedgehog_rear++]=r<<6|c;
				map[r][c]='.';
			}
		}
	}

	int temp_rear=water_rear;
	while(water_front<temp_rear)
	{
		int y=water_queue[water_front]>>6, x=water_queue[water_front]&(1<<6)-1;

		if(y>0 && map[y-1][x]=='.')
		{
			map[y-1][x]='*';
			water_queue[water_rear++]=(y-1)<<6|x;
		}
		if(y<R-1 && map[y+1][x]=='.')
		{
			map[y+1][x]='*';
			water_queue[water_rear++]=(y+1)<<6|x;
		}
		if(x>0 && map[y][x-1]=='.')
		{
			map[y][x-1]='*';
			water_queue[water_rear++]=y<<6|x-1;
		}
		if(x<C-1 && map[y][x+1]=='.')
		{
			map[y][x+1]='*';
			water_queue[water_rear++]=y<<6|x+1;
		}

		water_front++;
	}

	while(hedgehog_front<hedgehog_rear)
	{
		int previous_rear=hedgehog_rear;

		while(hedgehog_front<previous_rear)
		{
			int y=hedgehog_queue[hedgehog_front]>>6, x=hedgehog_queue[hedgehog_front]&(1<<6)-1;

			if(map[y][x]=='D')
			{
				map[y][x]='@';
				arrived=true;
				break;
			}

			if(y>0)
				if(map[y-1][x]=='D')
				{
					arrived=true;
					break;
				}
				else if(!visited[y-1][x] && map[y-1][x]=='.')
				{
					visited[y-1][x]=true;
					hedgehog_queue[hedgehog_rear++]=(y-1)<<6|x;
				}

			if(y<R-1)
				if(map[y+1][x]=='D')
				{
					arrived=true;
					break;
				}
				else if(!visited[y+1][x] && map[y+1][x]=='.')
				{
					visited[y+1][x]=true;
					hedgehog_queue[hedgehog_rear++]=(y+1)<<6|x;
				}

			if(x>0)
				if(map[y][x-1]=='D')
				{
					arrived=true;
					break;
				}
				else if(!visited[y][x-1] && map[y][x-1]=='.')
				{
					visited[y][x-1]=true;
					hedgehog_queue[hedgehog_rear++]=y<<6|x-1;
				}

			if(x<C-1)
				if(map[y][x+1]=='D')
				{
					arrived=true;
					break;
				}
				else if(!visited[y][x+1] && map[y][x+1]=='.')
				{
					visited[y][x+1]=true;
					hedgehog_queue[hedgehog_rear++]=y<<6|x+1;
				}

			hedgehog_front++;
		}

		count++;
		if(arrived)
			break;

		previous_rear=water_rear;
		while(water_front<previous_rear)
		{
			int y=water_queue[water_front]>>6, x=water_queue[water_front]&(1<<6)-1;

			if(y>0 && map[y-1][x]=='.')
			{
				map[y-1][x]='*';
				water_queue[water_rear++]=(y-1)<<6|x;
			}
			if(y<R-1 && map[y+1][x]=='.')
			{
				map[y+1][x]='*';
				water_queue[water_rear++]=(y+1)<<6|x;
			}
			if(x>0 && map[y][x-1]=='.')
			{
				map[y][x-1]='*';
				water_queue[water_rear++]=y<<6|x-1;
			}
			if(x<C-1 && map[y][x+1]=='.')
			{
				map[y][x+1]='*';
				water_queue[water_rear++]=y<<6|x+1;
			}
			water_front++;
		}
	}

	if(arrived)
		printf("%d\n", count);
	else
		printf("KAKTUS\n");
	for(int r=0;r<R;r++)
	{
		free(map[r]);
		free(visited[r]);
	}
	free(map);
	free(visited);
	free(hedgehog_queue);
	free(water_queue);
	return 0;
}
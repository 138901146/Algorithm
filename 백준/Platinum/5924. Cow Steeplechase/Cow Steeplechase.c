#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

typedef struct
{
	int X1, Y1, X2, Y2;
}
line;

int adjacent_list[251][249], adjacent_list_count[251]={0}, occupied[250]={0};
bool visited[250];

bool dfs(int current)
{
	for(int i=0;i<adjacent_list_count[current];++i)
	{
		int next=adjacent_list[current][i];

		if(!visited[next])
		{
			visited[next]=true;

			if(!occupied[next] || dfs(occupied[next]))
			{
				occupied[next]=current;
				return true;
			}
		}
	}

	return false;
}

int main(void)
{
	int N, count=0, horizontal_count=1, vertical_count=0;
	line obstacle, horizontal[251], vertical[250];

	scanf("%d", &N);

	for(int i=0;i<N;++i)
	{
		scanf("%d%d%d%d", &obstacle.X1, &obstacle.Y1, &obstacle.X2, &obstacle.Y2);

		if(obstacle.X1==obstacle.X2)
		{
			if(obstacle.Y2<obstacle.Y1)
			{
				int temp=obstacle.Y1;
				obstacle.Y1=obstacle.Y2;
				obstacle.Y2=temp;
			}

			vertical[vertical_count++]=obstacle;
		}
		else
		{
			if(obstacle.X2<obstacle.X1)
			{
				int temp=obstacle.X1;
				obstacle.X1=obstacle.X2;
				obstacle.X2=temp;
			}

			horizontal[horizontal_count++]=obstacle;
		}
	}

	for(int h=1;h<horizontal_count;++h)
		for(int v=0;v<vertical_count;++v)
			if(horizontal[h].X1<=vertical[v].X1 && vertical[v].X1<=horizontal[h].X2 && vertical[v].Y1<=horizontal[h].Y1 && horizontal[h].Y1<=vertical[v].Y2)
				adjacent_list[h][adjacent_list_count[h]++]=v;

	for(int h=1;h<horizontal_count;++h)
	{
		memset(visited,0,250);
		count+=dfs(h);
	}

	printf("%d", N-count);
	return 0;
}
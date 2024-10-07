#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

int adjacent_list[1001][200], adjacent_list_count[1001]={0}, occupied[200]={0};
bool visited[200];

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
	int n, size, time, count=0;

	scanf("%d", &n);

	for(int i=0;i<n;++i)
	{
		scanf("%d", &size);

		while(size--)
		{
			scanf("%d", &time);
			adjacent_list[time][adjacent_list_count[time]++]=i;
		}
	}

	for(time=1;count<n;++time)
	{
		memset(visited,0,200);
		count+=dfs(time);
	}

	printf("%d", time);
	return 0;
}
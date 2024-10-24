#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

int adjacent_list[1000][999], adjacent_list_count[1000], occupied[1000];
bool visited[1000];

bool dfs(int current)
{
	for(int i=0;i<adjacent_list_count[current];++i)
	{
		int next=adjacent_list[current][i];

		if(!visited[next])
		{
			visited[next]=true;

			if(occupied[next]==-1 || dfs(occupied[next]))
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
	int N, count=0;

	scanf("%d", &N);

	for(int n=0;n<N;++n)
	{
		scanf("%d", &adjacent_list_count[n]);

		for(int i=0;i<adjacent_list_count[n];++i)
			scanf("%d", &adjacent_list[n][i]);

		occupied[n]=-1;
	}

	for(int n=0;n<N;++n)
	{
		memset(visited,0,1000);
		count+=dfs(n);
	}

	printf("%d", N-count);
	return 0;
}
#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

int adjacent_list[201][200], adjacent_list_count[201]={0}, occupied[201]={0};
bool visited[201];

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
	int N, M, K, x, y, count=0;

	scanf("%d%d%d", &N, &M, &K);

	while(K--)
	{
		scanf("%d%d", &x, &y);
		adjacent_list[x][adjacent_list_count[x]++]=y;
	}

	for(int n=1;n<=N;++n)
	{
		memset(visited,0,201);
		count+=dfs(n);
	}

	printf("%d", N+M-count);
	return 0;
}
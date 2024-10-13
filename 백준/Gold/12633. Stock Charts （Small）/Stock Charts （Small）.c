#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

int adjacent_list[17][16], adjacent_list_count[17], occupied[17];
bool visited[17];

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
	int T, N, K, stock[17][25];

	scanf("%d", &T);

	for(int t=1;t<=T;++t)
	{
		int matched=0;

		scanf("%d%d", &N, &K);

		for(int n=1;n<=N;++n)
			for(int k=0;k<K;++k)
				scanf("%d", &stock[n][k]);

		memset(adjacent_list_count,0,(N+1)*sizeof(int));
		memset(occupied,0,(N+1)*sizeof(int));

		for(int n=1;n<=N;++n)
			for(int i=1;i<=N;++i)
				if(n!=i)
				{
					bool connectable=true;

					for(int k=0;k<K&&connectable;++k)
						if(stock[i][k]<=stock[n][k])
							connectable=false;

					if(connectable)
						adjacent_list[n][adjacent_list_count[n]++]=i;
				}

		for(int n=1;n<=N;++n)
		{
			memset(visited,0,N+1);
			matched+=dfs(n);
		}

		printf("Case #%d: %d\n", t, N-matched);
	}

	return 0;
}
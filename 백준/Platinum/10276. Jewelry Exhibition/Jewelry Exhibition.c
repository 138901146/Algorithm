#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

int adjacent_list[100][100], adjacent_list_count[100], occupied[100];
bool visited[100];

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
	int R, N, M, K;
	float x, y;
	bool filled[100][100];

	scanf("%d", &R);

	while(R--)
	{
		int matched=0;

		scanf("%d%d%d", &N, &M, &K);

		memset(occupied,-1,100*sizeof(int));
		memset(adjacent_list_count,0,100*sizeof(int));
		memset(filled,0,10000);

		while(K--)
		{
			scanf("%f%f", &x, &y);
			filled[(int)x][(int)y]=true;
		}

		for(int i=0;i<100;++i)
			for(int j=0;j<100;++j)
				if(filled[i][j])
					adjacent_list[i][adjacent_list_count[i]++]=j;

		for(int i=0;i<100;++i)
		{
			memset(visited,0,100);
			matched+=dfs(i);
		}

		printf("%d\n", matched);
	}

	return 0;
}
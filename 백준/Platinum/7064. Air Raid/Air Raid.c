#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

int adjacent_list[121][119], adjacent_list_count[121], occupied[121];
bool visited[121];

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
	int data_set, no_of_intersection, no_of_street, S, E, matched;

	scanf("%d", &data_set);

	while(data_set--)
	{
		scanf("%d", &no_of_intersection);
		scanf("%d", &no_of_street);

		matched=0;
		memset(adjacent_list_count,0,121*sizeof(int));
		memset(occupied,0,121*sizeof(int));

		for(int k=0;k<no_of_street;++k)
		{
			scanf("%d%d", &S, &E);
			adjacent_list[S][adjacent_list_count[S]++]=E;
		}

		for(int i=1;i<=no_of_intersection;++i)
		{
			memset(visited,0,121);
			matched+=dfs(i);
		}

		printf("%d\n", no_of_intersection-matched);
	}

	return 0;
}
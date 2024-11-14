#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

int adjacent_list[2001][1999], adjacent_list_count[2001], occupied[2000];
bool visited[2000];

int abs(int x)
{
	return x<0?-x:x;
}

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
	int N, x[2000], y[2000], same[2001], different[2000], same_count, different_count, matched;

	while(scanf("%d", &N)!=EOF)
	{
		matched=same_count=different_count=0;
		memset(adjacent_list_count,0,2001*sizeof(int));
		memset(occupied,0,2000*sizeof(int));

		for(int i=0;i<N;++i)
		{
			scanf("%d%d", &x[i], &y[i]);

			if(x[i]&1^y[i]&1)
				different[different_count++]=i;
			else
				same[++same_count]=i;
		}

		for(int i=1;i<=same_count;++i)
			for(int j=0;j<different_count;++j)
				if(x[same[i]]==x[different[j]]&&abs(y[same[i]]-y[different[j]])<2 || y[same[i]]==y[different[j]]&&abs(x[same[i]]-x[different[j]])<2)
					adjacent_list[i][adjacent_list_count[i]++]=j;

		for(int i=1;i<=same_count;++i)
		{
			memset(visited,0,2000);
			matched+=dfs(i);
		}

		printf("%d\n", N-matched);
	}

	return 0;
}
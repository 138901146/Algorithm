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
	int N, C[100], D[100];
	unsigned int low=0, high=1<<30, fit=0;

	scanf("%d", &N);
	for(int i=0;i<N;++i)
		scanf("%d", &C[i]);
	for(int i=0;i<N;++i)
		scanf("%d", &D[i]);

	while(low<=high)
	{
		unsigned int mid=low+high>>1, count=0;
		memset(adjacent_list_count,0,N*sizeof(int));
		memset(occupied,-1,N*sizeof(int));

		for(int c=0;c<N;++c)
			for(int d=0;d<N;++d)
				if(mid<=(C[c]^D[d]))
					adjacent_list[c][adjacent_list_count[c]++]=d;

		for(int i=0;i<N;++i)
		{
			memset(visited,0,N);
			if(!dfs(i))
				break;
			++count;
		}

		if(count==N)
		{
			fit=mid;
			low=mid+1;
		}
		else
			high=mid-1;
	}

	printf("%u", fit);
	return 0;
}
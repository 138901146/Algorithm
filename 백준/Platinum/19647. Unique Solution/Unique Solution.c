#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

int adjacent_list[1001][5], adjacent_list_count[1001]={0}, primary[1001]={0}, secondary[1001]={0};
bool visited[1001];

bool dfs1(int current)
{
	for(int i=0;i<adjacent_list_count[current];++i)
	{
		int next=adjacent_list[current][i];

		if(!visited[next])
		{
			visited[next]=true;

			if(!primary[next] || dfs1(primary[next]))
			{
				primary[next]=current;
				return true;
			}
		}
	}

	return false;
}

bool dfs2(int current)
{
	for(int i=adjacent_list_count[current]-1;0<=i;--i)
	{
		int next=adjacent_list[current][i];

		if(!visited[next])
		{
			visited[next]=true;

			if(!secondary[next] || dfs2(secondary[next]))
			{
				secondary[next]=current;
				return true;
			}
		}
	}

	return false;
}

int main(void)
{
	int N;

	scanf("%d", &N);

	for(int n=1;n<=N;++n)
	{
		scanf("%d", &adjacent_list_count[n]);

		for(int i=0;i<adjacent_list_count[n];++i)
			scanf("%d", &adjacent_list[n][i]);
	}

	for(int n=1;n<=N;++n)
	{
		memset(visited,0,1001);
		if(!dfs1(n))
		{
			printf("-1");
			return 0;
		}
	}

	for(int n=1;n<=N;++n)
	{
		memset(visited,0,1001);
		dfs2(n);
	}

	for(int n=1;n<=N;++n)
		if(primary[n]!=secondary[n])
		{
			printf("-1");
			return 0;
		}

	for(int n=1;n<=N;++n)
		primary[secondary[n]]=n;
	printf("1\n");
	for(int n=1;n<=N;++n)
		printf("%d ", primary[n]);
	return 0;
}
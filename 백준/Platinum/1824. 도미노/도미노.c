#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

int adjacent_list[10001][4]={0}, occupied[10001]={0};
bool visited[10001];

bool dfs(int current)
{
	for(int i=0;i<4;++i)
	{
		int next=adjacent_list[current][i];

		if(next && !visited[next])
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
	int N, M, L, x, y, dn[4]={-1,0,1,0}, dm[4]={0,1,0,-1};

	scanf("%d%d", &N, &M);
	scanf("%d", &L);

	for(int n=0;n<N;++n)
		for(int m=1;m<=M;++m)
		{
			if((n&1)==(m&1))
				continue;

			int id=n*M+m;

			for(int i=0;i<4;++i)
			{
				int next_n=n+dn[i], next_m=m+dm[i];

				if(next_n<0 || N<=next_n || next_m<=0 || M<next_m)
					continue;

				adjacent_list[id][i]=next_n*M+next_m;
			}
		}

	while(L--)
	{
		scanf("%d%d", &x, &y);

		if((((x-1)/M)&1)==((x%M?x%M:M)&1))
		{
			int temp=x;
			x=y;
			y=temp;
		}

		if(x+1==y)
			adjacent_list[x][1]=0;
		else if(x-1==y)
			adjacent_list[x][3]=0;
		else if(x<y)
			adjacent_list[x][2]=0;
		else
			adjacent_list[x][0]=0;
	}

	for(int i=N*M;i;--i)
	{
		memset(visited,0,10001);
		dfs(i);
	}

	for(int n=0;n<N;++n)
		for(int m=1;m<=M;++m)
			if((n&1)==(m&1))
				printf("%d %d\n", n*M+m, occupied[n*M+m]);
	return 0;
}
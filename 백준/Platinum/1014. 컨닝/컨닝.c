#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

int adjacent_list[51][6], adjacent_list_count[51], occupied[51];
bool visited[51];

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
	int C, dr[6]={-1,-1,0,0,1,1}, dc[6]={-1,1,-1,1,-1,1};

	scanf("%d", &C);

	while(C--)
	{
		int N, M, id[10][10], odd_count=1, even_count=1, odd_matched=0, even_matched=0;
		char seat[10][11]={0};

		scanf("%d%d", &N, &M);

		for(int n=0;n<N;++n)
			scanf("%s", seat[n]);

		for(int m=0;m<M;++m)
			for(int n=0;n<N;++n)
				if(seat[n][m]=='.')
					id[n][m]=m&1?odd_count++:even_count++;

		memset(adjacent_list_count,0,51*sizeof(int));
		memset(occupied,0,51*sizeof(int));

		for(int n=0;n<N;++n)
			for(int m=0;m<M;m+=2)
				if(seat[n][m]=='.')
					for(int i=0;i<6;++i)
						if(0<=n+dr[i] && n+dr[i]<N && 0<=m+dc[i] && m+dc[i]<M && seat[n+dr[i]][m+dc[i]]=='.')
							adjacent_list[id[n][m]][adjacent_list_count[id[n][m]]++]=id[n+dr[i]][m+dc[i]];

		for(int i=1;i<odd_count;++i)
		{
			memset(visited,0,51);
			odd_matched+=dfs(i);
		}

		memset(adjacent_list_count,0,51*sizeof(int));
		memset(occupied,0,51*sizeof(int));

		for(int n=0;n<N;++n)
			for(int m=1;m<M;m+=2)
				if(seat[n][m]=='.')
					for(int i=0;i<6;++i)
						if(0<=n+dr[i] && n+dr[i]<N && 0<=m+dc[i] && m+dc[i]<M && seat[n+dr[i]][m+dc[i]]=='.')
							adjacent_list[id[n][m]][adjacent_list_count[id[n][m]]++]=id[n+dr[i]][m+dc[i]];

		for(int i=1;i<even_count;++i)
		{
			memset(visited,0,51);
			even_matched+=dfs(i);
		}

		printf("%d\n", odd_count+even_count-(odd_matched<even_matched?even_matched:odd_matched)-2);
	}

	return 0;
}
#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

int adjacent_list[10001][8], adjacent_list_count[10001]={0}, occupied[10000]={0};
bool visited[10000];

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
	int N, M, meat=1, greenonion=0, id[100][100], dr[8]={-1,-1,-1,0,0,1,1,1}, dc[8]={-1,0,1,-1,1,-1,0,1}, matched=0;
	char grid[100][101]={0};

	scanf("%d%d", &N, &M);

	for(int i=0;i<N;++i)
		scanf("%s", grid[i]);

	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			if(grid[i][j]=='G')
				id[i][j]=greenonion++;
			else if(grid[i][j]=='S')
				id[i][j]=meat++;

	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			if(grid[i][j]=='M')
				for(int k=0;k<8;++k)
				{
					int r[3], c[3];
					bool calculatable=true;

					for(int l=0;l<3;++l)
					{
						r[l]=i+dr[k]*l;
						c[l]=j+dc[k]*l;

						if(r[l]<0 || N<=r[l] || c[l]<0 || M<=c[l])
						{
							calculatable=false;
							break;
						}
					}

					if(!calculatable)
						continue;

					if(grid[r[1]][c[1]]=='S' && grid[r[2]][c[2]]=='G')
						adjacent_list[id[r[1]][c[1]]][adjacent_list_count[id[r[1]][c[1]]]++]=id[r[2]][c[2]];
					else if(grid[r[1]][c[1]]=='G' && grid[r[2]][c[2]]=='S')
						adjacent_list[id[r[2]][c[2]]][adjacent_list_count[id[r[2]][c[2]]]++]=id[r[1]][c[1]];
				}

	for(int i=1;i<meat;++i)
	{
		memset(visited,0,10000);
		matched+=dfs(i);
	}

	printf("%d", matched);
	return 0;
}
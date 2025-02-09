#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include<memory.h>

int **adjacent_list=NULL, *adjacent_list_count=NULL, *occupied=NULL;
bool *visited=NULL;

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
	int N, M, grid[100][100], row[100][100], col[100][100], row_size=0, col_size=0, matched=0;

	scanf("%d%d", &N, &M);

	for(int n=0;n<N;++n)
	{
		scanf("%d", &grid[n][0]);

		if(grid[n][0]!=2)
			row[n][0]=row_size++;

		for(int m=1;m<M;++m)
		{
			scanf("%d", &grid[n][m]);

			if(grid[n][m]!=2)
				row[n][m]=grid[n][m-1]==2?row_size++:row[n][m-1];
		}
	}
	adjacent_list=(int **)malloc(row_size*sizeof(int *));
	adjacent_list_count=(int *)calloc(row_size,sizeof(int));

	for(int m=0;m<M;++m)
	{
		if(grid[0][m]!=2)
		{
			col[0][m]=col_size++;

			if(!grid[0][m])
				++adjacent_list_count[row[0][m]];
		}

		for(int n=1;n<N;++n)
			if(grid[n][m]!=2)
			{
				col[n][m]=grid[n-1][m]==2?col_size++:col[n-1][m];

				if(!grid[n][m])
					++adjacent_list_count[row[n][m]];
			}
	}

	occupied=(int *)malloc(col_size*sizeof(int));
	visited=(bool *)malloc(col_size*sizeof(bool));

	for(int i=0;i<row_size;++i)
	{
		adjacent_list[i]=(int *)malloc(adjacent_list_count[i]*sizeof(int));
		adjacent_list_count[i]=0;
	}

	for(int n=0;n<N;++n)
		for(int m=0;m<M;++m)
			if(!grid[n][m])
				adjacent_list[row[n][m]][adjacent_list_count[row[n][m]]++]=col[n][m];

	memset(occupied,-1,col_size*sizeof(int));
	for(int i=0;i<row_size;++i)
	{
		memset(visited,0,col_size);
		matched+=dfs(i);
	}

	printf("%d", matched);
	while(row_size--)
		free(adjacent_list[row_size]);
	free(adjacent_list);
	free(adjacent_list_count);
	free(occupied);
	free(visited);
	return 0;
}
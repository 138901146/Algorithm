#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

bool *visited=NULL;
int **row_list=NULL, *row_list_size=NULL, *occupied=NULL;

bool dfs(int current)
{
	for(int i=0;i<row_list_size[current];++i)
	{
		int col=row_list[current][i];

		if(!visited[col])
		{
			visited[col]=true;

			if(!occupied[col] || dfs(occupied[col]))
			{
				occupied[col]=current;
				return true;
			}
		}
	}

	return false;
}

int main(void)
{
	int N, row_count=1, col_count=0, **row=NULL, **col=NULL, max=0;
	bool **chess=NULL;
	char c;

	scanf("%d", &N);
	chess=(bool **)malloc(N*sizeof(bool *));
	row=(int **)malloc(N*sizeof(int *));
	col=(int **)malloc(N*sizeof(int *));

	for(int i=0;i<N;++i)
	{
		getchar();
		chess[i]=(bool *)malloc(N*sizeof(bool));
		row[i]=(int *)malloc(N*sizeof(int));
		col[i]=(int *)malloc(N*sizeof(int));

		for(int j=0;j<N;++j)
		{
			scanf("%c", &c);
			chess[i][j]=c=='.';

			if(chess[i][j])
			{
				row[i][j]=(i==0||!chess[i-1][j])?row_count++:row[i-1][j];
				col[i][j]=(j==0||!chess[i][j-1])?col_count++:col[i][j-1];
			}
			else
				row[i][j]=col[i][j]=-1;
		}
	}

	row_list=(int **)malloc(row_count*sizeof(int *));
	row_list_size=(int *)calloc(row_count,sizeof(int));

	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
			if(row[i][j]>0)
				++row_list_size[row[i][j]];
		free(chess[i]);
	}
	free(chess);

	for(int i=1;i<row_count;++i)
	{
		row_list[i]=(int *)malloc(row_list_size[i]*sizeof(int));
		row_list_size[i]=0;
	}

	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
			if(row[i][j]>0)
				row_list[row[i][j]][row_list_size[row[i][j]]++]=col[i][j];
		free(row[i]);
		free(col[i]);
	}
	free(row);
	free(col);

	visited=(bool *)malloc(col_count*sizeof(bool));
	occupied=(int *)calloc(col_count,sizeof(int));

	for(int i=1;i<row_count;++i)
	{
		for(int j=0;j<col_count;++j)
			visited[j]=false;

		dfs(i);
	}

	for(int i=0;i<col_count;++i)
		max+=occupied[i]>0;

	printf("%d", max);
	for(int i=1;i<row_count;++i)
		free(row_list[i]);
	free(row_list);
	free(row_list_size);
	free(occupied);
	free(visited);
	return 0;
}
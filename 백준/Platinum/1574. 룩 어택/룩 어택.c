#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

bool *visited=NULL;
int **row=NULL, *row_size=NULL, *occupied=NULL;

bool dfs(int current)
{
	for(int i=0;i<row_size[current];++i)
	{
		int col=row[current][i];

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
	int R, C, N, max=0;
	bool **empty=NULL;

	scanf("%d%d%d", &R, &C, &N);
	empty=(bool **)malloc((R+1)*sizeof(bool *));
	row=(int **)malloc((R+1)*sizeof(int *));
	row_size=(int *)calloc(R+1,sizeof(int));

	for(int r=1;r<=R;++r)
		empty[r]=(bool *)calloc(C+1,sizeof(bool));

	while(N--)
	{
		int r, c;

		scanf("%d%d", &r, &c);
		empty[r][c]=true;
	}


	for(int r=1;r<=R;++r)
	{
		for(int c=1;c<=C;++c)
			if(!empty[r][c])
				++row_size[r];

		row[r]=(int *)malloc(row_size[r]*sizeof(int));
		row_size[r]=0;

		for(int c=1;c<=C;++c)
			if(!empty[r][c])
				row[r][row_size[r]++]=c;

		free(empty[r]);
	}
	free(empty);

	visited=(bool *)malloc((C+1)*sizeof(bool));
	occupied=(int *)calloc(C+1,sizeof(int));

	for(int r=1;r<=R;++r)
	{
		for(int c=1;c<=C;++c)
			visited[c]=false;

		dfs(r);
	}

	for(int c=1;c<=C;++c)
		max+=occupied[c]>0;

	printf("%d", max);
	for(int r=1;r<=R;++r)
		free(row[r]);
	free(row);
	free(row_size);
	free(occupied);
	free(visited);
	return 0;
}